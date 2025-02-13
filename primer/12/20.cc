#include "mai.h"
#include "StrBlob.h"
#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
    StrBlob my_blob;
    ifstream ifs("input_file");
    string line;
    while(getline(ifs,line)){
        my_blob.push_back(line);
    }
    StrBlobPtr p_blob = my_blob.begin();
    while(p_blob != my_blob.end()){
        cout << p_blob.deref() << endl;
        p_blob.incr();
    }
    cout << endl;

    return 0;
}

