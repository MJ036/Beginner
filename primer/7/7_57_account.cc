#include "mai.h"

using namespace std;
class Account{
public:
    void calculate(){amount += amount * interestRate;}
    static double rate(){return interestRate;}
    static void rate(double);


private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};
double Account::interestRate = 0.02;

void Account::rate(double newRate){
    interestRate = newRate;
}

int main()
{
    Account ac;
    cout << ac.rate() << endl;
    ac.rate(0.1);
    cout << ac.rate() << endl;
    return 0;
}

