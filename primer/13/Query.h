#ifndef __QUERY_H__
#define __QUERY_H__

#include "mai.h"
#include "StrVec.h"
#include <cstring>
#include <memory>
using namespace std;

class QueryResult;
class TextQuery{
public:
    using line_no = size_t;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;
private:
    //QueryResult类也要访问文本内容，行号，所以vector、set直接用shared_ptr管理
    shared_ptr<StrVec> _file;
    map<string,shared_ptr<set<line_no>>> _wm;
};

class QueryResult{
public:
    using line_no = size_t;
    friend ostream& print(ostream &, const QueryResult&);
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> lines, shared_ptr<StrVec> blob):_sought(s),_lines(lines),_file(blob){}

    using Iter = set<line_no>::iterator;
    Iter begin() const { return _lines->begin();}
    Iter end() const { return _lines->end(); }

    shared_ptr<StrVec> get_file()const{
        return _file;
    }

private:
    string _sought;
    shared_ptr<set<TextQuery::line_no>> _lines;
    shared_ptr<StrVec> _file;

};
#endif
