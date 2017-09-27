#include <iostream>
#include <fstream>
using namespace std;
int n,level[15000],aibx[32002],i,x,y;
int calc(long long pos)
{
    long long x(0);
    while (pos>0)
    {
        x+=aibx[pos];
        pos-=(pos^(pos-1)&pos);
    }
    return x;
}
void adauga(long long pos)
{
    while (pos<=32001)
    {
        aibx[pos]++;
        pos+=(pos^(pos-1)&pos);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        level[calc(x+1)]++;
        adauga(x+1);
    }
    for(i=0;i<=n-1;i++) cout<<level[i]<<'\n';
    return 0;
}
