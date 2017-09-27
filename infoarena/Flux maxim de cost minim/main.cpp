#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("fmcm.in");
ofstream g("fmcm.out");

#define cout g
#define nmax 355
#define inf 0x3f3f3f3f
#define foor(a,b) for(__typeof(b.begin()) a=b.begin();a!=b.end();++a)

int n,m,source,dest,cost_min,minn,nod;
int cap[nmax][nmax],cost[nmax][nmax],flux[nmax][nmax];
int from[nmax],dist[nmax];
vector <int> G[nmax];
bool in_queue[nmax];

void read();

bool bellman_ford()
    {
    queue <int> q;
    int i,nod;
    for(i=1; i<=n; ++i) dist[i]=inf,in_queue[i]=false;
    dist[source]=0;
    q.push(source);

    while (!q.empty())
        {
        nod=q.front();
        q.pop();
        in_queue[nod]=false;

        foor(it,G[nod])
        if(dist[*it]>dist[nod]+cost[nod][*it] && cap[nod][*it]-flux[nod][*it]!=0)
            {
            dist[*it]=dist[nod]+cost[nod][*it];
            from[*it]=nod;
            if(!in_queue[*it])
                {
                in_queue[*it]=true;
                q.push(*it);
                }
            }
        }

    if(dist[dest]==inf) return false;

    return true;


    }

int main()
    {
    read();
    while(bellman_ford())
        {
        minn=inf;
        for(nod=dest; nod!=source; nod=from[nod]) minn=min(minn,cap[from[nod]][nod]-flux[from[nod]][nod]);
        for(nod=dest; nod!=source; nod=from[nod])
            {
            flux[from[nod]][nod]+=minn;
            flux[nod][from[nod]]-=minn;
            }
        cost_min+=minn*dist[dest];
        }
    cout<<cost_min;
    return 0;
    }

#define mb 100000
char b[mb];
int p(mb);

int gi()
    {
    int n(0),semn;
    while((b[p]<'0' || b[p]>'9') && b[p]!='-') if(++p>=mb) f.read(b,mb),p=0;
    if(b[p]=='-')
        {
        semn=-1;
        if(++p>=mb) f.read(b,mb),p=0;
        }
    else semn=1;
    while(b[p]>='0' && b[p]<='9')
        {
        n=n*10+b[p]-'0';
        if(++p>=mb) f.read(b,mb),p=0;
        }
    return semn*n;
    }

void read()
    {
    int i,a,b,c,z;
    n=gi(),m=gi(),source=gi(),dest=gi();
    for(i=1; i<=m; ++i)
        {
        a=gi(),b=gi(),c=gi(),z=gi();

        G[a].push_back(b);
        G[b].push_back(a);

        cost[a][b]=z;
        cap[a][b]=c;

        cost[b][a]=-z;
        }

    }
