#include <bits/stdc++.h>

using namespace std;

#define cout g
#define nmax 21001
#define inf 0x3f3f3f3f

ifstream f("amici2.in");
ofstream g("amici2.out");

queue<int>q;
vector <int> G[nmax],dist;
vector<bool> viz;
int n,m,t,i,x,y,dmax,res;

void bfs(int start)
{
    int nod;
    dmax=0;
    viz.assign(n+1,0);
    dist.assign(n+1,inf);
    dist[start]=0;
    q.push(start);
    viz[start]=1;
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(auto it:G[nod])
            if(!viz[it])
        {
            dist[it]=1+dist[nod];
            q.push(it);
            dmax=max(dmax,dist[it]);
            viz[it]=true;
        }
    }
}


int main()
{
f>>t;
viz.resize(nmax);
dist.resize(nmax);
for(;t;--t)
{
    f>>n>>m;
    for(;m;--m)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs(1);
    res=1;
    for(i=1;i<dmax;i<<=1) ++res;
    cout<<res<<'\n';
    for(i=1;i<=n;++i) G[i].clear();
}
    return 0;
}
