#include <bits/stdc++.h>

using namespace std;

ifstream f("clepsidra.in");
ofstream g("clepsidra.out");

#define cout g
#define mod 666013
#define nmax 200013
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int m,n,x,y,i;
vector <int> G[nmax];
int up[nmax],lev[nmax],sol[nmax];
bool viz[nmax];

int poww(int a,int p)
{
    int res(1);
    for(;p;p>>=1)
    {
        if(p&1) res=1LL*res*a%mod;
        a=1LL*a*a%mod;
    }
    return res;
}

void dfs(int nod,int fat, int level)
    {
    int nr=0;
    up[nod]=level;
    lev[nod]=level;
    viz[nod]=true;

    foor(it,G[nod])
        {
        if(*it==fat) continue;
        if(!viz[*it])
            {
            dfs(*it,nod,level+1);
            if(up[*it]>=level) ++nr;
            up[nod]=min(up[nod],up[*it]);
            }
        else up[nod]=min(up[nod],lev[*it]);
        }
    if(nod==1) --nr;
    if(nr)
        {
        sol[nod]=poww(2,nr+1)-2;
        if(sol[nod]<0) sol[nod]+=mod;
        }
    }

int main()
    {
    f>>n>>m;
    for(; m; --m)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    dfs(1,0,1);
    for(i=1;i<=n;++i) cout<<sol[i]<<'\n';
    return 0;
    }
