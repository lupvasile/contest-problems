#include <bits/stdc++.h>

using namespace std;

ifstream f("peisaj.in");
ofstream g("peisaj.out");

#define cout g
#define nmax 52

unsigned long long dp[3][nmax][11];
int n,k,i,j,h,s,p,l1,l2,l;

void din_p1()
    {
    dp[0][0][0]=1;
    for(i=1; i<=n; ++i)
        {
        l=p;
        p=i%3;
        for(j=0; j<=i; ++j)
            {
            if(j>0) dp[p][j][0]=dp[l][j-1][0]+dp[l][j+1][0];
            else dp[p][j][0]=dp[l][j+1][0];
            }
        }
    cout<<dp[p][0][0]<<' ';
    }
void din_p2()
    {
    for(i=0; i<=2; ++i)
        for(j=0; j<=n; ++j) dp[i][j][0]=0;
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    p=0;
    for(i=1; i<=n; ++i)
        {
        l=p;
        p=i%3;
        for(j=0; j<=i; ++j)
            {
            if(j>0)
                {
                dp[p][j][1]=dp[l][j-1][1]+dp[l][j+1][1];
                if(j>=k) dp[p][j][1]+=dp[l][j-1][0];
                else dp[p][j][0]=dp[l][j-1][0]+dp[l][j+1][0];
                }
            else
                {
                dp[p][j][1]=dp[l][j+1][1];
                dp[p][j][0]=dp[l][j+1][0];
                }
            }
        }
    cout<<dp[p][0][1]<<' ';
    }
void din_p3()
    {
    for(i=0; i<=2; ++i)
        for(j=0; j<=n; ++j) dp[i][j][0]=dp[i][j][1]=0;
    dp[0][0][0]=1;
    l1=l2=p=0;
    for(i=1; i<=n; ++i)
        {
        l2=l1;
        l1=p;
        p=i%3;
        for(j=0; j<=i; ++j)
            for(h=0; h<=k; ++h)
                {
                if(j>0) dp[p][j][h]=dp[l1][j-1][h];
                else dp[p][j][h]=0;
                if(i>1&&h>0)dp[p][j][h]+=dp[l1][j+1][h]-dp[l2][j][h]+dp[l2][j][h-1];
                }
        }
    cout<<dp[p][0][k];
    }
int main()
    {
    f>>n>>k;
    din_p1();
    din_p2();
    din_p3();
    //cout<<dp[n][0]<<' '<<dp[n][0];
    return 0;
    }
