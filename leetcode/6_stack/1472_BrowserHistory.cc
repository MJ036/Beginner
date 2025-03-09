#include "mai.h"
#include <algorithm>
#include <hiredis/alloc.h>
#include <vector>
using namespace std;
class BrowserHistory {
public:
    BrowserHistory(string homepage):_history{homepage}{
    }

    void visit(string url) {
        cur++;
        _history.resize(cur);
       _history.push_back(url);
    }

    string back(int steps) {
        cur = max(cur - steps,0);
        return _history[cur];
    }

    string forward(int steps) {
        cur = min(cur + steps,(int)_history.size()-1);
        return _history[cur];
        
    }
private:
    vector<string> _history;
    int cur = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


