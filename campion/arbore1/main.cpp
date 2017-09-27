#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define nmax 100010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define mod 666013

int n,i,x,y;
vector <int> G[nmax];
bool viz[nmax];
int dp[nmax],fii[nmax];//fii include si nodul
int fact_inv[nmax];//factorialele inverselor modulare
int fact[nmax];//factorialele
int comb(int n,int k)
{
    if(n==k || k==0) return 1;
    return (1LL*fact[n]*fact_inv[k]%mod)*fact_inv[n-k]%mod;

}

int dfs(int nod) //returneaza numarul de fii ai unui nod
{
    int s=0;
    dp[nod]=1;
    fii[nod]=1;
    viz[nod]=1;
    foor(it,G[nod]) if(!viz[*it])
    {
        fii[nod]+=dfs(*it);
        viz[*it]=false;
    }

    foor(it,G[nod])
    if(!viz[*it])
{
    dp[nod]=(1LL*dp[nod]*comb(fii[nod]-1-s,fii[*it])%mod)*dp[*it]%mod;
        s+=fii[*it];
    }

    return fii[nod];
}

int power(int x,int p)
{
    int res(1);
    for(; p; p>>=1)
    {
        if(p&1) res=1LL*res*x%mod;
        x=1LL*x*x%mod;
    }
    return res;
}

int main()
{
    freopen("arbore1.in","r",stdin);
   freopen("arbore1.out","w",stdout);

    scanf("%d",&n);
    fact[0]=fact[1]=fact_inv[1]=1;
    for(i=2; i<=n; ++i)
    {
        fact[i]=1LL*fact[i-1]*i%mod;
        fact_inv[i]=1LL*fact_inv[i-1]*power(i,mod-2)%mod;

    }

    for(i=1; i<n; ++i)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);
    cout<<dp[1];
    return 0;
}
