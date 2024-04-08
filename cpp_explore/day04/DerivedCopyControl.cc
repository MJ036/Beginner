#include <iostream>
#include <string.h>


using namespace std;

class Base
{
public:
    Base()
        :_pbase(nullptr)
    {
        cout << "Base()" << endl;
    }

    Base(const char *pbase)
        :_pbase(new char[strlen(pbase) + 1 ])
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase,pbase);
    }

    Base(const Base &rhs)
        :_pbase(new char[strlen(rhs._pbase) + 1]())
    {
        cout << "Base(cosnt Base &)" << endl;
        strcpy(_pbase,rhs._pbase);
    }

    Base &operator=(const Base &rhs)
    {
        cout << "Base operator(const Base &)" << endl;
        if(this != &rhs){
            delete[] _pbase;
            _pbase = nullptr;

            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase,rhs._pbase);
        }
        return *this;
    }

    ~Base(){
        cout << "~Base()" << endl;
        if(_pbase){
            delete [] _pbase;
            _pbase = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Base &rhs);
    
private:
    char *_pbase;
};

std::ostream &operator<<(std::ostream &os, const Base &rhs)
{
    if(rhs._pbase){
        os <<rhs._pbase;
    }
    return os;
}

class Derived
:public Base
{
public:
    Derived(const char *pbase, const char *pderived)
        :Base(pbase)
         ,_pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(const char *, const char *)" << endl;
        strcpy(_pderived,pderived);
    }

    Derived(const Derived &rhs)
        :Base(rhs)
         ,_pderived(new char[strlen(rhs._pderived) + 1]())
    {
        cout << "Derived(const Derived &)" << endl;
        strcpy(_pderived,rhs._pderived);
    }

    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived &operator=(const Derived &)" << endl;
        if(this != &rhs){
            Base::operator=(rhs);

            delete [] _pderived;
            _pderived = nullptr;

            _pderived = new char[strlen(rhs._pderived) + 1]();
            strcpy(_pderived,rhs._pderived);
        }
        return *this;
    }

    ~Derived(){
        cout << "~Derived" << endl;
        if(_pderived){
            delete [] _pderived;
            _pderived = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);
private:
    char *_pderived;
};

std::ostream &operator<<(std::ostream &os, const Derived &rhs){
    const Base &ref = rhs;
    os << ref << "," << rhs._pderived;
    return os;
}


int main(){
    Derived d1("hello","world");
    cout << "d1 = " << d1 << endl;

    cout << endl;
    Derived d2(d1);
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << endl;

    Derived d3("hubei","wuhan");
    cout << "d3 = " << d3 << endl;
    cout << endl;

    d3 = d1;
    cout << "d1 = " << d1 << endl;
    cout << "d3 = " << d3 << endl;


    return 0;
}


