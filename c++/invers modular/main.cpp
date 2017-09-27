#include <iostream>
#include <fstream>

using namespace std;

ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
#define cout g
int a,mod;
int pow(int x,int p)
{
    int i=0,r(1);
    while (p)
    {
        if (p&1) r=1LL*r*x%mod;
        p>>=1;
        x=1LL*x*x%mod;
    }
    return r;
}
int phi(int n)
{int nr(n);
    for(int i=2;i*i<=n;++i)
    {
        if(n%i)continue;
        nr=1LL*nr/i*(i-1);
        while (n%i==0) n/=i;
    }
    if (n>1) nr=1LL*nr/n*(n-1);
    return nr;
}
int main()
{
f>>a>>mod;
cout<<pow(a,phi(mod)-1);
    return 0;
}
