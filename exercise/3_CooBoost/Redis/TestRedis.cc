#include "MyRedis.h"

using namespace std;

void test(){
    unique_ptr<MyRedis> pRedis(new MyRedis());
    if(!pRedis->connect("127.0.0.1",6379)){
        std::cerr << "connect error" << endl;
        return;
    }

    pRedis->set("name","买买买");
    cout << "Get the name is " << pRedis->get("name") << endl;
}

int main()
{
    test();
    return 0;
}

