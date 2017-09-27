#include <iostream>
#include <fstream>

using namespace std;

ifstream f("suma4.in");
ofstream g("suma4.out");
#define cout g
#define nmax 70000

int i,n,level,cnt,l2,lin,x;
int v[nmax],son[nmax],dp[nmax];

int main()
{
    f>>n;
    for(level=1;level*(level+1)*(2*level+1)/6<n;++level);
    for(i=1;i<=n;++i) f>>v[i];
    cout<<level<<' ';

    for(i=n;i>n-level*level;--i) dp[i]=v[i];
    i=n-level*level;
    for(;i;--i,--cnt)
    {
        if(cnt==0)
        {
            --level;
            l2=level*level;
            cnt=l2;
        }
        lin=(cnt-1)/level+1;
        x=i+l2+lin-1;
        son[i]=x;
        dp[i]=dp[x];
        if(dp[i]>dp[x+1])
        {
            son[i]=x+1;
            dp[i]=dp[x+1];
        }
        if(dp[i]>dp[x+level+1])
        {
            son[i]=x+level+1;
            dp[i]=dp[x+level+1];
        }
        if(dp[i]>dp[x+level+2])
        {
            son[i]=x+level+2;
            dp[i]=dp[x+level+2];
        }
        dp[i]+=v[i];
    }
    cout<<dp[1]<<'\n';
    for(i=1;i;i=son[i]) cout<<i<<' ';
    return 0;
}
