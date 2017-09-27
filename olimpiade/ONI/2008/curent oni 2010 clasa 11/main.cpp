#include <bits/stdc++.h>

using namespace std;

ifstream f("curent.in");
ofstream g("curent.out");

#define nmax 100026
#define cout g
vector<int> G[nmax];
int from[nmax],to[nmax],arb[4*nmax],fire[4*nmax];
struct eee
    {
    int zi,casa,tip;
    void read()
        {
        f>>zi>>casa>>tip;
        }
    bool operator <(eee a) const
        {
        return zi<a.zi;
        }
    } ev[nmax];
int n,m,i,x,t;

void dfs(int nod)
    {
    from[nod]=++from[0];
    for(auto vec:G[nod]) dfs(vec);
    to[nod]=from[0];
    }

void build(int nod,int st,int dr)
    {
    if(st==dr)
        {
        arb[nod]=1;
        return;
        }

    int mid=(st+dr)>>1;
    int left=nod<<1,right=nod<<1|1;

    build(left,st,mid);
    build(right,mid+1,dr);

    arb[nod]=arb[left]+arb[right];
    }

void update(int nod,int st,int dr,int x,int y,int tip)
    {
    int mid=(st+dr)>>1;
    int left=nod<<1,right=nod<<1|1;

    if(x<=st && dr<=y)
        {
        if(tip==0) ++fire[nod];
        else --fire[nod];

        if(st<dr)
            if(fire[nod]==0) arb[nod]=arb[left]+arb[right];
                else arb[nod]=0;

        else
            if(fire[nod]==0) arb[nod]=1;
                else arb[nod]=0;
        return;
        }


    if(x<=mid) update(left,st,mid,x,y,tip);
    if(y>mid) update(right,mid+1,dr,x,y,tip);
    if(fire[nod]==0) arb[nod]=arb[left]+arb[right];
    else arb[nod]=0;
    }

int main()
    {
    f>>n;
    for(i=2; i<=n; ++i)
        {
        f>>x;
        G[x].push_back(i);
        }

    dfs(1);
    build(1,1,n);
    f>>m;
    for(i=1; i<=m; ++i) ev[i].read();
    sort(ev+1,ev+m+1);
    f>>t;
    i=1;
    for(; t; --t)
        {
        f>>x;
        while(i<=m && ev[i].zi<=x)
            {
            update(1,1,n,from[ev[i].casa],to[ev[i].casa],ev[i].tip);
            ++i;
            }
        cout<<arb[1]<<'\n';
        }
    return 0;
    }
