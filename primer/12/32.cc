#include "32.h"
#include <memory>
#include <openssl/types.h>


TextQuery::TextQuery(ifstream &ifs):_file(make_shared<StrBlob>()){
    string line;
    while(getline(ifs,line)){
        _file->push_back(line);
        size_t l = _file->size() - 1;
        istringstream iss(line);
        string word;
        while(iss >> word){
            auto &lines = _wm[word];
            if(!lines){
                lines.reset(new set<line_no>);
            }
            lines->insert(l);
        }
    }
}

QueryResult TextQuery::query(const string&s )const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = _wm.find(s);
    if(loc == _wm.end()){
        return QueryResult(s,nodata,_file);
    }else{
        return QueryResult(s,loc->second,_file);
    }
}

ostream& print(ostream& os, const QueryResult& qr){
    os << qr._sought << " occurs " << qr._lines->size() << " "
        << "time" << (qr._lines->size() > 1 ? "s" : "") << endl;
    for(auto num : *qr._lines){
        //os << "\t(line " << num + 1 << ")" << *(qr._file->begin() + num) << endl; 
        os << "\t(line " << num + 1 << ")" << StrBlobPtr(*qr._file,num).deref() << endl; 
    }
    return os;
}
