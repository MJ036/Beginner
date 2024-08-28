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

int main()
{
    test3_10();
    return 0;
}



