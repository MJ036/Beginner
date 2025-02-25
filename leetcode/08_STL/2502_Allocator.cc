#include "mai.h"
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <openssl/evp.h>
using namespace std;

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */

class Allocator {
public:
    Allocator(int n):_memory(n){};
    
    int allocate(int size, int mID) {
        size_t free = 0;
        for(size_t i = 0; i < _memory.size(); ++i){
            if(_memory[i] > 0){
                free = 0;
                continue;
            }
            ++free;
            if(free == size){
                fill(_memory.begin() + (i - size + 1), _memory.begin() + i + 1, mID);   
                return (i - size + 1);
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        size_t ret = 0;
        for(size_t i = 0; i < _memory.size(); ++i){
            if(_memory[i] == mID){
                ++ret;
                _memory[i] = 0;
            }
        }
        return ret;
    }
private:
    vector<int> _memory;
};

int main()
{

    return 0;
}

