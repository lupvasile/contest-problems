#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//#define cout g
#define nmax 100010

ifstream f("2sat.in");
ofstream g("2sat.out");

int n,m,i,a,b,r,st,e1[2*nmax],e2[2*nmax];
vector <int> G[nmax*2];
bool x[2*nmax];
bool viz[2*nmax];
int stack[2*nmax];

#define G (G+nmax)
#define viz (viz+nmax)
#define foor(i,a,b) for(__typeof(a) i=a;i!=b;++i)
#define x (x+nmax)

void dfs(int nod)
{
    viz[nod]=true;
    foor(it,G[nod].begin(),G[nod].end())
    if (!viz[*it]) dfs(*it);
    stack[++st]=nod;
}

int main()
{
    f>>n>>m;
    for(i=1; i<=m; ++i)
    {
        f>>a>>b;
        G[-a].push_back(b);
        G[-b].push_back(a);

        e1[i]=a;
        e2[i]=b;
    }

    for(i=-n; i<=n; ++i)
        if(!viz[i]) dfs(i);

    for(; st; --st)
        if(!x[stack[st]] && !x[-stack[st]]) x[-stack[st]]=1;

    for(i=1; i<=m; ++i)

        if(!x[e1[i]] && !x[e2[i]])
        {
            cout<<-1;
            return 0;
        }

    for(i=1; i<=n; ++i) cout<<x[i]<<' ';
    return 0;
}
