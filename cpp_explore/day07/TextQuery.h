#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class TextQuery
{
public:
    TextQuery();
    void readFile(const string &file);
    void query(const string &word);

private:
    void preProcessLine(string &line);

private:
    vector<string> _file;
    map<string,int> _dict;
    map<string,set<int>> _word2line;
};


#endif

