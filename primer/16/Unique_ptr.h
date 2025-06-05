#ifndef __Unique_ptr_H__
#define __Unique_ptr_H__

#include "mai.h"
#include "DebugDelete.h"
#include <utility>

using namespace std;

template<typename,typename> class Unique_ptr;
template<typename T,typename D> inline void swap(Unique_ptr<T,D>& lhs,Unique_ptr<T,D>&rhs){
    swap(lhs._p,rhs._p);
    swap(lhs.deleter,rhs.deleter);
}

template<typename T,typename D = DebugDelete>
class Unique_ptr
{
    friend void swap<T,D>(Unique_ptr<T,D>& lhs, Unique_ptr<T,D>& rhs);
public:
    //禁止拷贝、赋值
    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;
    Unique_ptr() = delete;

    explicit Unique_ptr(T* u = nullptr):_p(u){};

    Unique_ptr(Unique_ptr && u)noexcept : _p(u._p){
        u._p = nullptr;
    }
    Unique_ptr& operator=(Unique_ptr &&u){
        //防止自赋值
        if(this != u){
            //删除原来的资源
            delete _p;
            //接管资源对象
            _p = u._p;
            u._p = nullptr;
        }
        return *this;
    }

    void reset(T *p = nullptr){
        delete _p;
        _p = p;
    };

    T* get() const {return _p;}

    T* release(){
        T* temp = _p;
        _p = nullptr;
        return temp;
    }

    T& operator*() const{
        return *_p;
    }
    T* operator->() const{
        return _p;
    }

    explicit operator bool() const {
        return _p != nullptr;
    }

    ~Unique_ptr(){
        delete _p;
    }

private:
    T* _p = nullptr;
    D deleter = D();

};
#endif


