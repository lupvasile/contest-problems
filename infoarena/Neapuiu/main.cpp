#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("neapuiu.in");
ofstream fout("neapuiu.out");
/// ////////////////////////////////

void read();
void dfs(int);
void make_dads();
int lca(int,int);
#define nmax 200010

struct
{
    int tip,x,y;
} input[nmax];
vector<int> G[nmax];
int n,m,eul;
int from[nmax],to[nmax],dad[18][nmax],lev[nmax];
struct nod_aib{int nr_fii,p1,p2,maxx;} aib[nmax*4+2];

nod_aib combine(const nod_aib &a,const nod_aib &b)
{
    nod_aib res;


    if(a.maxx<b.maxx) res=b;
    if(a.maxx>b.maxx) res=a;
    if(a.maxx==b.maxx)
    {
        res.maxx=a.maxx;
        res.p1=a.p1;
        res.p2=b.p2;
    }
    res.nr_fii=a.nr_fii+b.nr_fii;

    return res;
}

void update(int nod,int st,int dr,int pos,int val,int nod_arbore)
{
    if(st==dr)
    {
        aib[nod]={1,nod_arbore,nod_arbore,val};
        if(aib[nod].maxx==0) aib[nod].nr_fii=0;
        return;
    }

    int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    if(pos<=mid) update(left,st,mid,pos,val,nod_arbore);
    else update(right,mid+1,dr,pos,val,nod_arbore);

    aib[nod]=combine(aib[left],aib[right]);

}

nod_aib query(int nod,int st,int dr,int x,int y)
{
    if(x<=st && dr<=y) return aib[nod];

    int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    if(y<=mid) return query(left,st,mid,x,y);
    else if(x>=mid+1) return query(right,mid+1,dr,x,y);
    else return combine(query(left,st,mid,x,y),query(right,mid+1,dr,x,y));
}

int raspuns(int nod)
{
    nod_aib n=query(1,1,eul,from[nod],to[nod]);
    int lc=lca(n.p1,n.p2);
    return (n.nr_fii-1) - (lev[lc] - lev[nod]);
}

void solve()
{
    int i;
    for(i=1;i<n;++i)
        if(input[i].tip==0) update(1,1,eul,from[input[i].y],lev[input[i].y],input[i].y);
        else if(input[i].tip==1) update(1,1,eul,from[input[i].x],0,input[i].x);
        else cout<<raspuns(input[i].x)<<'\n';
}

int main()
{
    read();
    lev[1]=1;
    dfs(1);
    make_dads();
    update(1,1,eul,1,1,1);
    solve();
    return 0;
}

void read()
{
    int i;
    fin>>n>>m;
    for(i=1; i<n; ++i)
    {
        fin>>input[i].x>>input[i].y;
        G[input[i].x].push_back(input[i].y);
    }

    n+=m;

    for(; i<n; ++i)
    {
        fin>>input[i].tip>>input[i].x;
        if(input[i].tip==0)
        {
            fin>>input[i].y;
            G[input[i].x].push_back(input[i].y);
        }
    }
}
void dfs(int nod)
{
    ++eul;
    from[nod]=eul;

    for(auto son:G[nod])
    {
        lev[son]=lev[nod]+1;
        dad[0][son]=nod;
        dfs(son);
    }

    to[nod]=eul;
}
int lca(int x,int y)
{
    if(lev[x]<lev[y]) swap(x,y);

    int diff=lev[x]-lev[y],k;

    for(k=0;(1<<k)<=diff;++k)
        if(diff&(1<<k)) x=dad[k][x];

    if(x==y) return x;

    for(k=0;dad[k][x];++k);
    for(;k>=0;--k)
        if(dad[k][x]!=dad[k][y]) x=dad[k][x],y=dad[k][y];

    return dad[0][x];
}
void make_dads()
{
    int k,i;
    for(int k=1;(1<<k)<n;++k)
        for(i=1;i<n;++i)
            dad[k][i]=dad[k-1][dad[k-1][i]];
}
