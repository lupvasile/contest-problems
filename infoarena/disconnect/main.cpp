#include <bits/stdc++.h>

using namespace std;

ifstream fin("disconnect.in");
ofstream fout("disconnect.out");

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

#define nmax 100010

int n,m,V;
vector<int> G[nmax];
int lev[nmax],aib[nmax<<1],first[nmax],last[nmax];
int P[20][nmax];
///in aib[0] ai lungimea aibului
///in first si last ai prima si ultima aparitie a unui nod in aib

void infinit()
{
    while(1);
}

void dfs(int nod,int level)
    {
    lev[nod]=level;
    first[nod]=++aib[0];

    for(auto it:G[nod])
        if(lev[it]==0)
            {
            P[0][it]=nod;
            dfs(it,level+1);
            }

    last[nod]=++aib[0];

    }

void update_aib(int pos,int val)
    {
    for(; pos<=aib[0]; pos+=(pos&(-pos))) aib[pos]+=val;
    }

int query(int pos)
    {
    int res=0;
    for(; pos; pos-=(pos&(-pos))) res+=aib[pos];
    return res;
    }

int get_lca(int x,int y)
    {
    if(lev[x]>lev[y]) swap(x,y);
    int diff=lev[y]-lev[x],k;

    for(k=0; (1<<k)<=diff; ++k)
        if(diff&(1<<k)) y=P[k][y];

    if(x==y) return x;

    for(k=0; (1<<k)<=n; ++k);
    for(; k; --k)
        if(P[k][x]!=P[k][y] && P[k][x] && P[k][y])
            {
            x=P[k][x];
            y=P[k][y];
            }
    return P[0][x];
    }

void citire();

bool connencted(int x,int y)
{
    int lca=get_lca(x,y);
    return (query(first[x])-query(first[lca])==lev[x]-lev[lca]) && (query(first[y])-query(first[lca])==lev[y]-lev[lca]);
}

int main()
    {
    int tip,x,y;

    citire();
    return 0;
    for(;m; --m)
        {
        fin>>tip>>x>>y;

        x^=V;
        y^=V;

        if(tip==1)
            {
            if(lev[x]>lev[y]) swap(x,y);
            update_aib(first[y],-1);
            update_aib(last[y],1);
            }
        else
            {
            if(connencted(x,y))
                {
                cout << "YES\n";
                V = x;
                }
            else
                {
                cout << "NO\n";
                V = y;
                }

            }
        }

    return 0;
    }


void citire()
    {
    int i,x,y,k;

    fin>>n>>m;
    //fin>>n;
    for(i=1; i<n; ++i)
        {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }

    dfs(1,1);

    for(i=1; i<=n; ++i)
        {
        update_aib(first[i],1);
        update_aib(last[i],-1);
        }

    for(k=1; (1<<k)<=n; ++k)
        for(i=1; i<=n; ++i)
            P[k][i]=P[k-1][P[k-1][i]];

    for(i=2;i<=n;++i) if(P[0][i]==0) infinit();

    }
