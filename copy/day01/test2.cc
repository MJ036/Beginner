#include <iostream>

using namespace std;
void test(){
    int a[5]={1,2,3,4,5};
int *ptr=(int *)(&a+1);
printf("%d,%d",*(a+1),*(ptr-1));
}
int main()
{
    test();
    return 0;
}

