#include "mai.h"
using namespace std;

int main(){
    try{
        //使用C++标准库
    }catch(bad_cast &e){
        cout << e.what();
        abort();   
    }catch(range_error &e){
        cout << e.what();
        abort();   
    }catch(underflow_error &e){
        cout << e.what();
        abort();   
    }catch(overflow_error &e){
        cout << e.what();
        abort();   

    }catch(runtime_error &e){
        cout << e.what();
        abort();   
    }catch(length_error &e){
        cout << e.what();
        abort();   
    }catch(out_of_range &e){
        cout << e.what();
        abort();   
    }catch(invalid_argument &e){
        cout << e.what();
        abort();   
    }catch(domain_error &e){
        cout << e.what();
        abort();   
    }catch(logic_error &e){
        cout << e.what();
        abort();   
    }catch(bad_alloc &e){
        cout << e.what();
        abort();   
    }
}

