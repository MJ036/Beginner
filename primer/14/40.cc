#include "mai.h"
using namespace std;

class ShorterString
{
public:
	bool operator()(string const& s1, string const& s2) const { return s1.size() < s2.size(); }
};

class CountWord{
public:
    CountWord(int expect):_expect(expect){}
    bool operator()(const string &s)const{
        return _expect <= s.size();
    }


private:
    int _expect;
};

int main()
{

    return 0;
}

