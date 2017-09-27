#include <bits/stdc++.h>

using namespace std;

ifstream f("cifru.in");
ofstream g("cifru.out");

#define mod 19997
#define cout g
#define nmax 2006

int i,n,dp[nmax],j;
long long k;
vector <int> divk;
int fact[nmax],finv[nmax];

int poww(int a,int p);
inline int aranj(int n,int k)
{
    return 1LL*fact[n]*finv[n-k]%mod;
}

int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i) if(k%i==0) divk.push_back(i);
    fact[0]=1;
    for(i=1;i<=n;++i) fact[i]=1LL*fact[i-1]*i%mod;
    finv[n]=poww(fact[n],mod-2);
    for(i=n-1;i>=0;--i) finv[i]=1LL*finv[i+1]*(i+1)%mod;
    dp[1]=dp[0]=1;
    for(i=2;i<=n;++i)
    {
        for(j=0;j<divk.size() && divk[j]<=i;++j) dp[i]=1LL*(dp[i]+1LL*aranj(i-1,divk[j]-1)*dp[i-divk[j]]%mod)%mod;
    }
    cout<<dp[n];
    return 0;
}
int poww(int a,int p)
{
    int x(1);
    for(;p;p>>=1)
    {
        if(p&1) x=1LL*x*a%mod;
        a=1LL*a*a%mod;
    }
    return x;
}
