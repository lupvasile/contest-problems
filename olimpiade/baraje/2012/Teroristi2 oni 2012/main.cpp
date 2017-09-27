#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("teroristi2.in");
ofstream fout("teroristi2.out");
/// ////////////////////////////

#define nmax 110
vector<int> spn;
bool spec[nmax],used[nmax];
int n,mod,res,fact[nmax],finv[nmax];
vector<int> G[nmax];
int dp[2000000],mask[nmax];

bool can_remove(int conf,int k)
{
    for (auto aft:G[spn[k]])
        if(conf&mask[aft]) return 0;

    return 1;
}

int get_dp(int x)
{
    if(dp[x]!=-1) return dp[x];
    if((x&(x-1))==0) return dp[x]=1;

    dp[x]=0;

    for(int k=0; k<spn.size(); ++k)
        if(x&(1<<k))
        {
            if(can_remove(x,k)) dp[x]=dp[x]+get_dp(x^(1<<k));
            if(dp[x]>=mod) dp[x]-=mod;
        }

    return dp[x];
}

void read();

int main()
{
    read();
    cout<<1ll*(1ll*get_dp((1<<spn.size())-1)*fact[n]%mod)*finv[spn.size()]%mod;
    return 0;
}

int poww(int n,int p)
{
    int res(1);
    for(; p; p>>=1)
    {
        if(p&1) res=1ll*res*n%mod;
        n=1ll*n*n%mod;
    }
    return res;
}

void read()
{
    int x,y,k,i;
    fin>>n>>k>>mod;
    for(; k; --k)
    {
        fin>>x>>y;
        G[x].emplace_back(y);

        if(!spec[x])
        {
            spn.emplace_back(x);
            spec[x]=true;
        }
        if(!spec[y])
        {
            spn.emplace_back(y);
            spec[y]=true;
        }
    }

    for(i=0; i<spn.size(); ++i)
        mask[spn[i]]=(1<<i);

    memset(dp,-1,sizeof dp);

    fact[0]=1;
    for(i=1; i<=n; ++i) fact[i]=1ll*fact[i-1]*i%mod;
    finv[n]=poww(fact[n],mod-2);
    for(i=n-1; i; --i) finv[i]=1ll*finv[i+1]*(i+1)%mod;
    //for(i=0;i<n;++i) finv[i]=poww(fact[i],mod-2);
}
