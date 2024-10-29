#include <string>
#include <iostream>

using namespace std;

int main()
{
    int *pInt = new int(10);
    string s1("hello");
    string s2("helloworldwuhan");
    string s3("helloworldwangdao");
    printf("s1 address = %p\n",s1.c_str());
    printf("s2 address = %p\n",s2.c_str());
    printf("s3 address = %p\n",s3.c_str());
    printf("&pInt %p\n",&pInt);
    printf("pInt %p\n",pInt);

    cout << "sizeof(s1) = " << sizeof(s1) << endl;
    cout << "sizeof(s3) = " << sizeof(s3) << endl;

    delete pInt;
    pInt = nullptr;
    return 0;
}

