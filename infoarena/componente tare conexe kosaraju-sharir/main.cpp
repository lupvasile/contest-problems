#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define cout g
#define nmax 100010
ifstream f("ctc.in");
ofstream g("ctc.out");

vector <int> G[nmax], G_t[nmax],rez[nmax];
int stiva[nmax];
bool viz[nmax];
int n,m,i,st,r,x,y;

void dfs(int nod)
{
    viz[nod]=true;
    for(int i=0; i<G[nod].size(); ++i) if(!viz[G[nod][i]]) dfs(G[nod][i]);
    stiva[++st]=nod;

}

void dfs_t(int nod)
{
    viz[nod]=true;
    rez[r].push_back(nod);
    for(int i=0; i<G_t[nod].size(); ++i) if(!viz[G_t[nod][i]]) dfs_t(G_t[nod][i]);
}
int main()
{
    f>>n>>m;
    for(; m; --m)
    {
        f>>x>>y;
        G[x].push_back(y);
        G_t[y].push_back(x);
    }
    for(i=1; i<=n; ++i)
        if(!viz[i]) dfs(i);

    for(i=1; i<=n; ++i) viz[i]=false;

    for(; st; --st)
    {
        if(!viz[stiva[st]])
        {
            ++r;
            dfs_t(stiva[st]);
        }
    }
    cout<<r<<'\n';
    for(; r; --r)
    {
        for(i=0; i<rez[r].size(); ++i) cout<<rez[r][i]<<' ';
        cout<<'\n';
    }
    return 0;
}
