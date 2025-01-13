#include "mai.h"

using namespace std;

void test3_2(){
    string line;
    while(cin >> line){
        cout << line << endl;
    }
    return;
}


void test3_2_1(){
    string word;
    while(cin >> word){
        cout << word << endl;
    }
    return;
}

void test3_4(){
    string str1;
    string str2;
    cin >> str1 >> str2;;
    if(str1 == str2){
        cout << "is equal : ";
        cout << str1 << endl;
        return;
    }
    if(str1 > str2){
        cout << str1 << endl;
    }else{
        cout << str2 << endl;
    }
}

void test3_4_1(){
    string str1;
    string str2;
    cin >> str1 >> str2;;
    if(str1.size() == str2.size()){
        cout << "equal !" << endl;
        return;
    }
    cout << "the longer is : ";
    if(str1.size() > str2.size()){
        cout << str1 << endl;
    }
    else{
        cout << str2 << endl;
    }

}

void test3_5(){
    string str,sum;
    while(cin >> str){
        sum  = str + sum;
    }
    cout << sum << endl;
}

void test3_5_1(){
    string str,sum;
    while(cin >> str){
        sum  = sum + str + " ";
    }
    cout << sum << endl;
}

void test3_6(){
    string str = "hello world 123 !";
    for(auto &c : str){
        if(isalnum(c)){
            c = 'X';
        }
    }
    cout << str << endl;
}

void test3_8(){
    string str = "hello world 123 !";

    /* for(int i = 0; i < str.size(); i++){ */
    /*     if(isalnum(str[i])){ */
    /*         str[i] = 'X'; */
    /*     } */
    /* } */


    decltype(str.size()) i = 0;
    while(i < str.size()){
        if(isalnum(str[i])){
            str[i] = 'X';
        }
        i++;
    }

    cout << str << endl;
}

void test3_9(){
    string s;
    cout << s[0] << endl;
}


void test3_10(){
    string str;
    string str_new;
    cin >> str;

    for(auto c : str){
        if(!ispunct(c)){
            str_new += c;
        }
    }
    cout << str_new << endl; 
}

void test3_31(){
    constexpr size_t array_size = 10;
    int a[array_size];
    for(size_t i = 0; i < array_size; i++){
        a[i] = i;
    }
    for(auto num : a){
        cout << num << " ";
    }
}

void test3_32(){
    constexpr size_t array_size = 10;
    int a[array_size];
    for(size_t i = 0; i < array_size; i++){
        a[i] = i;
    }
    vector<int> vec;
    for(auto num : a){
        vec.push_back(num);
    }
    for(auto num : vec){
        cout << num << " ";
    }
    cout << "\n";
}

//35

void print_intArray(int *pb,int *pe){
    while(pb != pe){
        cout << *pb << ",";
        pb++;
    } 
    cout << '\n';
}
void test3_35(){
    int ia[] = {0,2,4,6,8};
    int* pbeg = begin(ia),*pend = end(ia);

    print_intArray(pbeg,pend);

    pbeg = begin(ia);
    while(pbeg != pend){
        *pbeg = 0;
        pbeg++;
    }
    
    pbeg = begin(ia);
    print_intArray(pbeg,pend);
}

//3_36
bool compare(int *const pb1, int* const pe1,int* const pb2, int* const pe2){
    if((pe1 - pb1) != (pe2 - pb2)){
        return false;
    }
    else{
        for(int *i = pb1, *j = pb2; (i != pe1)&&(j != pe2); ++i,++j){
            if(*i != *j){
                return false;
            }
        }
    }
    return true;

}

void test3_36(){
    int ia[] = {0,2,4,6,8};
    int ib[] = {1,3,5,7,9};
    int ic[] = {0,2,4,6,8};

    if(compare(begin(ia),end(ia),begin(ib),end(ib))){
        cout << "equl" << '\n';
    }
    else{
        cout << "The two arrays are not equal." << endl;
    }

    if(compare(begin(ia),end(ia),begin(ic),end(ic))){
        cout << "equl" << '\n';
    }
    else{
        cout << "The two arrays are not equal." << endl;
    }

    vector<int> vec1 = {1,3,5};
    vector<int> vec2 = {2,4,6};
    vector<int> vec3 = {1,3,5};
    if(vec1 == vec2){
        cout << " equal" << endl;
    }
    else{
        cout << "not equal" << endl;
    }
}

void test3_39(){
    string s1("hello");
    string s2("world");
    if(s1 == s2){
        cout << "The two strings are equal."  << endl;
    }
    else{
        cout << "Thre two string are not equal" << endl;
    }

    char a1[] = "hello";
    char a2[] = "hello";
    if(!strcmp(a1,a2)){
        cout << "The two strings are equal."  << endl;
    }
    else{
        cout << "Thre two string are not equal" << endl;
    }
}

void print_charArray(char *pb,char *pe){
    while(pb != pe){
        cout << *pb;
        pb++;
    } 
    cout << '\n';
}
void test3_40(){
    char c1[] = "hello ";
    char c2[] = "world";
    char c3[15];
    strcpy(c3,c1);
    strcat(c3,c2);
    cout << c3;
}

void test_43(){
    int ia[3][4];
    int cnt = 0;
    for(auto &row : ia){
        for(auto &col : row){
            col = cnt;
            cnt++;
        }
    }

    for(auto &row : ia){
        for(auto &col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 4; col++){
            cout << ia[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int(*row)[4] = ia; row != ia+3; row++){
        for(int* col = *row; col != *row + 4; col++){
            cout << *col << " ";
        }
        cout << endl;
    }
}


int main()
{
    test_43();
    return 0;
}



