#ifndef __print_template_H__
#define __print_template_H__

#include "mai.h"

using namespace std;

template<typename T>
void print(T& t){
    //size版本
//    using size_type = typename T::size_type;
//    size_type size = t.size();
//    for(size_type i = 0; i < size; i++){
//        cout << t[i] << " ";
//    }
//    cout << endl;
    //迭代器版本
    using it = typename  T::iterator;
    it beg = t.begin(),end = t.end();
    for(;beg!=end; beg++){
        cout << *beg << " ";
    }
    cout << endl;
}




#endif


