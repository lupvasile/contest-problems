#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("cai.in");
ofstream fout("cai.out");

#define nmax 1010
#define jeg 200
#define inf 0x3f3f3f3f

int a[nmax],b[nmax],n,dp[nmax][nmax];

void readData()
{
    int i;
    fin>>n;
    for(i=1; i<=n; ++i) fin>>a[i];
    for(i=1; i<=n; ++i) fin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
}


int solve()
{
    memset(dp,-inf,sizeof dp);
    dp[0][0]=0;
    int i,j;
    for(i=1; i<=n; ++i)
        for(j=1; j<=i; ++j)
        {
            if(a[i]<b[j])
                dp[i][j]=dp[i-1][j-1]-jeg;
            else if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else  dp[i][j]=dp[i-1][j-1]+jeg;
            dp[i][j]=max(dp[i][j],dp[i][j-1]-200);
            dp[i][j]=max(dp[i][j],dp[i-1][j]-200);
        }

    return dp[n][n];
}
int main()
{
    /*int T;
    fin>>T;
    for(; T; --T)
    {
        readData();
        cout<<solve()<<'\n';
    }*/
    int n=100;
    int i,t,rez;
    for(i = 2 ; ; i ++)
    {
        t = n / (i - 1) - n / i;
        if(t >= 1)
            rez -= 1ll * t ;//* calc(i - 1);
        else
            break;
    }
    int last = i - 2;
    for(i = 2 ; ; i++)
    {
        if(n / i <= last)
            break;
        rez -=0;// calc(n / i);
    }
    return 0;
}
