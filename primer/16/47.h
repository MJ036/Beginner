#ifndef __47_H__
#define __47_H__

#include "mai.h"
#include <utility>

using namespace std;

template<typename F,typename T1,typename T2>
void outside(F f,T1 &&t1, T2 &&t2){
    f(std::forward(t1),std::forward(t2));
}

#endif


