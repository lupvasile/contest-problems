#include <bits/stdc++.h>

using namespace std;

ifstream f("lanterna.in");
ofstream g("lanterna.out");

#define cout g
#define nmax 52
#define kmax 1010
#define inf 0x3f3f3f3f
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,st,dr,m,i,cmin,kmin,mid,rr;
int dist[nmax][kmax];
bool pr[nmax],inq[nmax][kmax];
struct
    {
    int a,b,t,w;
    } ed[1300];
vector <int> G[nmax];
struct eee
    {
    int nod,wram;
    };
queue <eee> q;

int bellman(int start,int finish,int k)
    {
    int i,nod,d,wram,vecin,j,nwram,r(inf);
    eee x;
    for(i=1; i<=n; ++i) for(j=0; j<=k; ++j) dist[i][j]=inf;
    dist[start][k]=0;
    q.push({start,k});
    while(!q.empty())
        {
        x=q.front();
        q.pop();
        inq[x.nod][x.wram]=false;
        if(pr[x.nod]) x.wram=k;
        foor(it,G[x.nod]) if((nwram=(x.wram-ed[*it].w))>=0)
            {
            vecin=(ed[*it].a==x.nod ? ed[*it].b:ed[*it].a);
            if(dist[vecin][nwram]>dist[x.nod][x.wram]+ed[*it].t)
                {
                dist[vecin][nwram]=dist[x.nod][x.wram]+ed[*it].t;
                if(pr[vecin]) dist[vecin][k]=min(dist[vecin][k],dist[vecin][nwram]);
                if(vecin==finish)
                    r=min(r,dist[vecin][nwram]);
                if(vecin==3)
                    {
                    int ggg=0;
                    }
                if(!inq[vecin][nwram]) q.push({vecin,nwram}),inq[vecin][nwram]=true;
                }
            }
        }
    return r;
    }

int main()
    {
    f>>n>>dr;
    for(i=1; i<=n; ++i) f>>pr[i];
    f>>m;
    for(i=1; i<=m; ++i)
        {
        f>>ed[i].a>>ed[i].b>>ed[i].t>>ed[i].w;
        if(ed[i].a>ed[i].b) swap(ed[i].a,ed[i].b);
        G[ed[i].a].push_back(i);
        G[ed[i].b].push_back(i);
        }
    cmin=bellman(1,n,dr);
    kmin=dr;
    st=1;
    while(st<=dr)
        {
        mid=(st+dr)/2;
        rr=bellman(1,n,mid);
        if(rr<=cmin)
            {
            cmin=rr;
            kmin=min(kmin,mid);
            dr=mid-1;
            }
        else st=mid+1;
        }
    cout<<cmin<<' '<<kmin;
    return 0;
    }
