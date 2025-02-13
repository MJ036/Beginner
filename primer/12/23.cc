#include "mai.h"
#include <cstring>
using namespace std;

void test_23(){


    char str1[]="da shuai ge";
    char str2[]="mai jia bao";
    int n = strlen(str1)+strlen(str2);
    char* str = new char[n];
    strcpy(str,str1);
    strcat(str,str2);
    for(int i = 0; i < strlen(str); i++){
        cout << *(str+i);
    }
    cout << endl;
    delete[] str;
}

void test_23_1(){
    string str1 = "da shuai ge";
    string str2 = "mai jia bao";
    int n = str1.size() + str2.size();
    string* pstr = new string;
    *pstr = str1 + str2;
    cout << *pstr << endl;
    delete pstr;
}

int main()
{
    test_23_1();
}
