#ifndef __DebugDelete_H__
#define __DebugDelete_H__

#include "mai.h"
#include <ostream>

using namespace std;

class Delete
{
public:

    template<typename T>
    //const 是为了让函数调用运算符，可以被const 的 Delete对象使用
    void operator()(T *p)const{
            delete p;
        }

};
class DebugDelete
{
public:
    DebugDelete(ostream & os = std::cerr):_os(os){};

    template<typename T>
    void operator()(T *p){
            _os << "operator() \n";
            delete p;
        }

private:
    ostream& _os;

};
#endif


