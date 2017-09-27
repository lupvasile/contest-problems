#include <iostream>

using namespace std;
int v(int x)
{
    for(int i=1;i<=x;i++)
    cout<<i;
    return x+1;
}
int main()
{
v(v(v(1)));
    return 0;
}
