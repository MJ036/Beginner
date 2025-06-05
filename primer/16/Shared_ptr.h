#ifndef __Shared_ptr_H__
#define __Shared_ptr_H__

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>
#include "mai.h"
#include "DebugDelete.h"

using namespace std;

namespace my{

template<typename T>
class Shared_ptr;

template<typename T>
    void swap(Shared_ptr<T>&lhs,Shared_ptr<T>&rhs){
        using std::swap;
        swap(lhs._p,rhs._p);
        swap(lhs._ref_count,rhs._ref_count);
        swap(lhs.deleter,rhs.deleter);
    }

template<typename T>
class Shared_ptr
{
public:
    //无参构造
    Shared_ptr():_p(nullptr),_ref_count(new size_t(1)),deleter(Delete()){}
    
    //有参构造
    Shared_ptr(T* raw_ptr):_p(raw_ptr),_ref_count(new size_t(1)),deleter(Delete()){
    }

    //拷贝构造
    Shared_ptr(Shared_ptr const& S):_p(S._p),_ref_count(S._ref_count),deleter(S.deleter){
        ++_ref_count;
    }

    //移动构造
    Shared_ptr(Shared_ptr &&S) noexcept
        :_p(S._p),_ref_count(S._ref_count),deleter(std::move(S.deleter)){
            S._p = nullptr;
            S._ref_count = nullptr;
        }

    //赋值运算符
    Shared_ptr& operator=(Shared_ptr const& rhs){
        ++*rhs._ref_count;
        decrement_and_destory();
        _p = rhs._p;
        _ref_count = rhs._ref_count;
        deleter = rhs.deleter;
        return *this;
    }

    //移动赋值
    Shared_ptr& operator=(Shared_ptr && rhs){
        swap(*this,rhs);
        rhs.decrement_and_destory();
        return *this;
    }

    //类型转换运算符
    operator bool() const{
        return _p ? true : false;
    }

    //解引用运算符
    T& operator*()const{
        return *_p;
    }
    
    //箭头访问运算符
    T* operator->()const{
        return _p;
    }

    //成员函数
    size_t use_count() const{
        return *_ref_count;
    }

    T* get() const{
        return _p;
    }

    bool unique() const{
        return 1 == *_ref_count;
    }

    void swap(Shared_ptr& rhs){
        //从全局区域里找函数
        ::swap(rhs,*this);
    }

    void reset(){
        decrement_and_destory();
    }

    //reset是用一个指针，重新初始化智能指针，传入参数是初始化后指向新内容
    void reset(T* s){
        if(_p != s){
        decrement_and_destory();
        _p = s->_p;
        _ref_count = new size_t(1);
        deleter = s->deleter;
        }

    }

    void reset(T *s, const std::function<void(T*)>& d){
        reset(s);
        deleter = d;
    }

    //析构
    ~Shared_ptr(){
        decrement_and_destory();
    }

private:
    T * _p;
    size_t *_ref_count;
    function<void(T*)> deleter;

    //将当前shared_ptr置为空，在此之前要将引用计数的值减一，如果为减后为0，还要释放堆空间
    void decrement_and_destory(){
        if(_p && 0 == --*_ref_count){
            delete _ref_count;
            deleter(_p);
        //默认构造的Shared_ptr会出现指针为空，但_ref_count不为空的情况
        }else if(!_p){
            delete _ref_count;
        }
        _ref_count = nullptr;
        _p = nullptr;

    }

};



}//namespace my
#endif


