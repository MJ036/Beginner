#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::allocator;

template<class T>
class Vector{
public:
    using iterator = T *;
    iterator begin(){
        return _start;
    }

    iterator end(){
        return _finish;
    }

    Vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr){}

    ~Vector();

    void push_back(const T &);
    void pop_back();

    int size() const;
    int capacity() const;
private:
    void reallocate();
private:
    static std::allocator<T> _alloc;

    T *_start;
    T *_finish;
    T *_end_of_storage;
};

template <class T>
std::allocator<T> Vector<T>::_alloc;

template <class T>
Vector<T>::~Vector(){
    if(_start){
        while(_start != _finish){
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start,capacity());
    }
}

template <class T>
void Vector<T>::push_back(const T & value){
    if(size() == capacity()){
        reallocate();
    }
    if(size() < capacity()){
        _alloc.construct(_finish++,value);
    }
}

template <class T>
void Vector<T>::pop_back(){
    if(size() > 0){
        _alloc.destroy(--_finish);
    }
}


template <class T>
int Vector<T>::size() const{
    return _finish - _start;
}

template <class T>
int Vector<T>::capacity() const{
    return _end_of_storage - _start;
}

template <class T>
void Vector<T>::reallocate(){
    int oldCapacity = capacity();
    int newCapacity = oldCapacity > 0 ? 2 * oldCapacity : 1;
    T *ptemp = _alloc.allocate(newCapacity);

    if(_start){
        std::uninitialized_copy(_start,_finish,ptemp);
        while(_start != _finish){
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start,oldCapacity);
    }
    _start = ptemp;
    _finish = ptemp + oldCapacity;
    _end_of_storage = ptemp + newCapacity;
}

void printCapacity(const Vector<int> &con){
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test(){
    Vector<int> vec;
    printCapacity(vec);
    cout << endl;

    cout << endl;
    vec.push_back(1);
    printCapacity(vec);

        cout << endl;
    vec.push_back(2);
    printCapacity(vec);

        cout << endl;
    vec.push_back(3);
    printCapacity(vec);

    cout << endl;
    vec.push_back(4);
    printCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printCapacity(vec);

    for(auto &elem : vec)
    {
        cout << elem << "  ";
    }
    cout << endl;

}

int main()
{
    test();
    return 0;
}

