#include <bits/stdc++.h>

using namespace std;

ifstream f("iepuri2.in");
ofstream g("iepuri2.out");

#define cout g
#define nmax 110
#define mod 30011
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

vector <int> G[nmax];
int n,k,i,x,y,rad;
int P[nmax];
int dp[nmax][nmax];

void dfs(int nod)
{
    int i,s;
    foor(it,G[nod]) dfs(*it);
    for(i=k;i;--i)
    {
        s=1;
        foor(it,G[nod]) s=s*dp[*it][i+1]%mod;
        dp[nod][i]=(dp[nod][i+1]+s)%mod;
    }
}

int main()
{
    f>>n>>k;
    for(i=1;i<n;++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        P[y]=x;
    }

    for(i=1;i<=n;++i) if(P[i]==0)
    {
        rad=i;
        break;
    }

    dfs(rad);
    cout<<dp[rad][1];
    return 0;
}
