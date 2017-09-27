#include <bits/stdc++.h>

using namespace std;

ifstream f("graph.in");
ofstream g("graph.out");

#define cout g
#define nmax 1501
#define inf 0x3f3f3f3f

int n,m,i,x,y,z,j;
vector <pair<int,int>> G[nmax];
bool viz[nmax];
int dist[nmax][nmax],st[nmax],gr[nmax],nod;
struct eee
    {
    int n,d;
    bool operator<(eee a) const
        {
        return d>a.d;
        }
    };
priority_queue<eee> q;
int gi();

int top_sort(int nod)
    {
    viz[nod]=true;
    for(auto vec:G[nod]) if(!viz[vec.first]) top_sort(vec.first);
    st[++st[0]]=nod;
    }

int main()
    {
    f>>n>>m;
    for(i=1; i<=m; ++i)
        {
        f>>x>>y>>z;
        G[x].push_back({y,z});
        ++gr[y];
        }
    for(i=1; i<=n; ++i) if(gr[i]==0) top_sort(i);
    for(i=n; i>=1; --i)
        {
        nod=st[i];
        for(j=1; j<=n; ++j) dist[nod][j]=inf;
        dist[nod][nod]=0;

        for(j=i; j>=1; --j)
            {
            if(dist[nod][st[j]]==inf) continue;
            for(auto vec:G[st[j]]) if(dist[nod][vec.first]>dist[nod][st[j]]+vec.second)
                    {
                    dist[nod][vec.first]=dist[nod][st[j]]+vec.second;
                    }
            }

        }
    for(i=1; i<=n; ++i)
        {

        for(x=1; x<=n; ++x) if(dist[i][x]!=inf) cout<<dist[i][x]<<' ';
            else cout<<"x ";
        cout<<'\n';
        }
    return 0;
    }
#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
    {
    int n(0),s(1);
    while(!(buf[pos]>='0' && buf[pos]<='9') && buf[pos]!='-') if(++pos>=maxb) f.read(buf,maxb),pos=0;
    if(buf[pos]=='-')
        {
        s=-1;
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    while((buf[pos]>='0' && buf[pos]<='9'))
        {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    return n*s;
    }
