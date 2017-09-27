#include <iostream>
#include <fstream>

using namespace std;

ifstream f("munte3.in");
ofstream g("munte3.out");

#define nmax 200
#define hmax 210

#define cout g

int n,i,h;
int dp[nmax][hmax][100];

void big_sum(int a[],int b[])
    {
    int i,t(0),n;
    n=max(a[0],b[0]);
    for(i=1; i<=n; ++i)
        {
        a[i]=a[i]+b[i]+t;
        t=a[i]/10;
        a[i]%=10;
        }
    a[0]=n;
    while(t)
        {
        a[++a[0]]=t%10;
        t/=10;
        }
    return;
    }
void egaleaza(int a[],int b[])
{
    a[0]=b[0];
    for(int i=1;i<=b[0];++i) a[i]=b[i];
}
int main()
    {
    f>>n;
    dp[0][0][0]=dp[0][0][1]=dp[1][1][0]=dp[1][1][1]=1;
    for(i=2; i<=2*n-2; ++i)
        {

        egaleaza(dp[i][0],dp[i-1][1]);
        h=0;
        for(h=1; h<=i; ++h)
            {

            egaleaza(dp[i][h],dp[i-2][h]);
            big_sum(dp[i][h],dp[i-1][h-1]);
            big_sum(dp[i][h],dp[i-1][h+1]);
            }
        }
    n=2*n-2;
    for(; dp[n][0][0]; --dp[n][0][0]) cout<<(int)dp[n][0][dp[n][0][0]];
    return 0;
    }
