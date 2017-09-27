#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("inv.in");
ofstream g("inv.out");
int v[100010],v2[100010],n,i,aib[100010],nr;
int binsrc(int val)
    {
    int step(1),i;
    while(step<n) step=step<<1;
    i=0;
    while(step)
        {
        if(i+step<=n && v2[i+step]<=val) i+=step;
        step=step>>1;
        }
    return i;
    }
void adauga(int pos)
    {
    while (pos<=n)
        {
        aib[pos]+=1;
        pos+=(pos^(pos-1)&pos);
        }
    }
int calc(int pos)
    {
    int x(0);
    while(pos>0)
        {
        x+=aib[pos];
        pos-=(pos^(pos-1)&pos);
        }
    return x;
    }
int main()
    {
    f>>n;
    for(i=1; i<=n; i++)
        {
        f>>v[i];
        v2[i]=v[i];
        }
    sort(v2+1,v2+n+1);
    for(i=n; i>0; i--)
        {
        v[i]=binsrc(v[i]);
        nr+=calc(v[i]-1);
        adauga(v[i]);
        }
    //for(i=1;i<=n;i++)cout<<v[i];
    g<<(nr%9917);
    return 0;
    }