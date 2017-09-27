#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define cout g
#define nmax 100010

ifstream f("heavymetal.in");
ofstream g("heavymetal.out");

struct element{int from,to;} v[nmax];
int n,i,j;
int best[nmax];

bool cmp(element a,element b)
{
    if(a.to!=b.to) return a.to<b.to;
    return a.from<b.from;
}

int search(int x)
{
    int st=0,dr=n,m;
    while (st<=dr)
    {
        m=(st+dr)/2;
        if(v[m].to<=x) st=m+1;
        else dr=m-1;
    }
    return dr;
}

int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>v[i].from>>v[i].to;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        j=search(v[i].from);
        best[i]=max(best[i-1],v[i].to-v[i].from+best[j]);
    }
    cout<<best[n];
    return 0;
}
