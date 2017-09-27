#include <bits/stdc++.h>

using namespace std;

ifstream f("karb2.in");
ofstream g("karb2.out");

#define cout g
#define nmax 100010
#define mod 666013
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,k,x,i,y;
bool car[nmax];
int dp[nmax][2];//0 pt influenta din subarbore, 1 pentru influenta de deasupra
vector <int> G[nmax];

int poww(int a,int p)
{
    int res(1);
    if (a>=mod) a-=mod;
    for(;p;p>>=1)
    {
        if(p&1) res=1LL*res*a%mod;
        a=1LL*a*a%mod;
    }
    return res;
}

void dfs(int nod,int fat)
{
    foor(it,G[nod]) if(*it!=fat) dfs(*it,nod);

    if(car[nod])
    {
        dp[nod][1]=0;
        dp[nod][0]=1;
        foor(it,G[nod]) if(*it!=fat) dp[nod][0]=1LL*dp[nod][0]*(dp[*it][0]+dp[*it][1])%mod;
        return;
    }
    dp[nod][1]=1;
    foor(it,G[nod]) if(*it!=fat) dp[nod][1]=1LL*dp[nod][1]*(dp[*it][0]+dp[*it][1])%mod;
    foor(it,G[nod]) if(*it!=fat) dp[nod][0]=(dp[nod][0]+1LL*dp[nod][1]*poww(dp[*it][0]+dp[*it][1],mod-2)%mod*dp[*it][0]%mod)%mod;
}
int main()
    {
    f>>n>>k;
    for(i=1; i<=k; ++i)
        {
        f>>x;
        car[x]=true;
        }
    for(i=1;i<n;++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    cout<<dp[1][0];
    return 0;
    }
