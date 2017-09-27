#include <bits/stdc++.h>

using namespace std;

ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");

#define cout g
#define nmax 2010
#define kmax 19
#define inf 0x3f3f3f3f
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,m,k,x,y,z,i,s,cod,cost,j;
int C[kmax];//localitatile pe care trebuie sa le viziteze
struct eee{
    int nod,cost;
    bool operator <(eee a) const
    {
        return cost>a.cost;
    }
    };
vector <eee> G[nmax];
priority_queue <eee> heap;
int dist[kmax][nmax];
int dist_s[nmax];
int dp[1<<16][16];
void dijkstra(int source,int *dist)
{
    int nod,cost;
    dist[source]=0;
    heap.push({source,0});
    while(!heap.empty())
    {
        nod=heap.top().nod;
        cost=heap.top().cost;
        heap.pop();
        foor(it,G[nod])
            if(cost+it->cost<dist[it->nod])
            {
                dist[it->nod]=cost+it->cost;
                heap.push({it->nod,dist[it->nod]});
            }
    }
}

int main()
{
    f>>n>>m>>k;
    memset(dist,inf,sizeof(dist));
    memset(dp,inf,sizeof(dp));
    memset(dist_s,inf,sizeof(dist_s));
    for(i=0;i<k;++i) f>>C[i];
    C[k]=n;
    ++k;
    for(i=1;i<=m;++i)
    {
        f>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    dijkstra(1,dist_s);
    for(i=0;i<k;++i)
        dijkstra(C[i],dist[i]);

    for(s=1;s<(1<<k);++s)
    {
        if((s&(s-1))==0)
        {
            for(i=0;(1<<i)<s;++i);
            dp[s][i]=dist_s[C[i]];
            continue;
        }
        for(i=0;i<k;++i)
            if(s&(1<<i))
        {
            cod=s-(1<<i);//starea din care vii
            for(j=0;j<k;++j)
                if((s&(1<<j)) && i!=j)
            {
                cost=dp[cod][j]+dist[j][C[i]];
                dp[s][i]=min(dp[s][i],cost);
            }
        }
    }
    cout<<dp[s-1][k-1];
    return 0;
}
