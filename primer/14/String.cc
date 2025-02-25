#include "String.h"
#include <algorithm>
#include <cstring>
#include <memory>
#include <openssl/evp.h>

allocator<char> String::_alloc;

pair<char*, char*> String::alloc_n_copy(const char* b,const char* e){
    auto data = _alloc.allocate(e - b);
    return {data,uninitialized_copy(b,e,data)};
}


void String::range_initializer(const char* first, const char* last){
    auto newstr = alloc_n_copy(first,last);
    _element = newstr.first;
    _end = newstr.second;

}

String::String(const char* s){
    char *s1 = const_cast<char*>(s);
    while(*s1){
        ++s1;
    }
    //range_initializer的第二个参数，是为了把C风格字符串末尾的'\0'也拷贝过去
    range_initializer(s,++s1);
    cout << "String(const char* s)" << endl;
}
String::String(const String& rhs){
    range_initializer(rhs._element,rhs._end);
    cout << "String(const String* s)" << endl;

}


void String::free(){
    if(_element){
        for_each(_element,_end,[](char &c){
                 _alloc.destroy(&c);
                 });
        _alloc.deallocate(_element,_end - _element);
    }
}

String::~String(){
    free();
    cout << "~String" << endl;
}

String& String::operator=(const String& rhs){
    auto newstr = alloc_n_copy(rhs._element,rhs._end);
    free();
    _element = newstr.first;
    _end = newstr.second;
    cout << "String& operator=(const String&)" << endl;
    return *this;
}

String::String(String && rhs) noexcept
:_element(rhs._element),_end(rhs._end)
{
    cout << "String(String &&)" << endl;
    rhs._element = rhs._end = nullptr;
}
String& String::operator=(String&& rhs) noexcept{
    cout << "operator=(String &&)" << endl;
    if(this != &rhs){
        free();
        _element = rhs._element;
        _end = rhs._end;
        rhs._element = rhs._end = nullptr;
    }
    return *this;
}
ostream& operator<<(ostream& os, const String& s){
    for(auto b = s._element;b != s._end;b++){
        os << *b;
    }
    return os;
}
bool operator==(const String& lhs, const String& rhs){
    return !strcmp(lhs.c_str(),rhs.c_str());

}
bool operator!=(const String& lhs, const String& rhs){
   return !(lhs == rhs);
}
char& String::operator[](size_t n){
    return *(_element + n);
}
