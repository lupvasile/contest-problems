#include <iostream>
#include <fstream>

using namespace std;

ifstream f("joc13.in");
ofstream g("joc13.out");

#define cout g
#define nmax 5010
#define inf 0x3f3f3f3f

int n,k,i,j,l,maxx;
int v[2][nmax],dp[2][nmax][12];

int main()
    {
    f>>n>>k;
    for(i=1; i<=n; ++i) f>>v[0][i];
    for(i=1; i<=n; ++i) f>>v[1][i];
    dp[0][1][1]=v[0][1];
    dp[1][1][1]=v[0][1]+v[1][1];
    for(i=2; i<=n; ++i)
        {
        for(l=0; l<2; ++l)
            for(j=2; j<=k; ++j)
                {
                if(j>i) break;
                dp[l][i][j]=v[l][i]+dp[l][i-1][j-1];
                }

        for(l=0;l<2;++l)
        {
            maxx=-inf;
            for(j=2;j<=k;++j)
            {
                if(j>i) break;
                maxx=max(maxx,dp[l^1][i][j]);
            }
            dp[l][i][1]=maxx+v[l][i];
        }
        }
    maxx=-inf;
    for(j=1;j<=k;++j) maxx=max(maxx,dp[1][n][j]);
    cout<<maxx;
    return 0;
    }
