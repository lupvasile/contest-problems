#include <bits/stdc++.h>

using namespace std;

ifstream f("pamant.in");
ofstream g("pamant.out");

#define cout g
#define nmax 100001

vector <int> G[nmax];
int n,m,i,j,x,y,nr;
int level[nmax],up[nmax],cod[nmax];
bool viz[nmax],vul[nmax];

void dfs(int nod,int lev)
{
    viz[nod]=true;
    up[nod]=level[nod]=lev;
    int x=0;
    for(auto it:G[nod])
        if(!viz[it])
    {
        dfs(it,lev+1);
        ++x;
        up[nod]=min(up[nod],up[it]);
        if(up[it]>=lev) vul[nod]=true;
    }
    else up[nod]=min(up[nod],level[it]);

    if(lev==1) if(x==1) vul[nod]=false;
}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(i=1;i<=n;++i) if(!viz[i]) cod[++nr]=i,dfs(i,1);
    cout<<nr<<'\n';
    for(i=1;i<=nr;++i) cout<<cod[i]<<' ';
    cout<<'\n';
    nr=0;
    for(i=1;i<=n;++i) if(vul[i]) ++nr;
    cout<<nr<<'\n';
    for(i=1;i<=n;++i) if(vul[i]) cout<<i<<' ';
    return 0;
}
