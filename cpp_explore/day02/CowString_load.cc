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
        initRefCount();
    }

    String(const char *pstr)
    :_pstr(new char[strlen(pstr) + 5]() + 4)
    {
        strcpy(_pstr,pstr);
        initRefCount();
    }

    String(const String &rhs):_pstr(rhs._pstr)
    {
        increaseRefCount();
    }
    
    String &operator=(const String &rhs)
    {
        if(this != &rhs){
            release();

            _pstr = rhs._pstr;
            increaseRefCount();
        }
        return *this;
    }

    char &operator[](size_t idx){
        if(idx < size()){
            if(getRefCount() > 1){
                char *ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp,_pstr);
                decreaseRefCount();
                _pstr = ptmp;
                increaseRefCount();
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
        release();
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

    void initRefCount(){
        *(int*)(_pstr - 4) = 1;
    }

    void increaseRefCount(){
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefCount(){
        --*(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefCount();
        if(0 == getRefCount()){
            delete [] (_pstr - 4);
        }
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
