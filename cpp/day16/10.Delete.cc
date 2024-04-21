#include <iostream>
#include <string>
#include <memory>
using namespace std;

void test0(){
    string msg = "hello,world\n";
    FILE *fp = fopen(".txt","a+");
    fwrite(msg.c_str(),1,msg.size(),fp);
    fclose(fp);
}

struct FILEClose{
    void operator()(FILE *fp){
        if(fp){
            fclose(fp);
        }

    }
};

int main()
{

    return 0;
}

