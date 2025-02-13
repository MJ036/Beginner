#ifndef __HASPPTR_H__
#define __HASPPTR_H__
#include "mai.h"
#include <functional>
#include <random>
#include <sys/mman.h>
using namespace std;

class HasPtr{
public:
    HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    HasPtr(const HasPtr & hp):ps(new string(*hp.ps)),i(hp.i),use(hp.use){
        ++*use;
    }
    
    //将原来指向的内存释放，并指向新的内存
    HasPtr& operator=(const HasPtr& hp){
        ++*hp.use;
        if(--*use == 0){
            delete ps;
            delete use;
        }
        //string *new_ps = new string(*hp.ps);
        //ps = new_ps;

        ps = hp.ps;
        i = hp.i;
        use = hp.use;
        return *this;
    }
    ~HasPtr(){
        if(!ps){
            delete ps;
        }
    }

    string get_str(){
        return *ps;
    }
    friend void swap(HasPtr&,HasPtr&);
    friend bool operator<(const HasPtr& lhs,const HasPtr &rhs);
private:
    string* ps;
    int i;
    size_t* use;
};
    bool operator<(const HasPtr& lhs,const HasPtr &rhs){
        return *lhs.ps < *rhs.ps;
    }

inline void swap(HasPtr& lhs,HasPtr& rhs){
    std::swap(lhs.i,rhs.i);
    std::swap(rhs.ps,rhs.ps);
    cout << "call swap(HasPtr& ,HasPtr&)" << endl;
}
#endif

