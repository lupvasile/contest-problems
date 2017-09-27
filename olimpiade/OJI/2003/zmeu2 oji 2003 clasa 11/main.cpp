#include <bits/stdc++.h>

using namespace std;

ifstream f("zmeu2.in");
ofstream g("zmeu2.out");

#define pmax 210
#define cout g
#define inf 0x3f3f3f3f

int n,k,p,x,y,i;
bool on[pmax][pmax];
int d[pmax],c[pmax],dist[pmax],dad[pmax];
struct eee{int nod,rem,cost;
bool operator<(eee x) const
{
    if(cost!=x.cost) return cost>x.cost;
    return rem<x.rem;
}
};
priority_queue <eee> q;

void dijkstra()
{
    int nod,rem,i,cost;
    memset(dist,inf,sizeof dist);
    dist[1]=d[1];
    q.push({1,n-c[1],d[1]});
    while(!q.empty())
    {
        nod=q.top().nod;
        rem=q.top().rem;
        cost=q.top().cost;
        q.pop();
        for(i=1;i<=p;++i) if(on[nod][i])
        if(rem-c[i]>0)
        {
            if(i==nod || i==p && nod==1) continue;
            dist[i]=min(dist[i],cost+d[i]);
            dad[i]=nod;
            q.push({i,rem-c[i],cost+d[i]});
            if(i==p)
            {
                cout<<dist[p];
                exit(0);
            }
        }
    }
    cout<<-1;
}
void afis(int nod)
{
    if(dad[nod]!=0) afis(dad[nod]);
    cout<<nod<<' ';
}
int main()
{
    f>>n>>p>>k;
    memset(on,1,sizeof(on));
    for(i=1;i<=p;++i) f>>d[i]>>c[i];
    for(;k;--k)
    {
        f>>x>>y;
        on[x][y]=false;
    }
    dijkstra();
   // afis(p);
    return 0;
}
