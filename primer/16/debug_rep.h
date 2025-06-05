#ifndef __debug_rep_H__
#define __debug_rep_H__

#include "mai.h"

using namespace std;

template<typename T>
string debug_rep(const T &){
    cout << "const T & " << endl;
    return string("1");
}

template<typename T>
string debug_rep(T*){
    cout << "T *" << endl;
    return string("1");
}

//string debug_rep(const string &){
//    cout << "const string &" << endl;
//    return string("1");
//}

template<>
string debug_rep(char *p){
    return debug_rep(string(p));
}

template<>
string debug_rep(const char *p){
   cout << "debug_rep(const char *p) " << endl;
return debug_rep(string(p));
}

#endif


