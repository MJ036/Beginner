#include "func.h"

void copyFile(const char* src, const char* dst);
void copyDir(const char* src, const char* dst);
 
int main(int argc, char* argv[]) {
    // ./copyDir src dst
    ARGS_CHECK(argc, 3);
    copyFile(argv[1], argv[2]);
    
    return 0;
}
 
void copyFile(const char* src, const char* dst) {
	// 复制文件  
    int fdr = open(src,O_RDONLY);
    ERROR_CHECK(fdr,-1,"fdr");
    int fdw = open(dst,O_RDWR | O_CREAT | O_TRUNC,0644);
    ERROR_CHECK(fdw,-1,"fdw");

    struct stat src_stat;
    fstat(fdr,&src_stat);
    size_t src_size = src_stat.st_size;

    void *src_map = mmap(NULL,src_size,PROT_READ,MAP_SHARED,fdr,0);
    ERROR_CHECK(src_map,MAP_FAILED,"srcMap");

    int ret = ftruncate(fdw,src_size);
    ERROR_CHECK(ret,-1,"ftruncate");


    void *dst_map = mmap(NULL,src_size,PROT_WRITE,MAP_SHARED,fdw,0);
    ERROR_CHECK(dst_map,MAP_FAILED,"dstMap");

    memcpy(dst_map,src_map,src_size);

    munmap(src_map,src_size);
    munmap(dst_map,src_size);

    close(fdw);
    close(fdr);

}

