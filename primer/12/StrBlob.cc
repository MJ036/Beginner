#include "StrBlob.h"

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::check(size_type i,const std::string &msg)const{
    if(i >= data->size()){
        throw std::out_of_range(msg);
    }
}
void StrBlob::pop_back(){
    check(0,"back on empty StrBlob");
    data->pop_back();
}
    //访问元素
std::string& StrBlob::front(){
    return data->front();
}
std::string& StrBlob::back(){
    return data->back();
}

const std::string& StrBlob::front()const{
    return data->front();
}
const std::string& StrBlob::back()const{
    return data->back();
}

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this,data->size());
}
