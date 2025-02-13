#include "mai.h"
#include <iterator>
#include <memory>
#include <sys/socket.h>
using namespace std;

struct destination{
    string ip;
    int port;
    destination(string i, int p):ip(i),port(p){}
};
struct connection{
    string ip;
    int port;
    connection(string i, int p):ip(i),port(p){}
};
connection connect(destination* pDest){
    std::shared_ptr<connection> pConn(new connection(pDest->ip,pDest->port));
    cout << "createing connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection* pConn){
    cout << "connect close(" << pConn->ip << ":" << pConn->port << ")" << endl;
}
void end_connection(connection* pConn){
    disconnect(pConn);
}

void test_14(destination &d)
{
	connection conn = connect(&d);
	//std::shared_ptr<connection> p(&conn, end_connection);
    std::shared_ptr<connection> p(&conn,[](connection* p){disconnect(p);});
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}


int main()
{
    destination dest("100.100.100.100",10010);
    test_14(dest);
    return 0;
}

