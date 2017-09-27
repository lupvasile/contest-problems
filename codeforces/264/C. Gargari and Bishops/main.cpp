#include <iostream>

using namespace std;

#define nmax 2010

int n,i,j,y[2]={1,2},x[2]={1,1},a[nmax][nmax];
bool h;
unsigned long long dp[2*nmax],ds[2*nmax],maxx[2];
#define dp (dp+nmax)

int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
    {
        cin>>a[i][j];
        dp[i-j]+=a[i][j];
        ds[i+j]+=a[i][j];
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
    {
        h=(i+j)&1;
        if(maxx[h]<dp[i-j]+ds[i+j]-a[i][j])
        {
        maxx[h]=dp[i-j]+ds[i+j]-a[i][j];
        x[h]=i;
        y[h]=j;
        }
    }
    cout<<maxx[0]+maxx[1]<<"\n";
    cout<<x[0]<<' '<<y[0]<<" ";
    cout<<x[1]<<' '<<y[1];
return 0;
}
