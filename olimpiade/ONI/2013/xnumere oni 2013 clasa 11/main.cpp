#include <bits/stdc++.h>

using namespace std;

ifstream f("xnumere.in");
ofstream g("xnumere.out");

#define mod 666013
#define cout g

int x,res,i;
long long n,k,ii;
vector<int> fact,inv_f;

int poww(int a,long long p)
{
    int res(1);
    for(;p;p>>=1)
    {
        if(p&1) res=1ull*res*a%mod;
        a=1ull*a*a%mod;
    }
    return res;
}

int main()
{
    f>>k>>x>>n;
    fact.resize(x+1);
    inv_f.resize(x+1);
    fact[0]=1;
    for(i=1;i<=x;++i) fact[i]=1ull*fact[i-1]*i%mod;
    inv_f[x]=poww(fact[x],mod-2);
    for(i=x-1;i>=0;--i) inv_f[i]=1ull*inv_f[i+1]*(i+1)%mod;
    res=1;
    for(ii=k-x+1;ii<=k;++ii) res=1ull*res*(ii%mod)%mod;
    res=1ll*res*inv_f[x]%mod;
    int p;
    int r(0);
    for(i=0;i<x;++i)
    {
        p=1ull*fact[x]*inv_f[i]%mod*inv_f[x-i]%mod;
        p=1ull*p*poww(x-i,n)%mod;
        if(i&1) r-=p;
        else r+=p;
        if(r>=mod) r-=mod;
        if(r<0) r+=mod;
    }
    cout<<1ull*res*r%mod;
    return 0;
}
