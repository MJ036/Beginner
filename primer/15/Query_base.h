#ifndef __Query_base_H__
#define __Query_base_H__

#include "mai.h"
#include "../shared/Query.h"
#include "../shared/DebugDelete_template.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <queue>

using namespace std;

class Query;
class QueryResult;

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep()const = 0;
};
#endif


class WordQuery
:public Query_base
{
    friend class Query;
    WordQuery(const string &s):_query_word(s){
        cout << "WordQuery\n";
    }

    QueryResult eval(const TextQuery &t)const{
        return t.query(_query_word);
    }

    string rep()const{
        return _query_word;
    }
    
    string _query_word;

};

class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    friend ostream& operator<<(ostream &os,const Query &query);
public:
    Query(const string& s):_q(new WordQuery(s),DebugDelete()){
        cout << "Query\n";
    }
    QueryResult eval(const TextQuery &t)const{return _q->eval(t);};
    string rep()const{return _q->rep();}

private:
    Query(shared_ptr<Query_base> query):_q(query){}
    shared_ptr<Query_base> _q;

};
inline ostream& operator<<(ostream &os,const Query &query){
    return os << query.rep();
}


class NotQuery
:public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query& q):_query(q){
        cout << "NotQuery\n";
    }

    QueryResult eval(const TextQuery &text)const{
        auto result = _query.eval(text);
        auto ret_lines = make_shared<set<line_no>>();
        auto beg = result.begin(), end = result.end();
        auto sz = result.get_file()->size();
        for(size_t n = 0; n != sz; ++n){
            if(beg == end || *beg != n){
                ret_lines->insert(n);
            }else if(beg != end){
                ++beg;
            }
        }
        return QueryResult(rep(),ret_lines,result.get_file());

    }
    string rep()const{return "~(" + _query.rep() + ")";}
    Query _query;
};
inline Query operator~(const Query &q){
    return shared_ptr<Query_base>(new NotQuery(q),DebugDelete());
}

class BinaryQuery
:public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s)
        :_lhs(l),_rhs(r),_s(s){
        cout << "BinaryQuery\n";
        }

    string rep()const{return "(" + _lhs.rep() + " " + _s +  " " + _rhs.rep() + " ";}
    Query _lhs,_rhs;
    string _s;
};

class AndQuery
:public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& l, const Query& r):BinaryQuery(l,r,"&"){

        cout << "AndQuery\n";
    }

    QueryResult eval(const TextQuery &text) const{
        auto left = _lhs.eval(text), right = _rhs.eval(text);
        auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
        set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));
        return QueryResult(rep(),ret_lines,left.get_file());
    }
};
inline Query operator&(const Query& l, const Query& r){
    return shared_ptr<Query_base>(new AndQuery(l,r),DebugDelete());
}

class OrQuery
:public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& l, const Query& r):BinaryQuery(l,r,"&"){
        cout << "OrQuery\n";
    }

    QueryResult eval(const TextQuery& text) const{
        auto left = _lhs.eval(text), right = _rhs.eval(text);
        auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
        ret_lines->insert(right.begin(),right.end());
        return QueryResult(rep(),ret_lines,left.get_file());
    }
};
inline Query operator|(const Query& l, const Query& r){
    return shared_ptr<Query_base>(new OrQuery(l,r),DebugDelete());
}






