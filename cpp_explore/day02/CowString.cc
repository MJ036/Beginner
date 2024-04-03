#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
        :_pstr(new char[5]() + 4)
    {
        *(int*)(_pstr - 4) = 1;
    }

    String(const char *pstr)
    :_pstr(new char[strlen(pstr) + 5]() + 4)
    {
        strcpy(_pstr,pstr);
        *(int*)(_pstr - 4) = 1;
    }

    String(const String &rhs):_pstr(rhs._pstr)
    {
        ++*(int*)(_pstr - 4);
    }
    
    String &operator=(const String &rhs)
    {
        if(this != &rhs){
            --*(int*)(_pstr - 4);
            if(0 == *(int*)(_pstr - 4)){
                delete [] (_pstr - 4);
            }
            _pstr = rhs._pstr;
            ++*(int*)(_pstr - 4);
        }
        return *this;
    }

    char &operator[](size_t idx){
        if(idx < size()){
            if(getRefCount() > 1){
                char *ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp,_pstr);
                --*(int*)(_pstr - 4);
                _pstr = ptmp;
                ++*(int*)(_pstr - 4) = 1;
            }
            return _pstr[idx];
        }
        else{
            static char charnull = '\0';
            return charnull;
        }
    }

    ~String()
    {
        --*(int*)(_pstr - 4);
        if(0 == *(int*)(_pstr - 4)){
            delete [] (_pstr - 4);
        }
    }

public:
    const char *c_str() const
    {
        return _pstr;
    }

    int getRefCount() const
    {
        return *(int *)(_pstr - 4);
    }


private:
    size_t size() const
    {
        return strlen(_pstr);
    }

    friend std::ostream &operator<<(std::ostream &os,const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs){
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}


void test()
{String s1("hello");
String s2(s1);
cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
printf("s1'address : %p\n", s1.c_str());
printf("s2'address : %p\n", s2.c_str());

cout << endl;
String s3("world");
cout << "s3 = " << s3 << endl;
cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
printf("s3'address : %p\n", s3.c_str());

cout << endl << "使用s3 = s1进行赋值操作"  << endl;
s3 = s1;
cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
cout << "s3 = " << s3 << endl;
cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
printf("s1'address : %p\n", s1.c_str());
printf("s2'address : %p\n", s2.c_str());
printf("s3'address : %p\n", s3.c_str());

cout << endl << "对s3[0]执行写操作" << endl;
s3[0] = 'H';//'h' = 'H' char = char
cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
cout << "s3 = " << s3 << endl;
cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
printf("s1'address : %p\n", s1.c_str());
printf("s2'address : %p\n", s2.c_str());
printf("s3'address : %p\n", s3.c_str());

cout << endl << "对s1[0]执行读操作" << endl;
cout << "s1[0] = " << s1[0] << endl;
cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
cout << "s3 = " << s3 << endl;
cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
printf("s1'address : %p\n", s1.c_str());
printf("s2'address : %p\n", s2.c_str());
printf("s3'address : %p\n", s3.c_str());
}

int main(){
    test();
    return 0;
}
