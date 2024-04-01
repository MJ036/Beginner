#include <iostream>

using namespace std;

class Data
{
public:
    Data(int data = 10)
        :_data(data)
    {
        cout << "Data(int = 10)" << endl;
    }
    
    int getData() const
    {
        return _data;
    }

    ~Data()
    {
        cout << "~Data()" << endl;
    }

private:
    int _data;
};

class SecondLayer
{
public:
    SecondLayer(Data *pdata)
        :_pdata(pdata)
    {
        cout << "SecondLayer(Data *)" << endl;
    }
    Data *operator->()
    {
        return _pdata;
    }

    Data &operator*()
    {
        return *_pdata;
    }

    ~SecondLayer()
    {
        cout << "~SecondLayer()" << endl;
        if(_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
    }

private:
    Data *_pdata;
};

class ThirdLayer
{
    public:
    ThirdLayer(SecondLayer *s1)
        :_s1(s1)
    {
        cout << "ThirdLayer(SecondLayer *)" << endl;
    }

    SecondLayer &operator->()
    {
        return *_s1;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if(_s1)
        {
            delete _s1;
            _s1 = nullptr;
        }
    }
private:
    SecondLayer *_s1;
};

void test()
{
    SecondLayer s1(new Data(10));
    //s1.operator->()->getData;
    cout << "s1->getData() = " << s1->getData() << endl;
    //s1.operator*().getData
    cout << "(*s1).getData() = " << (*s1).getData() << endl;

    ThirdLayer t1(new SecondLayer(new Data(20)));
    //t1.operator->().operator->()->getData();
    cout << "t1->getData() =" << t1->getData() << endl;
}

int main()
{
    test();
    return 0;
}

