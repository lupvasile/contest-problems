#include <iostream>

using namespace std;
void f(int &x)
{
    x=1<<1<<1<<1;
}
int main()
{
    int x=0;
    f(x);
    cout<<x;
    return 0;
}