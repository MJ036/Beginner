#include<string.h>
#include<string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(int num, string name, int year)
        :_num(num)
         ,_name(name)
         ,_year(year)
    {}
 //   {
 //       _name = new char[20]();
 //       strcpy(_name,name);
 //   }

    ~Student()
    {
       // if(_name)
       // {
       //     delete [] _name;
       //     _name = nullptr;
       // }
    }

    void print(){
        cout << "num = " << _num
            << "  " 
            << "name = " << _name
            << "  " 
            << "year = " << _year << endl;
    }



private:
    int _num;
    string _name;
    int _year;
};


int main()
{
    Student stu1(100,"mai",18);
    Student stu2(200,"jia",20);
    stu1.print();
    stu2.print();
    return 0;
}

