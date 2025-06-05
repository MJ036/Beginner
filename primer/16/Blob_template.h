#include"mai.h"
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include "shared_ptr.h"

using namespace std;
template<typename T>
class BlobPtr;
//Blob的功能：封装指向vector数组的智能指针，以及相关操作
template<typename T>
class Blob
{
public:
    typedef typename std::vector<T>::size_type size_type;
    friend class BlobPtr<T>;

    template<typename It>
        Blob(It b, It e);
    Blob(std::initializer_list<T> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();};
    //添加删除元素
    void push_back(const T &t){data->push_back(t);};
    void pop_back();
    //访问元素
    T& front();
    T& back();
    const T& front()const;
    const T& back()const;

    BlobPtr<T> begin();
    BlobPtr<T> end();


private:
    //指向动态内存的智能指针
    shared_ptr<std::vector<T>> data;
    void check(size_type i, const string &msg) const;
};

//用于访问Blob的伴随类
//curr存储了指针当前指向元素的位置。这里的BlobPtr相当于一个迭代器
template<typename T>
bool operator!=(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs){
    if(lhs.wptr.lock() != rhs.wptr.lock()){
        throw runtime_error("ptrs to different Blob");
    }
    return lhs.curr != rhs.curr;

}
template<typename T>
class BlobPtr{
    friend bool operator!=<T>(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs);
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a, size_t sz = 0):wptr(a.data),curr(sz){}
    T& deref()const{
        auto p = check(curr,"deference past end");
        return (*p)[curr];
    }
    BlobPtr& incr(){
        check(curr,"increment past end of BlobPtr");
        ++curr;
        return *this;
    }

private:
    weak_ptr<vector<T>> wptr;
    size_t curr;
    shared_ptr<vector<T>> check(size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret){
            throw std::runtime_error("unbound BlobPtr");
        }
        if(i >= ret->size()){
            throw std::out_of_range(msg);
        }
        return ret;
    }
};


template<typename T>
template<typename It>
    Blob<T>::Blob(It b,It e):data(std::make_shared<std::vector<T>>(b,e)){}
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)){}

template<typename T>
void Blob<T>::check(size_type i,const string &msg)const{
    if(i >= data->size()){
        throw std::out_of_range(msg);
    }
}
template<typename T>
void Blob<T>::pop_back(){
    check(0,"back on empty Blob");
    data->pop_back();
}
//访问元素
template<typename T>
T& Blob<T>::front(){
    return data->front();
}
template<typename T>
T& Blob<T>::back(){
    return data->back();
}

template<typename T>
const T& Blob<T>::front()const{
    return data->front();
}
template<typename T>
const T& Blob<T>::back()const{
    return data->back();
}

template<typename T>
BlobPtr<T> Blob<T>::begin(){
    return BlobPtr<T>(*this);
}
template<typename T>
BlobPtr<T> Blob<T>::end(){
    return BlobPtr<T>(*this,data->size());
}
