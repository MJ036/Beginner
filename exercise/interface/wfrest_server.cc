#include <mai.h>
#include <workflow/WFFacilities.h>
#include <wfrest/HttpServer.h>

static WFFacilities::WaitGroup gWaitGroup(1);

void handler(int signum){
    printf("signum = %d\n",signum);
    
}

using namespace std;

int main()
{

    return 0;
}

