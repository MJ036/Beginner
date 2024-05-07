#include <iostream>

using namespace std;

class Point
{
public:
  Point(int x, int y)
      :_x(x),_y(y)
  {}

  void print() const{
      cout << "print" << endl;
  }

private:
  int _x;
  int _y;
};

class Point3D
:public Point
{
    Point3D(int x, int y, int z)
        :Point(x,y)
         ,_z(z)
    {}

    void display() const{
        print();
        cout << _z << endl;
    }
private:
    int _z;
};




int main()
{

    return 0;
}

