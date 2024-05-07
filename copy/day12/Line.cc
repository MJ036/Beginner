#include <iostream>

using namespace std;

class Line
{
public:
    Line(int ix1, int iy1, int ix2 ,int iy2)
        :_pt1(ix1,iy1)
         ,_pt2(ix2,iy2)
    {}

    void printLine() const
    {
        _pt1.print();
        cout << "--->";
        _pt2.print();
        cout << endl;
    }

    ~Line()
    {

    }

private:

    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
            :_ix(ix)
             ,_iy(iy)
        {}

        void print() const
        {
            cout << "(" << _ix
                <<"," << _iy
                <<")" ;
        }

        ~Point(){

        }
        
    private:
        int _ix;
        int _iy;
        
    };

    Point _pt1;
    Point _pt2;
};

int main()
{
    Line line(1,2,3,4);
    line.printLine();
    return 0;
}

