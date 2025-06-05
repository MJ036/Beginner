#ifndef __DebugDelete_H__
#define __DebugDelete_H__

#include "mai.h"
#include <ostream>

using namespace std;

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


