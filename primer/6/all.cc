#include "mai.h"

using namespace std;

void test_3(){
    int n ;
    cout << "Enter a num:";
    cin >> n;
    int ret  = 1;
    while(n > 1){
        ret *= n--;
    }
    cout << "fact(n) = " << ret << endl;
}

void test_5(){
    cout << "Enter a num:";
    int n;
    cin >> n;
    cout << "abs of num: " << abs(n) << endl;
}

void test_7(){
    static int cnt = 0;
    cout << "cnt = " << cnt  << endl;
    cnt++;
}

int test_21(int a,int *p){
    return a > *p ? a :*p;

}
void test_22( int * &a, int * &b){
    int *temp = a;
    a = b;
    b = temp;

}

void test_23_0( int* i){
    cout << *i << endl;

}
void test_23_1( int j[],int length){
    for(int i = 0; i < length; ++i){
        cout << j[i] << " ";
    }
    cout << endl;
}
void test_23_2(int* beg, int* end){
    while(beg != end){
        cout << *beg++ << " " ;
    }
    cout << endl;
}
void test_23_3( int (&arr)[2]){
    for(auto num : arr){
        cout << num << " ";
    }
    cout << endl;

}

void test_23(){
    cout << "23" << endl;
    int j[2]= {0,1};
    test_23_1(j,2);
    test_23_2(begin(j),end(j));
    test_23_3(j);
}

int  test_27(initializer_list<int> il){
    int sum = 0;
    for(auto num : il){
        sum += num;
    }
    return sum;
}

bool test_30(const string str1, const string str2){
    if(str1.size() == str2.size()){
        return str1 == str2;
    }
    auto size = str1.size() < str2.size() ? str1.size() : str2.size();
    for(decltype(size) i = 0; i != size; i++){
        if(str1[i] != str2[i]){
    //        return;
        }
    }
    return 0;
}


void test_33(vector<int>::iterator beg,vector<int>::iterator end){
    if(beg != end){
        cout << *beg << endl;
        return test_33(beg+1,end);
    }
    cout << endl;
    return;
}

//6_36
string (&func_36(void))[10];

//6_37
typedef string(& pstr)[10];
pstr func_37_1();

auto func_37_2() -> string(&)[10];

void test_37_3(){
    string str[10];
    decltype(str) &test();
}

int odd[] = {1,3,5,7,9};
int even[] = {2,4,6,8,10};
decltype(odd)& test_38(int i){
    return (i%2)?even:odd;

}

//test_42
string make_plural(size_t ctr,const string &word,const string &ending = "s"){
    return (ctr > 1) ? word + ending : word;
}

//test_44
inline bool isShorter(const string &str1, const string &str2){
    return str1.size() < str2.size();
}

//test_46 str1.size() < str2.size()不是常量表达式，所以非法的
//constexpr  bool isShorter2(const string &str1, const string &str2){
//    return str1.size() < str2.size();
//}

void test_47(vector<int>::iterator beg,vector<int>::iterator end){
    #ifndef NDEBUG
		std::cerr  << __func__ << " " << __FILE__ << " "
		<< __LINE__ << " " << __TIME__ << " " << __DATE__ << std::endl;
	#endif
    if(beg != end){
        cout << *beg << endl;
        return test_47(beg+1,end);
    }
    return;
}

//test_51 
void f(){
    cout << "f()" << endl;
}
void f(int){
    cout << "f(int)" << endl;
}
void f(int,int){
    cout << "f(int,int)" << endl;
}
void f(double,double = 3.14){
    cout << "f(double,double = 3.14)" << endl;
}

typedef int func54(int,int);
int funcAdd(int a,int b){
    return a+b;
}
int funcSub(int a,int b){
    return a-b;
}
int funcDiv(int a,int b){
    return a/b;
}
int funcMul(int a,int b){
    return a*b;
}
void test_54(){
    vector<func54*> vec;
    vec.push_back(funcAdd);
    vec.push_back(funcSub);
    vec.push_back(funcMul);
    vec.push_back(funcDiv);
    int a = 15,b = 3;
    for(auto num : vec){
        cout << num(a,b) << endl;
    }
    cout << endl;
}

int main()
{
    //vector<int> vec = {1,2,3,4,5,6};
    //test_47(vec.begin(),vec.end());
//
//    for(auto num : test_38(4)){
//        cout << num << " ";
//    }
//    cout << endl;
//    cout<<endl;

//    cout << make_plural(2,"success","es") << endl;
//    cout << make_plural(2,"failure") << endl;
//    
//    int a = 1,b = 2;
//    double c = 1.1 , d = 1.2;
//    f();
//    f(c,d);
//    f(a,b);
//    f(a);
    test_54();
        
}

