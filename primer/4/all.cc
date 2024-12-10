#include "mai.h"

using namespace std;

bool is_odd(int a){
    if(a % 2 == 0){
        return false;
    }else{
        return true;
    }
}

void test_21(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

    for(auto num : vec){
        cout << num << " ";
    }
    cout << endl;

    for(auto &num : vec){
        num = (is_odd(num) ? num << 1 : num);
    }
    for(auto num : vec){
        cout << num << " ";
    }
    cout << endl;

}

void test_22_1(){
    int a;
    cin >> a;
    string finalGrade = (a > 90 ? "high pass" : (a > 75 ? "pass" :(a > 60 ? "low pass" : "fail")));
    cout << finalGrade << endl;
}
void test_22_2(){
    int a;
    cin >> a;
    if(a > 90){
        cout <<  "high pass";
    }else if(a > 75){
        cout << "pass";
    }else if(a > 60){
        cout << "low pass";
    }else{
        cout << "fail";
    }
    cout << '\n';
}

void test_28(){
    cout << "char :" << sizeof(char) << endl;
    cout << "int:" << sizeof(int) << endl;
    cout << "short:" << sizeof(short) << endl;
    cout << "unsigned int:" << sizeof(unsigned int) << endl;
    cout << "float : " << sizeof(float) << endl;
    cout << "double:" << sizeof(double) << endl;
}

void test_29(){
    int x[10];
    int *p = x;
    cout << sizeof(p) / sizeof(*p) << endl;
}

void test_36(){
    int i = 25;
    double d = 4.5;
    i *= static_cast<int>(d);
    cout << i << endl;
    return ;
}

void test_37(){
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;
    pv = static_cast<void*>(const_cast<string *>(ps));
    i = static_cast<int>(*pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);
}

int main()
{
    test_29();
    return 0;
}

