#include "mai.h"
using namespace std;

class TextEditor {
public:
    string text(){
        return _left.substr(max(0,(int)_left.size()-10));
    }

    
    void addText(string text) {
        _left += text;
    }
    
    int deleteText(int k) {
        k = min(k,(int)_left.length());
        _left.resize(_left.length() - k);
        return k;
    }
    
    string cursorLeft(int k) {
        while(k && !_left.empty()){
            _right += _left.back();
            _left.pop_back();
            --k;
        }
        return text();
    }
    
    string cursorRight(int k) {
        while(k && !_right.empty()){
            _left += _right.back();
            _right.pop_back();
            --k;
        }
       return text(); 
    }
private:
    string _left;
    string _right;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
