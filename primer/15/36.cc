#include "mai.h"
#include "Query_base.h"
using namespace std;

//需要同 StrVec、Query的实现文件一起编译
int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << "ending\n";

    return 0;
}

