#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("dbz.in");
ofstream fout("dbz.out");
/// ////////////////////////////////////////////////////////

#define nmax 1510

struct eee
{
    int nod,cost,tata;
    bool operator<(const eee &a) const
    {
        return cost>a.cost;
    }
};

#define inf 0x3f3f3f3f

vector <eee> G[nmax];
int n,m;
int dist[nmax],P[nmax],rez[nmax];
priority_queue <eee> q;

void dijkstra(int nod)
{
    eee top;

    memset(dist,inf,sizeof dist);
    dist[nod]=0;

    q.push({nod,0,0});
    P[nod]=0;

    while(!q.empty())
    {
        top=q.top();
        q.pop();
        if(dist[top.nod]!=top.cost) continue;

        for(auto vec:G[top.nod])
        {
            if(dist[vec.nod]>top.cost+vec.cost)
            {
                dist[vec.nod]=top.cost+vec.cost;
                if(top.tata==0) P[vec.nod]=vec.nod;
                else P[vec.nod]=top.tata;
                q.push({vec.nod,dist[vec.nod],P[vec.nod]});
            }
            if(top.nod==nod) continue;
            if(P[top.nod]!=top.nod)
            {
                if(P[vec.nod]!=P[top.nod]) rez[nod]=min(rez[nod],dist[vec.nod]+dist[top.nod]+vec.cost);
            }
            else if(vec.nod!=nod && P[vec.nod]!=P[top.nod]) rez[nod]=min(rez[nod],dist[vec.nod]+dist[top.nod]+vec.cost);
        }



    }
}

int main()
{
    int x,y,c,i;

    fin>>n>>m;
    for(; m; --m)
    {
        fin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }

    memset(rez,inf,sizeof rez);

    for(i=1; i<=n; ++i)
        dijkstra(i);

    for(i=1; i<=n; ++i) cout<<(rez[i]!=inf ? rez[i]:-1 )<<' ';

    return 0;
}
