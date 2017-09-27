#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("profit.in");
ofstream fout("profit.out");
/// ////////////////////////////////

#define nmax 2010
#define inf 0x3f3f3f3f

int h[nmax],res(inf),n;
int dp[nmax];
vector<int> v;


void solve()
{
    int i;
    memset(dp,inf,sizeof dp);

    dp[0]=0;

    for(auto height:v)
    {
        for(i=1;i<=n;++i)
            dp[i]=min(dp[i],dp[i-1]+abs(height-h[i]));
    }

    res=min(res,dp[n]);
}

int main()
{
    int i;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>h[i];
        v.push_back(h[i]);
    }

    sort(v.begin(),v.end());
    solve();
    reverse(h+1,h+1+n);
    solve();

    cout<<res;
    return 0;
}
