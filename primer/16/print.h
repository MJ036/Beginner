#ifndef __print_H__
#define __print_H__

#include "mai.h"

using namespace std;


template<typename T>
ostream& print(ostream& os, const T &t){
    os << t ;
    return os;
}

template<typename T, typename ... Args>
ostream& print(ostream& os,const T &t,const Args ... rest){
    os << t << ", ";
    return print(os,rest...);
}
#endif
