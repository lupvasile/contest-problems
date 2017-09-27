#include <iostream>
#include <fstream>

using namespace std;

ifstream f("borg.in");
ofstream g("borg.out");

#define cout g
#define mod 30103

int n,m,h,a,b,c,k,r,res;
int fact[8010],fact_inv[8010];

int put(int a,int x)
    {
    int res=1;
    while(x)
        {
        if(x&1) res=1LL*res*a%mod;
        x>>=1;
        a=1LL*a*a%mod;
        }
    return res;
    }


int comb(int n,int k)
    {
        if(k>n) return 0;
    return fact[n]*fact_inv[k]%mod*fact_inv[n-k]%mod;

    }

int main()
    {
    f>>n>>m>>h>>k;
    a=n*m*h+5;
    fact[0]=fact_inv[0]=1;
    for(int i=1; i<=a; ++i)
        {
        fact[i]=1LL*fact[i-1]*i%mod;
        fact_inv[i]=1LL*fact_inv[i-1]*put(i,mod-2)%mod;
        }
    for(a=0; a<=n; ++a)
        for(b=0; b<=m; ++b)
            for(c=0; c<=h; ++c)
                {
                r=1LL*comb(n,a)*comb(m,b)%mod;
                r=1LL*r*comb(h,c)%mod;
                r=1LL*r*comb((n-a)*(m-b)*(h-c),k)%mod;
                if((a+b+c)&1) r=-r+mod;
                res=res+r;
                res%=mod;
                }
    cout<<res;
    return 0;
    }
