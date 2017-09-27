#include <iostream>
#include <fstream>

using namespace std;

ifstream f("fractii2.in");
ofstream g("fractii2.out");

#define cout g
#define mod 100003
void rez_1();
void rez_2();

int n,p;
int dp[2010][1010];

int main()
    {
    f>>p>>n;
    if(p==1) rez_1();
    else rez_2();
    cout.close();
    return 0;
    }

void rez_1()
    {
    int i;
    for(i=1; i<n; ++i) cout<<i<<' ';
    cout<<n-1;
    }
void rez_2()
    {
    int rez=0;
    int i,j,m;
    dp[2][1]=1;
    for(i=3; i<=n; ++i)
       for(j=1;j<=(i>>1);++j)
       {
           dp[i][j]=dp[i][j-1]+dp[i-j][(i-j)>>1]-dp[i-j][(j-1)>>1];
           if(dp[i][j]>=mod) dp[i][j]-=mod;
           if(dp[i][j]<0) dp[i][j]+=mod;
                  }
          cout<<dp[n][n>>1];
    }
