#ifndef __Screen_H__
#define __Screen_H__

#include "mai.h"
#include <istream>
#include <ostream>

using namespace std;

template<unsigned H,unsigned W>
class Screen
{
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(char c):contents(H*W,c){}
    char get() const {
        return contents[cursor];
    }
    Screen &move(pos r, pos c){
        pos row = r * width;
        cursor = row + c;
        return *this;
    }

    friend ostream &operator<<(std::ostream &os, const Screen<H,W> &c){
        for(unsigned i = 0; i < H; i++){
            os << c.contents.substr(i*W,W) << endl;
        }
        return os;
    }
    friend istream &operator>>(std::istream &is, Screen<H,W> &c){
        char a;
        is >> a;
        c.contents.assign(H*W,a);
        return is;


    }

private:
    pos height = H ,width = W;
    pos cursor = 0;
    string contents;


};
#endif


