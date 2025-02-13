#ifndef __STRING_H__
#define __STRING_H__

#include "mai.h"
#include <alloca.h>
#include <iterator>

using namespace std;

class String
{
public:
    String():_element(nullptr),_end(nullptr){
        cout << "String()" << endl;
    };
    String(const char*);
    String(const String&);
    String& operator=(const String&);
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

    static allocator<char> _alloc;
    char* _element;
    char* _end;

};
#endif


