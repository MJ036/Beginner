#ifndef __FOO_H__
#define __FOO_H__

#include "mai.h"

using namespace std;

class Foo
{
public:
    Foo sorted() const &{
        	std::cout << "sorted() &" << std::endl;
        Foo ret(*this);
        return ret.sorted();
    }
    Foo sorted() &&{
        	std::cout << "sorted() &&" << std::endl;
        sort(_data.begin(),_data.end());
        return *this;
    }
//   Foo sorted() const &{
//        	std::cout << "sorted() &" << std::endl;
//       return Foo(*this).sorted();
//   }

private:
    vector<int> _data;

};
#endif


