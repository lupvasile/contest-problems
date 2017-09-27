#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("carry.in");
ofstream fout("carry.out");

#define nmax 100010
#define kmax 110
#define mod 30211

int dp[nmax][kmax][2];
int v[nmax];
char s[nmax];
int main()
{
    int i,n,K,j;
    fin>>n>>K;
    fin>>s+1;
    for(i=1; i<=n; ++i)
        v[i]=s[i]-'0';

    ///caz special daca nr ii de o cifra


    dp[n][0][0]=10-v[n];
    dp[n][1][1]=v[n];

    for(i=n-1; i>=2; --i)
        for(j=0; j<=K; ++j)
        {
            dp[i][j][0]=(dp[i+1][j][0]*(10-v[i]) + dp[i+1][j][1]*(9-v[i]))%mod;
            if(j) dp[i][j][1]=(dp[i+1][j-1][0]*(v[i]) + dp[i+1][j-1][1]*(v[i]+1))%mod;
        }
    if(n>1)
    {
        i=1;
        for(j=0; j<=K; ++j)
        {
            dp[i][j][0]=(dp[i+1][j][0]*(9-v[i]) + dp[i+1][j][1]*max(8-v[i],0))%mod;
            if(j) dp[i][j][1]=(dp[i+1][j-1][0]*(v[i]) + dp[i+1][j-1][1]*(v[i]+(v[i]!=9)))%mod;
        }
    }
    fout<<(dp[1][K][0]+dp[1][K][1])%mod;
    fout.close();
    return 0;
}
