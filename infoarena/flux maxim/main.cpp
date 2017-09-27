#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("maxflow.in");
ofstream g("maxflow.out");

#define cout g
#define nmax 1010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define inf 120000

int n,m,i,x,y,z,flow;
int minn;
int C[nmax][nmax],Flow[nmax][nmax],P[nmax];
vector <int> G[nmax];
bool viz[nmax];
queue <int> q;

bool bfs()
{
    int i,nod;
    for(i=1; i<=n; ++i) viz[i]=0;
    q.push(1);
    while (!q.empty())
    {
        nod=q.front();
        q.pop();
        foor(it,G[nod])
        {
            if(viz[*it] || Flow[nod][*it]==C[nod][*it]) continue;
            viz[*it]=1;
            if(*it==n) continue;
            q.push(*it);
            P[*it]=nod;

        }
    }
    return viz[n];
}

int main()
{
    f>>n>>m;
    for(; m; --m)
    {
        f>>x>>y>>z;
        C[x][y]=z;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    while (bfs())
    {
        foor(nod,G[n])
        {
            if(Flow[*nod][n]==C[*nod][n] || !viz[*nod]) continue;

            minn=inf;
            P[n]=*nod;
            for(x=n; x!=1; x=P[x])
            {
                minn=min(minn,C[P[x]][x]-Flow[P[x]][x]);///det cant cu care poti mari fluxu
            }

            for(x=n; x!=1; x=P[x])
            {
                Flow[P[x]][x]+=minn;
                Flow[x][P[x]]-=minn;
            }

            flow+=minn;
        }
    }

    cout<<flow;
    return 0;
}
