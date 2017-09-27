#include <iostream>
#include <fstream>

using namespace std;

ifstream f("poly2.in");
ofstream g("poly2.out");
int c[510],n,i,j;
#define mod 30103
int main()
{
    f>>n;
    c[0]=1;
    for(i=1;i<=n;++i)
    for(j=0;j<i;++j)
    c[i]=(c[i]+c[j]*c[i-j-1])%mod;
    g<<c[n];
    return 0;
}
