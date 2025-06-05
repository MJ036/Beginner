#ifndef __find_H__
#define __find_H__

#include <cstddef>
#include <cstdio>
#include "mai.h"
using namespace std;
namespace my{

template<typename T>
bool compare(T lhs, T rhs){
    return lhs < rhs;
}

template<typename iterator , typename T>
iterator find(iterator beg,iterator end,const T& val){
    while(beg != end && *beg != val){
        beg++;
    }
    return beg;
}

template<typename T >
void print(const T& array){
    for(const auto &a : array){
        cout << a << endl;
    }
}

template<typename T, unsigned N>
T* begin(const T(&arr)[N]){
    return arr;
}

template<typename T, unsigned N>
T* end(const T(&arr)[N]){
    return arr+N;
}

template<typename T,unsigned N>constexpr
unsigned size(const T(&arr)[N]){
    return N;
}


}
#endif


