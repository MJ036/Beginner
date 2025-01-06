#include "mai.h"
using namespace std;

class Screen;

class Window_mgr{
public:
    using ScreenIdx = std::vector<Screen>::size_type;
    Window_mgr();
    void clear(ScreenIdx);
    void display(ostream& os);
private:
    vector<Screen> _screens;
    
};

class Screen{
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos height, pos width):_height(height),_width(width),_content(height * width, ' '){}
    Screen(pos height, pos width, char c):_height(height),_width(width),_content(height * width, c){}

    Screen& move(pos r, pos col){
        _cursor = r * _width + col;
        return *this;
    }
    Screen& set(char c){
        _content[_cursor] = c;
        return *this;
    }
    Screen& set(pos r, pos col, char c){
        _content[r * _width + col] = c;
        return *this;

    }
    Screen& display(ostream& os){
        do_display(os);
        return *this;
    }
    const Screen& display(ostream& os) const {
        do_display(os);
        return *this;
    }

    pos size() const;

private:
    pos _cursor = 0;
    pos _height = 0, _width = 0;
    string _content;
private:
    void do_display(ostream &os) const {os << _content;};
    friend void Window_mgr::clear(ScreenIdx);
};

Screen::pos Screen::size()const{
    return _height * _width;
}

Window_mgr::Window_mgr():_screens{Screen(24,80,'#')}{}

void Window_mgr::clear(ScreenIdx idx){
    Screen &s = _screens[idx];
    s._content = string(s._height * s._width,' ');
}
void Window_mgr::display(ostream& os){_screens[0].display(os);};


void test_27(){
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}

void test_32(){
    Window_mgr win;
    win.display(cout);
    win.clear(0);
    cout << endl;
    win.display(cout);
}

int main()
{
    test_32();
    return 0;
}

