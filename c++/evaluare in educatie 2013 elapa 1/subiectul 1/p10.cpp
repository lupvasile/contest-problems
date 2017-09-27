#include <iostream>

using namespace std;
int f(int x,int y)
{
    for(int i=x;i<=y;i++)
    if (i%7==0) return i;
    return 0;
}
int g(int x,int y)
{
    int nr(0);
    for(int i=x;i<=y;i++)
    if(i%7==0) nr++;
    return nr;
}
int main()
{ int a,b;
a=2;
b=200;
    cout<<(g(f(a,b),f(a,b))==1);
    return 0;
}
