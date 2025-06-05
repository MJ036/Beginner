#include "DebugDelete.h"
#include "mai.h"
#include "Unique_ptr.h"
#include "Shared_ptr.h"
using namespace std;

int main()
{
    Unique_ptr<string> u_str(new string{"mai"});
    cout << *u_str << endl;
    
    my::Shared_ptr<string> s_str(new string{"jia"});
    cout << s_str.use_count() << endl;

    return 0;
}

