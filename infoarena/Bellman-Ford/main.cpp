#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("bellmanford.in");
ofstream g("bellmanford.out");

#define nmax 50010
#define inf (1<<30)
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define cout g

int n,m,i,a,b,c,nod,vecin;
struct elem
    {
    int nod,cost;
    };
vector <elem> G[nmax];
int dist[nmax],ccount[nmax];
queue <int> Q;
bool in_queue[nmax],negative_cicle;

int main()
    {
    f>>n>>m;
    for(i=1; i<=m; ++i)
        {
        f>>a>>b>>c;
        G[a].push_back({b,c});
        }
    for(i=1; i<=n; ++i) dist[i]=inf;

    dist[1]=0;
    Q.push(1);
    while (!Q.empty() && !negative_cicle)
        {
        nod=Q.front();
        Q.pop();
        in_queue[nod]=false;
        foor(it,G[nod])
        if(dist[it->nod]>dist[nod]+(it->cost))
            {
            dist[it->nod]=dist[nod]+(it->cost);
            if(!in_queue[it->nod])
                {
                ccount[it->nod]++;
                if(ccount[it->nod]>n) negative_cicle=true;
                Q.push(it->nod);
                in_queue[it->nod]=true;
                }
            }
        }
    if(negative_cicle) cout<<"Ciclu negativ!\n";
    else for(i=2; i<=n; ++i) cout<<dist[i]<<' ';
    return 0;
    }
