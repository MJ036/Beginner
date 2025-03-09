#include "mai.h"
#include <csignal>
#include <iterator>
#include <memory>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string bookNo, double sales_price)
        :_bookNo(bookNo)
         ,_price(sales_price)
    {}

    string isbn() const {return _bookNo;}

    virtual double net_price(size_t n) const {
        return n * _price;
    }

    virtual void debug(){
        cout << "_bookNo: " << _bookNo << "\n"
            << "_price:"  << _price << "\n";
    }

    virtual ~Quote() = default;

private:
    string _bookNo;
protected:
    double _price;
};

class Bulk_quote
:public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string bookNo, double sales_price,size_t cnt,double discount)
        :Quote(bookNo,sales_price)
         ,_min_qty(cnt)
         ,_discount(discount)
    {}

    double net_price(size_t cnt)const override {
        if(cnt > _min_qty){
            auto base = _min_qty * _price;
            auto add  = (cnt - _min_qty) * (1 - _discount) * _price;
            return base + add;
        }else{
            return cnt * _price;
        }
    }

    void debug() override {
        Quote::debug();
        cout << "_min_qty: " << _min_qty << "\n"
            << "_discount: " << _discount << "\n";
    }
private:
    size_t _min_qty;
    double _discount;


};

double print_total(ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() <<" # sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main(){
    string bookNo("001");
    double sales_price(100);
    size_t n = 10;
    double discount = 0.5;
    Quote q(bookNo,sales_price);
    Bulk_quote bq(bookNo,sales_price,n,discount);

    print_total(cout,q,20);
    q.debug();
    print_total(cout,bq,20);
    bq.debug();
    shared_ptr<Quote> p(new Quote(bookNo,sales_price));
    


}
