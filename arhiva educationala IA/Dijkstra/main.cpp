#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
/// ////////////////////////////////

#define nmax 50010
#define inf 0x3f3f3f3f

struct eee
{
    int nod,cost;
    bool operator < (const eee &a) const
    {
        return cost>a.cost;
    }
};
vector<eee> G[nmax];
priority_queue<eee> q;
int dist[nmax],n;

void dijkstra(int start)
{
    int nod,cost;
    dist[start]=0;
    q.push({start,0});

    while(!q.empty())
    {
        nod=q.top().nod;
        cost=q.top().cost;
        q.pop();
        if(cost!=dist[nod]) continue;
        for(auto son:G[nod])
            if(cost+son.cost<dist[son.nod])
            {
                dist[son.nod]=cost+son.cost;
                q.push({son.nod,dist[son.nod]});
            }
    }
}
void read();
int main()
{
    read();
    dijkstra(1);

    for(int i=2;i<=n;++i) cout<<(dist[i]!=inf ? dist[i]:0)<<' ';
    return 0;
}

void read()
{
    int x,y,c,m;
    fin>>n>>m;
    for(; m; --m)
    {
        fin>>x>>y>>c;
        G[x].push_back({y,c});
    }

    memset(dist,inf,sizeof dist);
}
