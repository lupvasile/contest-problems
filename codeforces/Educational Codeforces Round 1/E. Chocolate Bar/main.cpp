#include <iostream>
#include <cstring>

using namespace std;

#define nmax 33
#define inf 0x3f3f3f3f

int dp[nmax][nmax][60];

int main()
{
    int n,m,k,i,j,h;
    n=30;

    memset(dp,inf,sizeof dp);

    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=0;k<=min(i*j,50);++k)
            {

                if(k==i*j || k==0) {
                    dp[i][j][k]=0;
                    continue;
                }

                for(h=1;h<i;++h)
                    dp[i][j][k]=min(dp[i][j][k],j*j + dp[h][j][k]);

                for(h=1;h<j;++h)
                    dp[i][j][k]=min(dp[i][j][k],i*i + dp[i][h][k]);

                for(h=1;h*j<=k && h<i;++h)
                    dp[i][j][k]=min(dp[i][j][k],j*j + dp[i-h][j][k-h*j]);

                for(h=1;h*i<=k && h<j;++h)
                        dp[i][j][k]=min(dp[i][j][k],i*i+dp[i][j-h][k-i*h]);
            }
    int t;
    cin>>t;
    for(;t;--t)
    {
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<'\n';
    }
    return 0;
}
