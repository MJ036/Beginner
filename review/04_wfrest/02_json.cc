#include "mai.h"
#include <nlohmann/json.hpp>
using namespace std;

using Json = nlohmann::json;
int main(){
    Json sites1 = {
        {"sites", {
                {{"name","王道论坛"}, {"url","www.cskaoyan.com"}},
                     {{"name","google"}, {"url","www.google.com"}},
                {{"name","微博"}, {"url","www.weibo.com"}}
            }}
    };
    Json sites2;
    sites2["sites"].push_back({{"name","王道论坛"},{"url","www.cskaoyan.com"}});
    Json object;
    object["key1"] = "value";
    object["key2"] = 2;
      // 使用[]运算符可以增加键值对
      // 使用push_back方法可以增加数组元素
      std::cout << sites1.dump() << "\n";
      std::cout << sites2.dump() << "\n";
      std::cout << object.dump() << "\n";

return 0;
}

