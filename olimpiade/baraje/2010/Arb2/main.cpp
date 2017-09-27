#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("arb2.in");
ofstream fout("arb2.out");
/// ////////////////////////////////

#define nmax 100010
#define inf INFINITY
#define min(x,y) (x<y ? x:y)

struct eee{int n,d,c;};

long long cost[nmax],depth[nmax],dp[nmax];
int n;
vector<eee> G[nmax];

void dfs(int nod,int tata)
{
    if(G[nod].size()==1)
    {
        cost[nod]=inf;
        return;
    }
    for(auto &it:G[nod])
    {
        if(it.n==tata) continue;
        dfs(it.n,nod);
        depth[nod]=max(depth[nod],depth[it.n]+it.d);
        dp[nod]+=dp[it.n];
    }
    long long k;
    for(auto &it:G[nod])
    {
        if(it.n==tata) continue;

        k=depth[nod]-depth[it.n]-it.d;
        dp[nod]+=k*min(cost[it.n],it.c);
        cost[nod]+=min(cost[it.n],it.c);
    }
}
void read();
int main()
{
    read();
    dfs(1,0);
    cout<<dp[1]<<'\n';
    return 0;
}

void read()
{
    int x,y,c,d;
    fin>>n;
    for(int i=1;i<n;++i)
    {
        fin>>x>>y>>d>>c;
        G[x].push_back({y,d,c});
        G[y].push_back({x,d,c});
    }
}

