#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream f("hamilton.in");
ofstream g("hamilton.out");

#define cout g
#define nmax 18
#define inf 0x3f3f3f3f
#define foor(it,v) for(__typeof (v.begin()) it=v.begin();it!=v.end();++it)

int n,m,x,y,i,sol;
vector <int> G[nmax];
int Cost[nmax][nmax];
int dist[1<<nmax][nmax];

int r_dist(int conf,int last)
    {
    if(dist[conf][last]!=-1) return dist[conf][last];
    dist[conf][last]=inf;
    foor(it,G[last])
    if(conf&(1<<(*it)))
    {
    if(*it==0 && conf!=(1<<last)+1) continue;
        dist[conf][last]=min(dist[conf][last],r_dist(conf^(1<<last),*it)+Cost[*it][last]);
        }
    return dist[conf][last];
    }

int main()
    {
    f>>n>>m;
    memset(Cost,inf,sizeof Cost);
    for(; m; --m)
        {
        f>>x>>y;
        G[y].push_back(x);
        f>>Cost[x][y];
        }
    memset(dist,-1,sizeof dist);
    dist[1][0]=0;
    sol=inf;
    foor(it,G[0]) sol=min(sol,r_dist((1<<n)-1,*it)+Cost[*it][0]);
    if(sol!=inf) cout<<sol;
    else cout<<"Nu exista solutie";
    return 0;
    }
