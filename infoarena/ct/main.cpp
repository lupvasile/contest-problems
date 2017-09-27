#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

ifstream f("ct.in");
ofstream g("ct.out");

#define cout g
#define nmax 300010
#define foor(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)

int n,k,nr_orase_distruse;
vector <int> G[nmax],lca_l;
struct element
    {
    int l1,l2;
    };
vector <element> ac[nmax];//ac[i] lista oraselor la  care lca ii i
int level[nmax];
bool del[nmax];
int P[222][nmax];
int lg[nmax];
int fat[nmax];

void dfs(int nod,int lev,int father)
    {
    fat[nod]=father;
    level[nod]=lev;
    foor(it,G[nod])
        {
        if(*it!=father) dfs(*it,lev+1,nod);
        }
    }
void build_p()
    {
    for(int i=2; i<=n; ++i) lg[i]=1+lg[i>>1];
    for(int i=1; i<=n; ++i) P[0][i]=fat[i];
    for(int j=1; j<=lg[n]; ++j)
        for(int i=1; i<=n; ++i) P[j][i]=P[j-1][P[j-1][i]];
    }
int lca(int x,int y)
    {
    int diff,log2x,log2y;
    if(level[y]>level[x]) swap(x,y);

    for(log2x=1; (1<<log2x)<=x; ++log2x);
    for(log2y=1; (1<<log2y)<=y; ++log2y);
    --log2x,--log2y;

    for(int k=log2x; k>=0; --k)
        if(level[x]-(1<<k)>=level[y])
            x=P[k][x];

    if(x==y) return x;

    for(int k=log2y; k>=0; --k)
        if(P[k][x]!=P[k][y] && P[k][x])
            x=P[k][x],y=P[k][y];

    return fat[x];

    }
void initialize()
{
    nr_orase_distruse=0;
    for(int i=1;i<=n;++i)
    {G[i].clear();
    del[i]=false;
    }
    for(int i=1;ac[i].size();++i) ac[i].clear();
}
void read()
    {
    int x,y,q;
    f>>n>>k;
    for(int i=1; i<n; ++i)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    dfs(1,0,0);
    build_p();
    for(int i=1; i<=k; ++i)
        {
        f>>x>>y;
        q=lca(x,y);
        ac[q].push_back( {x,y});
        lca_l.push_back(q);
        }

    }

bool cmp(int nod1,int nod2)
    {
    return level[nod1]>level[nod2];
    }
void dfs_s(int nod)
    {
    del[nod]=true;
    foor(it,G[nod])
        {
        if(level[*it]>level[nod] && !del[*it]) dfs_s(*it);
        }
    }
void solve()
    {
    sort(lca_l.begin(),lca_l.end(),cmp);
    foor(it,lca_l)
        {
        foor(itt,ac[*it])
            {
            if(!del[itt->l1] && !del[itt->l2])
                {
                ++nr_orase_distruse;
                dfs_s(*it);
                break;
                }
            }
        }
    }

int main()
    {
    int t;
    f>>t;
    for(; t; --t)
        {
        initialize();
        read();
        solve();
        cout<<nr_orase_distruse<<'\n';
        assert(nr_orase_distruse<0);
        }
    return 0;
    }
