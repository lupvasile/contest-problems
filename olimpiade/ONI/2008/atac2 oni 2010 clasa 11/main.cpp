#include <bits/stdc++.h>

using namespace std;

ifstream f("atac2.in");
ofstream g("atac2.out");

#define umax 143
#define inf 0x3f3f3f3f
#define cout g
int n,m,nr_trp,nr_oras,P,S,x,y,i,nod,j,cost_tot,cant;
int oras[umax>>1],trp[umax>>1],cap[umax][umax],flux[umax][umax],cost[umax][umax];
int dist[100001],fat[umax];
bool inq[umax];
vector<int> G[10001];
vector<int> G_flux[umax];
queue<int> q;

void read();
void build();
void bfs();

void bellman()
    {
    q.push(S);
    inq[S]=true;
    while(!q.empty())
        {
        nod=q.front();
        inq[nod]=false;
        q.pop();
        for(auto vec:G_flux[nod])
            if(cap[nod][vec]-flux[nod][vec]>0)
                if(dist[nod]+cost[nod][vec]<dist[vec])
                    {
                    dist[vec]=dist[nod]+cost[nod][vec];
                    fat[vec]=nod;
                    if(!inq[vec])
                        {
                        inq[vec]=true;
                        q.push(vec);
                        }
                    }
        }
    }

void det_cant(int nod)
    {
    if(fat[nod]) det_cant(fat[nod]);
    cant=min(cant,cap[fat[nod]][nod]-flux[fat[nod]][nod]);
    }
void add_flux(int nod)
    {
    if(fat[nod]) add_flux(fat[nod]);
    flux[fat[nod]][nod]+=cant;
    flux[nod][fat[nod]]-=cant;
    }
void det_flux()
    {
    while(1)
        {
        for(i=1; i<=P; ++i) dist[i]=inf,inq[i]=false;
        bellman();
        if(dist[P]==inf) break;
        cant=inf;
        det_cant(P);
        add_flux(P);
        cost_tot+=cant*dist[P];
        }
    }

int main()
    {
    read();
    build();
    //acuma in G_flux ai grafu de cuplaj
    det_flux();
    cout<<cost_tot;
    return 0;
    }

void bfs(int nod)
    {
    q.push(nod);
    dist[nod]=0;
    while(!q.empty())
        {
        nod=q.front();
        q.pop();
        for(auto vec:G[nod]) if(dist[nod]+1<dist[vec])
                {
                dist[vec]=dist[nod]+1;
                q.push(vec);
                }
        }
    }

void build()
    {
    S=0;
    P=nr_oras+nr_trp+1;

    for(i=1; i<=nr_trp; ++i)
        {
        G_flux[S].push_back(i);
        G_flux[i].push_back(S);
        cap[S][i]=1;
        }

    for(i=1; i<=nr_oras; ++i)
        {
        nod=nr_trp+i;
        G_flux[nod].push_back(P);
        G_flux[P].push_back(nod);
        cap[nod][P]=1;
        }

    for(i=1; i<=nr_trp; ++i)
        {
        for(j=1; j<=n; ++j) dist[j]=inf;
        bfs(trp[i]);
        for(j=1; j<=nr_oras; ++j)
            if(dist[oras[j]]!=inf)
                {
                nod=nr_trp+j;
                G_flux[i].push_back(nod);
                G_flux[nod].push_back(i);
                cost[i][nod]=dist[oras[j]];
                cost[nod][i]=-dist[oras[j]];
                cap[i][nod]=1;
                }
        }
    }
void read()
    {
    f>>n>>m>>nr_trp>>P;
    for(i=1; i<=nr_trp; ++i) f>>trp[i];
    for(; m; --m)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }

    ///0 sursa, 1..nr_trp trupe, nrtrp+1..nr_trp+nr_oras orase,nr_trp+nr_oras+1 scurgerea
    ///dai flux de la S la P

    for(auto x:G[P]) oras[++nr_oras]=x;

    }
