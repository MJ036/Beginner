#include <string.h>
#include <iostream>

using namespace std;

class Person{
public:
    Person(char *name, int age)
        :_name(new char[strlen(name) + 1]())
         ,_age(age)
    {
        strcpy(_name,name);
    }

    Person(const Person &rhs)
        :_name(new char[strlen(rhs._name) + 1]())
         ,_age(rhs._age)
    {}
    
    Person &operator=(const Person &rhs)
    {
        if(this != &rhs){
            delete [] _name;
            _name = new char[strlen(rhs._name) + 1]();
            strcpy(_name,rhs._name);
            _age = rhs._age;
        }
        return *this;
    }




    void display(){
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
    }

protected:
    char *_name;
    int _age;
};

class Employee
:public Person
{
public:

    Employee(char *name,int age,char *department,double salary)
        :Person(name,age)
         ,_department(new char[strlen(department) + 1]())
         ,_salary(salary)
    {
        strcpy(_department,department);
    }

    Employee (const Employee &rhs)
        :Person(rhs)
    {
        
    }

    Employee &operator=(const Employee &rhs){
        if(this != &rhs){
            Person::operator=(rhs);
            delete [] _name;
            _name = new char[strlen(rhs._name) + 1]();
            strcpy(_name,rhs._name);

            delete [] _department;
            _department = new char[strlen(rhs._department) + 1]();
            strcpy(_department,rhs._department);

            _age = rhs._age;
            _salary = rhs._salary;
        }
        return *this;
    }



    void display(){
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
        cout << "department: " << _department << endl;
        cout << "salary: " << _salary << endl;
    }

    double getSalary(){
        return _salary;
    }

private:
    char *_department;
    double _salary;
};

void test(){
    Employee e1("mai",18,"jia",20);
    Employee e2("jia",20,"xuexiao",21);
    Employee e3("bao",22,"wangdao",23);
    cout << (e3.getSalary() + e2.getSalary() + e1.getSalary()) << endl;

    e2 = e1;
    e3 = e1;
    cout << (e3.getSalary() + e2.getSalary() + e1.getSalary()) << endl;


}

int main()
{
    test();
    return 0;
}

