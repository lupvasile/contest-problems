#include <iostream>
#include <fstream>

using namespace std;

ifstream f("diamant.in");
ofstream g("diamant.out");
#define dmax 45000
#define cout g
int dp[2*dmax],aux[2*dmax];
#define dp (dp+dmax)
#define aux (aux+dmax)

int n,m,i,j,h,x,v;

int main()
{
    f>>n>>m>>x;
    dp[0]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        v=i*j;
        for(h=dmax-1-v;h>=-dmax+1;--h) aux[h+v]+=dp[h];
        for(h=-dmax+1+v;h<=dmax-1;++h) aux[h-v]+=dp[h];
        for(h=-dmax+1;h<=dmax-1;++h) dp[h]=(aux[h]+dp[h])%10000,aux[h]=0;
    }
    if(x>-dmax && x<dmax)
    cout<<dp[x];
    else cout<<0;
    return 0;
}
