#ifndef __STRVEC_H__
#define __STRVEC_H__ 

#include "mai.h"
#include <cstdlib>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>

using namespace std;

class StrVec
{
public:
    StrVec():
        _element(nullptr),_first_free(nullptr),_cap(nullptr){};
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();

    void push_back(const string&);

    size_t size()const{return _first_free - _element;}
    void reserve(size_t );
    void resize(size_t);
    size_t capacity() const {return _cap - _element;}
    string *begin() const {return _element;}
    string *end() const {return _first_free;}

    template<typename... Args>
        void emplace_back(Args&& ...args){
            chk_n_alloc();
            alloc.construct(_first_free++,std::forward<Args>(args)...);
        }

private:
    //分配元素
    static allocator<string> alloc;
    //添加元素前使用的函数
    void chk_n_alloc(){
        if(size() == capacity()) reallocate();
    }
    //工具函数
    pair<string*, string*> alloc_n_copy(const string*,const string*);
    void free();
    void reallocate();

    string *_element;
    string *_first_free;
    string *_cap;

};
#endif


