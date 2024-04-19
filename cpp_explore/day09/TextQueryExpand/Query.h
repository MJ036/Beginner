#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

class Query_base{
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
};



#endif
