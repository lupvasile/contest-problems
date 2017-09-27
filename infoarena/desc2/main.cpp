#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#ifdef INFOARENA
ifstream f("desc2.in");
ofstream g("desc2.out");
#else
ifstream f("desc.in");
ofstream g("desc.out");
#endif // INFOARENA

#define cout g
#define mod 10007

int n,k,x,i,j,h;

int main()
    {
    f>>n>>k>>x;
    n-=k*(k-1)*x/2;
    int v[n+6][k+6];
    memset(v,0,sizeof(v));
    for(i=0;i<=n;++i) v[i][1]=1;
    for(i=0;i<=n;++i)
    {
        for(j=2;j<=k && j<=i;++j) v[i][j]=(v[i-j][j]+v[i][j-1])%mod;
        for(;j<=k;++j) v[i][j]=v[i][j-1];

    }
    cout<<(v[n][k]-v[n][k-1]<0 ? v[n][k]-v[n][k-1]+mod:v[n][k]-v[n][k-1]);
    return 0;
    }
