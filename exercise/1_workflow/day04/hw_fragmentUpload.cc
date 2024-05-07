#include <mai.h>
#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>
#include <workflow/HttpUtil.h>
#include <wfrest/json.hpp>

using Json = nlohmann::json;
using namespace std;
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    printf("finish 1 work!\n");
    waitGroup.done();
}

void process(WFHttpTask *serverTask){
// http://192.168.118.128:1234/file/mupload/init
// http://192.168.118.128:1234/file/mupload/uppart?uploadID=liao1122&chkidx=2
// http://192.168.118.128:1234/file/mupload/complete?uploadID=liao1122
    auto req = serverTask->get_req();
    auto resp = serverTask->get_resp();
    std::string uri = req->get_request_uri();
    std::string path = uri.substr(0,uri.find("?"));
    std::string query = uri.substr(uri.find("?")+1);
    std::string method = req->get_method();
    if(path == "/file/mupload/inti" && method == "POST"){
        //resolution request
        const void *body;
        size_t size;
        req->get_parsed_body(&body,&size);
        // parse from string to json
        Json fileInfo = Json::parse(static_cast<const char *>(body));
        std::string filename = fileInfo["filename"];
        int filesize = fileInfo["filesize"];
        std::string filehash = fileInfo["filehash"];
        fprintf(stderr,"%s %s %d\n", filename.c_str(),filehash.c_str(),filesize);
        //initialize the block
        std::string uploadID = "mai";
        time_t now = time(NULL);
        struct tm *ptm = localtime(&now);
        char timeStamp[30] = {0};
        sprintf(timeStamp,"%02d%02d%02d",ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
        uploadID = uploadID + timeStamp;

        int chunkcount;
        int chunksize = 1024*1024;
        if(filesize % chunksize != 0 ){
            chunkcount = filesize/chunksize + 1;
        }
        else{
            chunkcount = filesize/chunksize;
        }
    // initialize redis
    std::vector<std::vector<std::string>> argsVec = {
            {uploadID,"chunkcount",std::to_string(chunkcount)},
            {uploadID,"filehash",filehash},
            {uploadID,"filesize",std::to_string(filesize)}
        };
    for(int i = 0; i < 3; ++i){
        auto redisTask = WFTaskFactory::create_redis_task("redis://localhost",0,nullptr);
        redisTask->get_req()->set_request("HSET",argsVec[i]);
        redisTask->start();
    }
    //respose to client
    Json uppartInfo;
    uppartInfo["status"] = "OK";
    uppartInfo["uploadID"] = uploadID;
    uppartInfo["chunkcount"] = chunkcount;
    uppartInfo["filesize"] = filesize;
    uppartInfo["chunksize"] = chunksize;
    uppartInfo["filehask"] = filehash;
    resp->append_output_body(uppartInfo.dump());
    }
    else if(path == "/file/mupload/uppart" && method == "POST"){
        fprintf(stderr,"uppart\n");   
    }



    else if(path == "file/mupload/complete" && method == "POST"){

    }
     
}


int main()
{
    signal(SIGINT,sighandler);
    WFHttpServer server(process);
    if(server.start(1234) == 0){
        waitGroup.wait();
        server.stop();
    }
    else{
        perror("server start error!\n");
        exit(-1);
    }

    return 0;
}

