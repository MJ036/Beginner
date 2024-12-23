#include "func.h"
 
void deleteDir(const char* path);
 
int main(int argc, char *argv[])
{
    // ./deleteDir dir
    ARGS_CHECK(argc, 2);
 
    deleteDir(argv[1]);
    return 0;
}
 
void deleteDir(const char* path) {
	// 打开目录
    DIR* pdir = opendir(path);

    // 遍历目录流，依次删除每一个目录项
    struct dirent* pdirent;
    while ((pdirent = readdir(pdir)) != NULL) {
        // 忽略.和..
        const char* name = pdirent->d_name;
        if(strcmp(name,".") == 0 || strcmp(name,"..") == 0){
            continue;
        }
        // 如果该目录项是目录，则调用deleteDir递归删除
        char subpath[1024];
        sprintf(subpath,"%s/%s",path,name);
        if(pdirent->d_type == DT_DIR){
            deleteDir(subpath);
        }else if(pdirent->d_type == DT_REG){
        // 如果该目录项是文件，则调用unlink删除文件
            unlink(subpath);
        }

    }
    
	// 关闭目录流    
    closedir(pdir);
    // 目录为空了，可以删除该目录了
    rmdir(path);

}

