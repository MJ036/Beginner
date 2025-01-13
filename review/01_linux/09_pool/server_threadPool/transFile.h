
typedef struct train_s{
    int dataLength;
    char buf[1000];
}train_t;

// operation of transFile
int transFile(int netFd);
int transFile_mmap_times(int netFd);
int transFile_mmap(int netfd);
