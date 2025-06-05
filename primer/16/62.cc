#include "mai.h"
#include "hash.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
    unordered_multiset<Sales_data> u_mset;
    u_mset.insert(Sales_data("001",20,30));
    for(auto m : u_mset){
        cout << m << endl;
    }
}
