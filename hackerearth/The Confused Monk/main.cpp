#include <iostream>

using namespace std;

#define mod 1000000007

int gcd(int a,int b)
{
    while(a%=b) swap(a,b);
    return b;
}
int n,prod(1),gg(-1),x;

int poww(int x,int p)
{
    int res(1);
    for(;p;p>>=1)
    {
        if(p&1) res=1ll*res*x%mod;
        x=1ll*x*x%mod;
    }
    return res;
}

int main()
{
    cin>>n;
    for(;n;--n)
    {
        cin>>x;
        if(gg==-1) gg=x;
        else gg=gcd(gg,x);
        prod=1ll*prod*x%mod;
    }
    cout<<poww(prod,gg);
    return 0;
}
