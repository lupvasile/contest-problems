#include <bits/stdc++.h>

using namespace std;

ifstream f("graf.in");
ofstream g("graf.out");

#define cout g
#define nmax 7600
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define inf 0x3f3f3f3f

int n,m,start,finish,x,y,i,nr;
vector <int> G[nmax];
int ds[nmax],df[nmax],fr[nmax];
queue<int> q;
bool art[nmax],on[nmax];

void bfs(int a,int b,int d[])
    {
    int nod;
    for(int i=0; i<=n; ++i) d[i]=inf;
    d[a]=0;
    q.push(a);
    while(!q.empty())
        {
        nod=q.front();
        q.pop();
        foor(it,G[nod]) if(d[*it]==inf)
            {
            d[*it]=d[nod]+1;
            q.push(*it);
            }
        }
    }

int main()
    {
    f>>n>>m>>start>>finish;
    for(; m; --m)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    bfs(start,finish,ds);
    bfs(finish,start,df);

    for(i=1;i<=n;++i) if(ds[i]+df[i]==ds[finish]) ++fr[ds[i]],on[i]=true;
    for(i=1;i<=n;++i) if(fr[ds[i]]==1 && on[i]) art[i]=true;
    for(i=1;i<=n;++i) if(art[i])++nr;
    cout<<nr<<"\n";
    for(i=1;i<=n;++i) if(art[i]) cout<<i<<' ';
    return 0;
    }
