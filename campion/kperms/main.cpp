#include <iostream>
#include <cstdio>

using namespace std;

#define nmax 1010
#define mod 666013

int dp[nmax][nmax];
int i,j,n,k;

int main()
{
    freopen("kperms.in","r",stdin);
    freopen("kperms.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i) dp[i][1]=dp[i][i]=1;
    for(i=2;i<=n;++i)
        for(j=2;j<=k;++j)
        dp[i][j]=(j*dp[i-1][j]+(i-j+1)*dp[i-1][j-1])%mod;
    cout<<dp[n][k];
    return 0;
}
