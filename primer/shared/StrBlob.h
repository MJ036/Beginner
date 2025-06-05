#include"mai.h"
#include <memory>

using namespace std;
class StrBlobPtr;
//对智能指针进行包装，指向vector<string>
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size(){return data->size();}
    bool empty() const {return data->empty();};
    //添加删除元素
    void push_back(const std::string &t){data->push_back(t);};
    void pop_back();
    //访问元素
    std::string& front();
    std::string& back();
    const std::string& front()const;
    const std::string& back()const;

    StrBlobPtr begin();
    StrBlobPtr end();


private:
    //指向动态内存的智能指针
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

//用于访问StrBlob的伴随类
class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data),curr(sz){}
    bool operator!=(const StrBlobPtr&p){return p.curr != curr;}
    string &deref()const{
        auto p = check(curr,"deference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret){
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if(i >= ret->size()){
            throw std::out_of_range(msg);
        }
        return ret;
    }
};


