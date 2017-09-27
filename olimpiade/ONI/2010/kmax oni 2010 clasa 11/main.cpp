#include <fstream>
#include <iostream>

using namespace std;

ifstream f("kmax.in");
ofstream g("kmax.out");

#define cout g
#define nmax 302

int n,k,mod,i,j,pos;
int dp[nmax][nmax];
int comb[nmax][nmax];

int main()
    {
    f>>n>>k>>mod;
    comb[0][0]=1;
    for(i=1; i<=n; ++i)
        for(j=0; j<=i; ++j)
            {
            comb[i][j]=comb[i-1][j];
            if(j)
                {
                comb[i][j]+=comb[i-1][j-1];
                if(comb[i][j]>=mod) comb[i][j]-=mod;
                }
            }
    dp[0][0]=1;
    for(i=1; i<=n; ++i)
        {
        for(pos=1; pos<=i; ++pos)
            if(pos==1)

                {
                for(j=1; j<=i; ++j)
                    {
                    dp[i][j]+=dp[i-1][j];//pt max pe pozitia 1
                    dp[i][j]+=dp[i-1][j-1];//pt max pe pozitia j
                    while(dp[i][j]>=mod) dp[i][j]-=mod;
                    }
                }
            else
                {
                for(j=1; j<=i; ++j)
                {
                    dp[i][j]+=(1ll*dp[pos-1][k-1]*dp[i-pos][j]*comb[i-1][pos-1]%mod);
                    if(dp[i][j]>=mod) dp[i][j]-=mod;
                }
            }
        for(j=i+1; j<=k; ++j) dp[i][j]=dp[i][j-1];
        }

    cout<<dp[n][k];
    return 0;
    }
