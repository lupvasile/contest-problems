#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");

#ifndef ONLINE_JUDGE
#define cin fin
#endif // ONLINE_JUDGE

#define nmax 123460

vector<int> G[nmax];
bool on[nmax],spec[nmax];
int n,m,nr,dist[nmax];

bool dfs(int nod,int tata)
{
    if(spec[nod]) on[nod]=1;

    for(auto it:G[nod])
    {
        if(it==tata) continue;
        dist[it]=1+dist[nod];
        on[nod]=on[nod]|dfs(it,nod);
    }
    return on[nod];

}


int main()
{
    int x,y,i,nod,maxx=0;
    cin>>n>>m;

    for(i=1; i<n; ++i)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(i=1; i<=m; ++i)
    {
        cin>>x;
        spec[x]=1;
    }

    dfs(x,0);
    for(i=1; i<=n; ++i)
        if(on[i]) maxx=dist[maxx]<=dist[i] ? i:maxx;

    dist[maxx]=0;
    dfs(maxx,0);
    x=maxx;
    maxx=0;
    for(i=1; i<=n; ++i)
        if(on[i]) maxx=max(maxx,dist[i]);

    dist[x]=maxx;

    for(i=1; i<=n; ++i)
        if(on[i] && dist[i]==maxx)
        {
            cout<<i<<'\n';
            break;
        }
    for(i=1;i<=n;++i)
        nr+=on[i];
    cout<<2*(nr-1)-maxx;
    return 0;
}
