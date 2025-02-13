#include "String.h"
#include <algorithm>
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
