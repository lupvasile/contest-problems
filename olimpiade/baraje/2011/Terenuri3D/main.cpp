#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("terenuri3d.in");
ofstream fout("terenuri3d.out");
/// ////////////////////////////////

void read();

#define nmax 510
#define inf 0x3f3f3f3f

int source(0),sink(509),dummy(508),n,m;
int flux[nmax][nmax],cost[nmax][nmax],dist[nmax],P[nmax];
vector<pair<int,int>> sol;
vector<int> G[nmax];
queue<int> q;
bool inq[nmax];

bool bellman()
{
    int nod;
    memset(dist,inf,sizeof dist);

    dist[source]=0;
    q.push(source);

    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        inq[nod]=false;

        for(auto vec:G[nod])
            if(flux[nod][vec])
                if(dist[vec]>dist[nod]+cost[nod][vec])
                {
                    dist[vec]=dist[nod]+cost[nod][vec];
                    P[vec]=nod;

                    if(!inq[vec])
                    {
                        inq[vec]=true;
                        q.push(vec);
                    }
                }
    }

    return dist[sink]!=inf;
}

void make_flux()
{
    int nod,minn;

    while(bellman())
    {
        minn=inf;

        for(nod=sink; nod!=source; nod=P[nod]) minn=min(minn,flux[P[nod]][nod]);

        if(minn)
            for(nod=sink; nod!=source; nod=P[nod])
            {
                flux[P[nod]][nod]-=minn;
                flux[nod][P[nod]]+=minn;
            }
    }
}

int main()
{
    read();
    make_flux();

    int k=0;

    for(int i=1; i<=n; ++i)
        for(auto it:G[i])
            if(flux[it][i] && it!=dummy) sol.push_back({i,it-n}),k+=cost[it][i];

    cout<<k<<'\n'<<sol.size()<<'\n';
    for(auto it:sol)
        cout<<it.first<<' '<<it.second<<'\n';

    return 0;
}

void read()
{
    int x,y,c,k,i;

    fin>>n>>m>>k;
    for(; k; --k)
    {
        fin>>x>>y>>c;
        y+=n;
        flux[x][y]=1;
        cost[x][y]=-c;
        cost[y][x]=c;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(i=1; i<=n; ++i)
    {
        G[source].push_back(i);
        G[i].push_back(source);
        flux[source][i]=1;

        G[i].push_back(dummy);
        G[dummy].push_back(x);
        flux[i][dummy]=1;
    }

    for(i=n+1; i<=n+m; ++i)
    {
        G[i].push_back(sink);
        G[sink].push_back(i);
        flux[i][sink]=1;
    }

    G[sink].push_back(dummy);
    G[dummy].push_back(sink);
    flux[dummy][sink]=inf;
}
