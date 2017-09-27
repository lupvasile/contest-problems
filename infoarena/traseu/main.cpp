#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("traseu.in");
ofstream g("traseu.out");

#define cout g
#define nmax 65
#define inf (1<<29)
#define foor(a,b) for(__typeof(b.begin()) a=b.begin();a!=b.end();++a)

int n,m,i,a,b,c,res;
int dist[nmax],in[nmax],out[nmax],cap[nmax][nmax],cost[nmax][nmax],flux[nmax][nmax],pre[nmax];
vector <int> G[nmax],G_f[nmax];
bool inq[nmax];

void roy_floyd();

bool bellman_f()
    {
    int i,nod;
    queue<int> q;
    for(i=1; i<=n+1; ++i) dist[i]=inf,inq[i]=false;
    dist[0]=0;
    q.push(0);
    while (!q.empty())
        {
        nod=q.front();
        inq[nod]=false;
        q.pop();
        foor(it,G_f[nod])
         if(dist[*it]>dist[nod]+cost[nod][*it] && cap[nod][*it]-flux[nod][*it]!=0)
                {
                dist[*it]=dist[nod]+cost[nod][*it];
                pre[*it]=nod;
                if(!inq[*it])
                    {
                    inq[*it]=true;
                    q.push(*it);
                    }
                }
        }

    if(dist[n+1]==inf) return 0;
return 1;
    }

int flux_min()
    {
    int fflux=0,minn,nod;
    while(bellman_f())
        {
            minn=inf;
            for(nod=n+1;nod!=0;nod=pre[nod]) minn=min(minn,cap[pre[nod]][nod]-flux[pre[nod]][nod]);
             for(nod=n+1;nod!=0;nod=pre[nod])
             {
                 flux[pre[nod]][nod]+=minn;
                 flux[nod][pre[nod]]-=minn;
             }
             fflux+=minn*dist[n+1];
        }
    return fflux;
    }

int main()
    {
    f>>n>>m;

    for(i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i!=j) cost[i][j]=inf;

    for(i=1; i<=m; ++i)
        {
        f>>a>>b>>c;
        G[a].push_back(b);
        cost[a][b]=c;
        in[b]++;
        out[a]++;
        res+=c;
        }
    roy_floyd();
    for(i=1; i<=n; ++i)
        {
        if(in[i]>out[i])
            {
            G_f[0].push_back(i);
            G_f[i].push_back(0);
            cap[0][i]=in[i]-out[i];
            }
        if(in[i]<out[i])
            {
            G_f[n+1].push_back(i);
            G_f[i].push_back(n+1);
            cap[i][n+1]=out[i]-in[i];
            }
        }



    foor(it,G_f[0])
    foor(itt,G_f[n+1])
        {
        G_f[*it].push_back(*itt);
        G_f[*itt].push_back(*it);
        cap[*it][*itt]=inf;
        cost[*itt][*it]=-cost[*it][*itt];
        }

    cout<<res+flux_min();
    return 0;
    }

void roy_floyd()
    {
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                    if(cost[i][k]+cost[k][j]<cost[i][j]) cost[i][j]=cost[i][k]+cost[k][j];
    }
