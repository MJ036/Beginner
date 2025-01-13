#include "mai.h"


int directories = 0, files = 0;

void dfs_print(const char* path,int width){
    DIR* stream = opendir(path);
    ERROR_CHECK(stream,NULL,"opendir");

    struct dirent* p;
    while((p = readdir(stream)) != NULL){
        const char* name = p->d_name;
        if(strcmp(name,".") == 0 || strcmp(name,"..") == 0){
            continue;
        }
        for(int i = 0; i < width;i++){
            putchar(' ');
        }
        puts(name);

        if(p->d_type == DT_DIR){
            directories++;
            char subpath[PATH_MAX];
            sprintf(subpath,"%s/%s",path,name);
            dfs_print(subpath,width + 4);
        }else if(p->d_type == DT_REG){
            files++;
        }
    }

    closedir(stream);
}


int main(int argc,char* argv[])
{
    //./tree dir
    ARGS_CHECK(argc,2);

    puts(argv[1]);

    dfs_print(argv[1],4);
    
    printf("\n%d directories, %d files\n",directories,files);

    return 0;
}

