#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("arbore4.in");
ofstream fout("arbore4.out");
/// ////////////////////////////////

void read();

#define mod 666013
#define nmax 100010

int n;
vector<int> G[nmax];
int nr_fii[nmax],dp[nmax],fact[nmax],finv[nmax];

inline int comb(int n,int k)
{
    return 1ll*fact[n]*finv[k]%mod*finv[n-k]%mod;
}


void dfs(int nod,int tata)
{
    for(auto son:G[nod])
        {
            if(son==tata) continue;
            dfs(son,nod);
            nr_fii[nod]+=nr_fii[son];
        }

    dp[nod]=1;
    int rem=nr_fii[nod];
    for(auto son:G[nod])
    {
        if(son==tata) continue;
        dp[nod]=1ll*(1ll*dp[nod]*dp[son]%mod)*comb(rem,nr_fii[son])%mod;
        rem-=nr_fii[son];
    }

    ++nr_fii[nod];
}

int main()
{
    read();
    dfs(1,0);
    cout<<dp[1];
    return 0;
}

int poww(int x,int p)
{
    int res=1;
    for(;p;p>>=1)
    {
        if(p&1) res=1ll*res*x%mod;
        x=1ll*x*x%mod;
    }
    return res;
}

void read()
{
    int x,y,i;
    fin>>n;
    for(i=1;i<n;++i)
    {
        fin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    fact[0]=1;
    for(i=1;i<=n;++i) fact[i]=1ll*fact[i-1]*i%mod;
    finv[n]=poww(fact[n],mod-2);
    for(i=n-1;i>=0;--i) finv[i]=1ll*finv[i+1]*(i+1)%mod;
}
