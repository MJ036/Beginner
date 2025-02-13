#ifndef __32_H__
#define __32_H__

#include "mai.h"
#include "StrBlob.h"
#include <cstring>
#include <memory>
using namespace std;

class QueryResult;
class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;
    
private:
    //QueryResult类也要访问文本内容，行号，所以vector、set直接用shared_ptr管理
    shared_ptr<StrBlob> _file;
    map<string,shared_ptr<set<line_no>>> _wm;
};

class QueryResult{
public:
    friend ostream& print(ostream &, const QueryResult&);
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> lines, shared_ptr<StrBlob> blob):_sought(s),_lines(lines),_file(blob){}
private:
    string _sought;
    shared_ptr<set<TextQuery::line_no>> _lines;
    shared_ptr<StrBlob> _file;

};
#endif
