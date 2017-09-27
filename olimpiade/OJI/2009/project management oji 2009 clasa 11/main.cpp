#include <bits/stdc++.h>
using namespace std;

ifstream f("pm2.in");
ofstream g("pm2.out");

#define cout g
#define nmax 110
#define foor(it,v) for(__typeof(v.begin())it=v.begin();it!=v.end();++it)
#define inf 0x3f3f3f3f

int n,i,m,k,x,tmin;
int t[nmax],smin[nmax],smax[nmax];//start min
vector <int> G[nmax];

void dfsmin(int nod,int s)
{
    if(smin[nod]>s) return;
    smin[nod]=max(smin[nod],s);
    foor(it,G[nod]) dfsmin(*it,s+t[nod]);
    if(G[nod].size()==0)
        tmin=max(tmin,s+t[nod]);
}
void dfsmax(int nod)
{
    if(smax[nod]>0) return;
    smax[nod]=tmin-t[nod];
    foor(it,G[nod])
    {
        dfsmax(*it);
        smax[nod]=min(smax[nod],smax[*it]-t[nod]);
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>t[i];
    for(i=1;i<=n;++i)
    {
        f>>k;
        if(k==0) G[0].push_back(i);
        for(;k;--k)
        {
            f>>x;
            G[x].push_back(i);
        }
    }
    dfsmin(0,0);
    dfsmax(0);
    cout<<tmin<<'\n';
    for(i=1;i<=n;++i) cout<<smin[i]<<' '<<smax[i]<<'\n';
    return 0;
}
