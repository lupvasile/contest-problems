#include <bits/stdc++.h>
using namespace std;
ifstream f("numere6.in");
ofstream g("numere6.out");
#define cout g
#define mod 9973
#define amax 9100

int a,b,ff[10],sol,fact[amax],finv[amax],i;

int comb(int n,int k)
    {
    return 1LL*fact[n]*finv[n-k]*finv[k]%mod;
    }

void bback(int cate,int p,int last)
    {
    int i;
    if(cate==0 && p>1) return;
    if(p==1)
        {
        int x=comb(a,cate);
        cate=a-cate;
        for(i=2; i<=9; ++i)
            {
            x=x*comb(cate,ff[i])%mod;
            cate-=ff[i];
            }
        sol=(sol+x)%mod;
        return;
        }
    for(i=last; i<=9; ++i) if(p%i==0)
            {
            ++ff[i];
            bback(cate-1,p/i,i);
            --ff[i];
            }
    }

int poww(int a,int p)
    {
    int x(1);
    for(; p; p>>=1)
        {
        if(p&1) x=x*a%mod;
        a=a*a%mod;
        }
    return x;
    }

int main()
    {
    f>>a>>b;
    fact[0]=1;
    for(i=1; i<=a; ++i) fact[i]=fact[i-1]*i%mod;
    finv[a]=poww(fact[a],mod-2);
    for(i=a-1; i>=0; --i) finv[i]=finv[i+1]*(i+1)%mod;
    bback(a,b,2);
    cout<<sol;
    return 0;
    }
