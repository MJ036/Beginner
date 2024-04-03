#include <iostream>


using namespace std;

class Line
{
public:
    class Point{
    public:
        Point(int x,int y)
            :_ix(x)
             ,_iy(y)
        {}

        friend class Line;
    public:
        void print() const{
            cout << "(" << _ix
                << "," << _iy
                << ")";
        } 

        static void show(){
            cout << "Point::show()" << endl;
        }

        void display() const{
            Line::test();
            test();
        }

        void getll(const Line & rhs){
            cout << rhs._length << endl;
            rhs.printLine();
        }
    private:

        int _ix;
        int _iy;
    };

public:
    Line(int x1, int y1, int x2, int y2)
        :_pt1(x1,y1)
         ,_pt2(x2,y2)
    {}
private:
    void printLine() const{
        Point::show();
    }

    static void test(){
        cout << "Line::test()" << endl;
    }

    Point _pt1;
    Point _pt2;
    double _length = 10;


};

void test0(){
    Line ll(1,2,3,4);

    Line::Point pt(9,8);

    cout << sizeof(pt) << endl;
    cout << sizeof(ll) << endl;
}

void test1(){
    Line::Point pt(1,2);
    pt.print();
    pt.display();
}

int main()
{
    test1();
    return 0;
}

