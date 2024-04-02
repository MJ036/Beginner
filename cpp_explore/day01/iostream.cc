#include <sstream>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <string.h>

using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::istringstream;
using std::ostringstream;

//文件输出流
void test0(){
    ofstream ofs("rec.tet",std::ios::app);

    string line("Hello,world! \n");
    ofs << line;
    
    const char *buff = "wangdao cpp!\n";
    ofs.write(buff,strlen(buff));

    string str("summer coming\n");
    ofs.write(str.c_str(),str.size());


    ofs.close();
}

//字符串输入流
void test1(){
    string s("123 456");
    int num = 0;
    int num2 =0;

    istringstream iss(s);
    iss >> num >> num2;
    cout << "num:" << num << endl;
    cout << "num2:" << num2 << endl;
}

//字符串输出流
void test3(){
    int num =123,num2 = 456;
    std::ostringstream oss;
    oss << "num = " << num << " ,num2 = " << num2;
    string line =oss.str();
    cout << line << endl;
}

int main()
{
    test3();
    return 0;
}

