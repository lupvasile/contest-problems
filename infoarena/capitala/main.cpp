#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("capitala.in");
ofstream g("capitala.out");

#define cout g
#define nmax 200010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,i,x,y,dmin(1<<30),rasp;
bool viz[nmax];
vector <int> G[nmax];
int dist[nmax];
int nr[nmax];

void dfs1(int nod,int d)//face dist de la 1 pana la celelalte noduri
{
    viz[nod]=true;
    dist[1]+=d;
    foor(it,G[nod]) if(!viz[*it])
    {
        dfs1(*it,d+1);
        nr[nod]+=1+nr[*it];
    }
}
void dfs2(int nod,int tata)
{
    viz[nod]=false;
    if(nod>1)dist[nod]=dist[tata]+n-1LL*2*(nr[nod]+1);
    foor(it,G[nod]) if(viz[*it]) dfs2(*it,nod);
}
int main()
{
    f>>n;
    for(i=1;i<n;++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(i=1;i<=n;++i) if (dist[i]<dmin)
    {
        dmin=dist[i];
        rasp=i;
        //cout<<dist[i]<<' ';
    }
    cout<<rasp<<' '<<dmin<<'\n';
    return 0;
}
