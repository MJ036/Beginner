#include "mai.h"
#include <memory>
using namespace std;

class Quote{
    friend bool operator !=(const Quote& lhs, const Quote& rhs);

public:
    Quote(){
        cout << "Quote()\n";
    };

    Quote(const Quote& rhs):_bookNo(rhs._bookNo),_price(rhs._price){
        cout << "Quote(Quote&)\n";
    }

    Quote(Quote&& rhs)noexcept :_price(std::move(rhs._price)),_bookNo(std::move(rhs._bookNo)){
        cout << "Quote(Quote &&)\n";
    }

    Quote(const string bookNo, double sales_price)
        :_bookNo(bookNo)
         ,_price(sales_price)
    {
        cout << "Quote(string,double)\n";
    }


    Quote& operator=(const Quote& rhs){
        if(*this != rhs){
            cout << "operator=(Quote&)\n";
            _bookNo = rhs._bookNo;
            _price = rhs._price;

        }
        return *this;
    }

    Quote& operator=(Quote && rhs){
            cout << "operator=(Quote&&)\n";
        _bookNo = std::move(rhs._bookNo);
        _price = std::move(rhs._price);
        return *this;
    }

    string isbn() const {return _bookNo;}

    virtual Quote* clone()const &{
        return new Quote(*this);
    }

    virtual double net_price(size_t n) const {
        return n * _price;
    }

    virtual void debug(){
        cout << "_bookNo: " << _bookNo << "\n"
            << "_price:"  << _price << "\n";
    }

    virtual ~Quote(){
        cout << "~Quote()\n";

    };

private:
    string _bookNo;
protected:
    double _price;
};
    bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
    return lhs._bookNo != rhs._bookNo
        &&
        lhs._price != rhs._price;
}

class Disc_quote
:public Quote
{
public:
    Disc_quote(){
        cout << "Disc_quote()\n";
    };
    Disc_quote(Disc_quote& rhs):Quote(rhs),_quantity(rhs._quantity),_discount(rhs._discount){
        cout <<"Disc_quote(Disc_quote&)\n";
    }
    Disc_quote(Disc_quote&& rhs)noexcept:Quote(std::move(rhs)),_quantity(std::move(rhs._quantity)),_discount(std::move(rhs._discount)){
        cout <<"Disc_quote(Disc_quote&&)\n";

    }
    Disc_quote(const string bookNo, double sales_price,size_t cnt,double discount)
        :Quote(bookNo,sales_price)
         ,_quantity(cnt)
         ,_discount(discount)
    {}

    Disc_quote& operator=(Disc_quote& rhs){
        Quote::operator=(rhs);
        _quantity = rhs._quantity;
        _discount = rhs._discount;
        cout << "operator=(Disc_quote&)\n";
        return *this;
    }

    Disc_quote& operator=(Disc_quote&& rhs)noexcept{
        Quote::operator=(std::move(rhs));
        cout << "operator=(Disc_quote &&)\n";
        return *this;
    }

    ~Disc_quote(){
        cout << "~Disc_quote\n";
    }




    double net_price(size_t cnt)const =0;

private:
    size_t _quantity = 0;
    double _discount = 0.0;


};

class Bulk_quote
:public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string bookNo, double sales_price,size_t cnt,double discount)
        :Disc_quote(bookNo,sales_price,cnt,discount)
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

class Basket{
public:
    void add_item(const Quote &sale){
        _items.insert(shared_ptr<Quote>(sale.clone()));
    }

    double total_receipt(ostream &os){
        double sum = 0;
        for(auto it = _items.cbegin() ; it != _items.cend(); it = _items.upper_bound(*it)){
            sum += print_total(os,**it,_items.count(*it));
        }
        os << "Total Sale: " << sum << endl; 
        return sum;
    }

private:
    static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs){
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>,decltype(compare)*> _items{compare};
};

void test1(){
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

void test_26(){
    Bulk_quote d;
    Bulk_quote d1(std::move(d));
}

void test_30(){
    Basket bskt;
    bskt.add_item(Quote("001",10));
    bskt.add_item(Quote("001",20));
    bskt.total_receipt(cout);
    
}

int main(){
    test_30();
    return 0;
}
