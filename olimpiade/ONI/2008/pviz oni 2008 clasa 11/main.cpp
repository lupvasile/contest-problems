#include <bits/stdc++.h>

using namespace std;

ifstream f("pviz.in");
ofstream g("pviz.out");

#define nmax 2001
#define mod 10007
//#define cout g
int v[nmax],n,m,dp[nmax][nmax],i,j;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i) f>>v[i];
    dp[0][0]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=i;++j)
            dp[i][j]=(dp[i][j]+dp[i-1][j-1]+(v[j]-(i-1))*dp[i-1][j])%mod;

    cout<<dp[n][m];
    return 0;
}
