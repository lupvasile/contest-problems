#include <iostream>

using namespace std;
int f(int x)
{
    int i,E=0;
    for(i=1;i<=x;i++)
    {
        if(i%2==0)continue;
        E=E+1;
    }
    return E;
}
int main()
{
cout<<f(20);
    return 0;
}
