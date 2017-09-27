#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

#define cout fout
#define nmax 100010
#define foor(it,V) for(__typeof(V.begin()) it=V.begin();it!=V.end();++it)

int n,m,k;
vector<int> G[nmax];
int E[nmax<<1],First[nmax],L[nmax];
int lg[nmax<<1],rmq[22][nmax<<1];

void read()
{
    int x;
    fin>>n>>m;
    for(int i=2; i<=n; ++i)
    {
        fin>>x;
        G[x].push_back(i);
    }
}

void euler(int nod,int level)
{
    E[++k]=nod;
    First[nod]=k;
    L[nod]=level;
    foor(it,G[nod])
    {
        euler(*it,level+1);
        E[++k]=nod;
    }
}

void rrmq()
{
    for(int i=2; i<=k; ++i) lg[i]=1+lg[i>>1];
    for(int i=1; i<=k; ++i) rmq[0][i]=E[i];

    for(int j=1; j<=lg[k]; ++j)
        for(int i=1; i+(1<<j)-1<=k; ++i)
        {
            rmq[j][i]=rmq[j-1][i+(1<<(j-1))];
            if(L[rmq[j][i]]>L[rmq[j-1][i]])
                rmq[j][i]=rmq[j-1][i];
        }
}

int lca(int x,int y)
{
    x=First[x],y=First[y];
    if(x>y) swap(x,y);
    int d=lg[y-x+1];
    //cout<<x<<' '<<y<<' '<<d;
    if(L[rmq[d][x]]<L[rmq[d][y-(1<<d)+1]]) return rmq[d][x];
    else return rmq[d][y-(1<<d)+1];

}
int main()
{
    read();
    euler(1,0);
    rrmq();
    int x,y;
    for(;m;--m)
    {
        fin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
    //for(int i=1;i<=k;++i) cout<<E[i]<<' ';cout<<'\n';
    //for(int i=1;i<=k;++i) cout<<L[E[i]]<<' ';
    return 0;
}
