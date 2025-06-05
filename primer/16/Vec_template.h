#ifndef __Vec_H__
#define __Vec_H__ 

#include "mai.h"
#include <cstdlib>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>

using namespace std;

template<typename T>
class Vec
{
public:
    Vec():
        _element(nullptr),_first_free(nullptr),_cap(nullptr){};
    Vec(initializer_list<T>);
    Vec(const Vec&);
    Vec(Vec&&) noexcept;
    Vec& operator=(const Vec&);
    Vec& operator=(Vec&&) noexcept;
    ~Vec();

    void push_back(const T&);

    size_t size()const{return _first_free - _element;}
    void reserve(size_t );
    void resize(size_t);
    size_t capacity() const {return _cap - _element;}
    T *begin() const {return _element;}
    T *end() const {return _first_free;}
private:
    //分配元素
    static allocator<T> alloc;
    //添加元素前使用的函数
    void chk_n_alloc(){
        if(size() == capacity()) reallocate();
    }
    //工具函数
    pair<T*, T*> alloc_n_copy(const T*,const T*);
    void free();
    void reallocate();

    T *_element;
    T *_first_free;
    T *_cap;

};


template<typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b,const T* e){
    auto data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b,e,data)};
}
template<typename T>
Vec<T>::Vec(const Vec<T>& s){
    auto newdata = alloc_n_copy(s.begin(),s.end());
    _element = newdata.first;
    _first_free = _cap = newdata.second;
}

template<typename T>
Vec<T>::Vec(initializer_list<T> il){
    auto newdata = alloc_n_copy(il.begin(),il.end());
    _element = newdata.first;
    _first_free = _cap = newdata.second;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs){
    auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    _element = newdata.first;
    _first_free = _cap = newdata.second;
    return *this;
}
template<typename T>
Vec<T>::Vec(Vec<T>&& rhs) noexcept
    :_element(rhs._element),_first_free(rhs._first_free),_cap(rhs._cap)
    {
        rhs._element = rhs._first_free = rhs._cap = nullptr;
    }
template<typename T>
Vec<T>& Vec<T>::operator=(Vec<T>&& rhs) noexcept{
    if(this != &rhs){
        free();
        _element = rhs._element;
        _first_free = rhs._first_free;
        _cap = rhs._cap;
        rhs._element = rhs._first_free = rhs._cap = nullptr;
    }
    return *this;
}

template<typename T>
Vec<T>::~Vec<T>(){
    free();
}

template<typename T>
void Vec<T>::push_back(const T& s){
    chk_n_alloc();
    alloc.construct(_first_free++,s);
}

template<typename T>
void Vec<T>::free(){
    //    //如果_element为空，则什么都不做
    //    if(_element){
    //        for(auto p = _first_free; p != _element;){
    //            alloc.destroy(--p);
    //        }
    //        alloc.deallocate(_element,_cap - _element);
    //    }

    //for_each + lambda实现
    //非静态成员要通过this去访问，所以要捕获this。但该代码段在该类的成员函数中，所以不捕获也可以
    for_each(begin(),end(),[this](T& rhs){
             alloc.destroy(&rhs);
             });
    alloc.deallocate(_element,_cap - _element);
}

template<typename T>
void Vec<T>::reallocate(){
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = _element;
    for(size_t i = 0; i != size(); ++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    _element = newdata;
    _first_free = dest;
    _cap = _element + newcapacity;
}

template<typename T>
void Vec<T>::resize(size_t n){
    if(n > capacity()){
        reserve(n);
    }else{
        auto newdata = alloc.allocate(n);
        auto dest = newdata;
        auto elem = _element;
        for(size_t i = 0; i != n; ++i){
            alloc.construct(dest++,std::move(*elem++));
        }
        free();
        _element = newdata;
        _first_free = dest;
        _cap = _element + n;

    }
}

template<typename T>
void Vec<T>::reserve(size_t n){
    if(n < capacity()) return;
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = _element;
    for(size_t i = 0; i != size(); ++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    _element = newdata;
    _first_free = dest;
    _cap = _element + n;
}
#endif


