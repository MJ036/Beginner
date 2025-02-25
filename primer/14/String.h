#ifndef __STRING_H__
#define __STRING_H__

#include "mai.h"
#include <alloca.h>
#include <iterator>
#include <ostream>

using namespace std;

class String
{
    friend ostream& operator<<(ostream& os, const String& s);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
public:
    String():_element(nullptr),_end(nullptr){
        cout << "String()" << endl;
    };
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    char& operator[](size_t n);
    
    ~String();

    const char* c_str() const {
        return _element;
    }
    //字符串中字符的个数，不含/0
    size_t size() const { return _end - _element; }
    //字符串的长度，含/0
    size_t length() const {return _end - _element + 1;}

private:
    pair<char*, char*> alloc_n_copy(const char*,const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    static allocator<char> _alloc;
    char* _element;
    char* _end;

};
#endif


