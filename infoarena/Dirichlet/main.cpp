#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dirichlet.in");
ofstream fout("dirichlet.out");

#define mod 9999991

int poww(int n,int p)
{
    int res=1;
    for(;p;p>>=1)
    {
        if(p&1) res=1ll*res*n%mod;
        n=1ll*n*n%mod;
    }
    return res;
}

int main()
{
    int res(1),i,n;
    fin>>n;
    for(i=1;i<=n;++i) res=1ll*res*i%mod;
    res=poww(res,mod-2);
    for(i=n+2;i<=2*n;++i)
        res=1ll*res*i%mod;

    fout<<res;
    return 0;
}
