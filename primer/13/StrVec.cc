#include "StrVec.h"
#include <algorithm>
#include <openssl/evp.h>

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec& s){
    auto newdata = alloc_n_copy(s.begin(),s.end());
    _element = newdata.first;
    _first_free = _cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il){
    auto newdata = alloc_n_copy(il.begin(),il.end());
    _element = newdata.first;
    _first_free = _cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs){
    auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    _element = newdata.first;
    _first_free = _cap = newdata.second;
    return *this;
}
StrVec::StrVec(StrVec&& rhs) noexcept
    :_element(rhs._element),_first_free(rhs._first_free),_cap(rhs._cap)
    {
        rhs._element = rhs._first_free = rhs._cap = nullptr;
    }
StrVec& StrVec::operator=(StrVec&& rhs) noexcept{
    if(this != &rhs){
        free();
        _element = rhs._element;
        _first_free = rhs._first_free;
        _cap = rhs._cap;
        rhs._element = rhs._first_free = rhs._cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec(){
    free();
}

void StrVec::push_back(const string& s){
    chk_n_alloc();
    alloc.construct(_first_free++,s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string* b,const string* e){
    auto data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free(){
    //    //如果_element为空，则什么都不做
    //    if(_element){
    //        for(auto p = _first_free; p != _element;){
    //            alloc.destroy(--p);
    //        }
    //        alloc.deallocate(_element,_cap - _element);
    //    }

    //for_each + lambda实现
    //非静态成员要通过this去访问，所以要捕获this。但该代码段在该类的成员函数中，所以不捕获也可以
    for_each(begin(),end(),[this](string& rhs){
             alloc.destroy(&rhs);
             });
    alloc.deallocate(_element,_cap - _element);
}

void StrVec::reallocate(){
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

void StrVec::resize(size_t n){
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

void StrVec::reserve(size_t n){
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




