#include "mai.h"
#include <nlohmann/json.hpp>

using namespace std;
using Json = nlohmann::json;

int main()
{
    Json sites;
    sites["sites"].push_back({"site",{"name","王道论坛"},{"url","www.kaoyan.com"}});
    sites["sites"].push_back({"site",{"name","google"},{"url","www.google.com"}});
    sites["sites"].push_back({"site",{"name","微博"},{"url","www.weibo.com"}});
    std::cerr << sites.dump() << "\n";
    return 0;
}

