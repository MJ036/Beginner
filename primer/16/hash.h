#ifndef __hash_H__
#define __hash_H__

#include "mai.h"
#include "../shared/Sales_data.h"

using namespace std;

namespace std{
template<>
    struct hash<Sales_data>{
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data& s) const;
        //拷贝控制和默认构造函数 均使用默认的
    };
size_t hash<Sales_data>::operator()(const Sales_data& s) const{
    return hash<string>()(s.BookNo) ^
        hash<unsigned>()(s.units_sold) ^
        hash<double>()(s.revenue);
}
}


#endif


