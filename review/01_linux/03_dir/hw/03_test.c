#include "func.h"

void copyFile(const char* src, const char* dst);
void copyDir(const char* src, const char* dst);
 
int main(int argc, char* argv[]) {
    // ./copyDir src dst
    ARGS_CHECK(argc, 3);
    copyDir(argv[1], argv[2]);
    
    return 0;
}
 
void copyFile(const char* src, const char* dst) {
	// 复制文件  
    FILE* fpr = fopen(src,"rb");
    FILE* fpw = fopen(dst,"wb");
    char buf[4096];
    int bytes;
    while(1){
        bytes = fread(buf,1,4096,fpr);
        if(bytes == 0) break;
        fwrite(buf,1,bytes,fpw);
    }
    fclose(fpr);
    fclose(fpw);
}

void copyFile_rw(const char* src,const char* dst){
    int fdr = open(src,O_RDONLY);
    int fdw = open(dst,O_RDWR);

    int bytes;
    char buf[4096];
    while((bytes = read(fdr,buf,sizeof(bytes))) > 0){
        write(fdw,buf,bytes);
    }

    close(fdr);
    close(fdw);
}
 
void copyDir(const char* src, const char* dst) {
    // 创建dst目录
    mkdir(dst,0777);
    // 打开src目录
    DIR* pdir = opendir(src);
    // 遍历目录流
        struct dirent* pdirent;
    while((pdirent = readdir(pdir)) != NULL) {
        // 忽略.和..
        const char* name = pdirent->d_name;
        if(strcmp(name,".") == 0 || strcmp(name,"..") == 0){
            continue;
        }

        char subsrc[1024];
        char subdst[1024];
        sprintf(subsrc,"%s/%s",src,name);
        sprintf(subdst,"%s/%s",dst,name);
        // 如果该目录项是目录，则调用copyDir递归复制
        if(pdirent->d_type == DT_DIR){
            copyDir(subsrc,subdst);
        }else if(pdirent->d_type == DT_REG){
        // 如果该目录项是文件，则调用copyFile复制文件
            copyFile(subsrc,subdst);

        }

    }

    // 关闭目录流
    closedir(pdir);
}
