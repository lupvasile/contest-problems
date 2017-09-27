#include <bits/stdc++.h>

using namespace std;

ifstream f("darb.in");
ofstream g("darb.out");

#define cout g
#define nmax 100010

int n,i,x,y,lev_max,nod_max;
vector<int> G[nmax];
bool viz[nmax];

void dfs(int nod,int lev)
{
    viz[nod]=true;
    if(lev>lev_max) nod_max=nod,lev_max=lev;
    for(int i=0;i<G[nod].size();++i)
        if(!viz[G[nod][i]]) dfs(G[nod][i],lev+1);
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1,1);
    memset(viz,0,sizeof viz);
    lev_max=0;
    dfs(nod_max,1);
    cout<<lev_max;
    return 0;
}
