#include <bits/stdc++.h>

using namespace std;

ifstream f("fotbal2.in");
ofstream g("fotbal2.out");
#define nmax 200002
#define cout g
vector<pair<int,int>> G[nmax];
bool on[nmax],viz[nmax];
int n,m,i,x,y,h,diff;
int win[nmax],gr[nmax];
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
void euler(int nod)
{
    viz[nod]=true;
    foor(vec,G[nod])
        if(on[vec->second])
    {
        on[vec->second]=false;
        euler(vec->first);
        win[vec->second]=nod;
    }

}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>x>>y;
        G[x].push_back({y,i});
        G[y].push_back({x,i});
        ++gr[x];
        ++gr[y];
        on[i]=true;
    }
    h=m;
    for(i=1;i<=n;++i) if(gr[i]&1)
    {
        diff=2;
        G[0].push_back({i,++h});
        G[i].push_back({0,h});
        on[h]=true;
    }

    for(i=0;i<=n;++i) if(!viz[i]) euler(i);

    cout<<diff<<'\n';
    for(i=1;i<=m;++i) cout<<win[i]<<'\n';
    return 0;
}
