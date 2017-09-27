#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("reversez.in");
ofstream fout("reversez.out");
/// ////////////////////////////////

#define nmax 300010
#define mod 666013

int z[nmax],n;
long long res(1);
bool used[nmax],viz[nmax];
vector<int> G[nmax];
int dad[nmax],P[nmax];

int get_dad(int nod)
{
    if(nod!=dad[nod]) dad[nod]=get_dad(dad[nod]);
    return dad[nod];
}

void unite(int x,int y)
{
    x=get_dad(x),y=get_dad(y);
    if(x==y) return;
    dad[x]=y;
}

void dfs(int nod,int sigma)
{
    viz[nod]=true;
    res=res*sigma%mod;

    for(auto son:G[nod])
        if(!viz[son]) dfs(son,sigma-1);
}

int main()
{
    int n,sigma,i,L(-1),R(-1),put(0);
    fin>>n>>sigma;

    for(i=1; i<=n; ++i)
        fin>>z[i],dad[i]=i;
    dad[n+1]=n+1;
    for(i=2; i<=n; ++i)
    {
        if(i+z[i]-1>R && z[i]) L=i,R=z[i]+i-1;
        if(i<=R) unite(i,i-L+1);
    }

    ///teoretic pana acuma alea egale is in aceeasi componenta

    used[n+1]=true;
    for(i=1; i<=n; ++i)
        if(!used[i+z[i]])
        {
            used[i+z[i]]=true;
            P[get_dad(i+z[i])]=get_dad(z[i]+1);
        }

    for(i=1;i<=n;++i)
        if(i==dad[i] && P[i]!=0)
            G[P[i]].push_back(i);

    for(i=1; i<=n; ++i)
        if(!viz[get_dad(i)])
            dfs(get_dad(i),sigma);


    cout<<res;

    return 0;
}
