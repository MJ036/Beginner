#include "mai.h"
#include <mysql/mysql.h>
using namespace std;

class Employee{
public:
    Employee();
    Employee(const string& name);
    Employee(Employee& n) = delete;
    Employee& operator=(const Employee&) = delete;

private:
    static int unique;
    string _name;
    int _no;
};
int Employee::unique = 1;


