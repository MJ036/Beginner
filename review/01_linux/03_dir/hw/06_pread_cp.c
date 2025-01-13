#include "func.h"

void copyFile(const char* src, const char* dst){
    int fdr = open(src,O_RDONLY);
    ERROR_CHECK(fdr,-1,"rdr");
    int fdw = open(dst,O_RDWR | O_CREAT | O_TRUNC,0644);
    ERROR_CHECK(fdw,-1,"fdw");

    
    struct stat src_stat;
    fstat(fdr,&src_stat);
    size_t src_size = src_stat.st_size;
    char buf[4096] = {0};

    size_t block_size = 4096;

    size_t offset = 0;
    while(offset < src_size){
        size_t bytes_to_read = block_size;
        if(bytes_to_read + offset > src_size){
            bytes_to_read = src_size - offset;
        }
        ssize_t bytes_read = pread(fdr,buf,bytes_to_read,offset);
        //检查块是否全0
        int is_zero_block = 1;
        for(size_t i = 0; i < bytes_read; ++i){
            if(buf[i] != 0){
                is_zero_block = 0;
                break;
            }
        }
        if(is_zero_block){
            lseek(fdw,bytes_read,SEEK_CUR);
        }else{
            write(fdw,buf,bytes_read);
        }
        offset += bytes_read;
    }
    close(fdr);
    close(fdw);
}

int main(int argc,char* argv[])
{
    // ./06_pread_cp src dst
    ARGS_CHECK(argc,3);
    copyFile(argv[1],argv[2]);


    return 0;
}

