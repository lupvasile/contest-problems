#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("spiridusi.in");
ofstream fout("spiridusi.out");

#define nmax 100010

vector<int> G[nmax];
int n,c,res;
int p[nmax],dp[20][nmax],dad[20][nmax],s[nmax];
int k,poz,minn;

void dfs(int nod,int tata,int lev)
{
    p[nod]+=p[tata];
    s[nod]+=s[tata];
    dad[0][nod]=tata;
    minn=p[nod];
    for(k=1;(1<<k)<lev;++k) dad[k][nod]=dad[k-1][dad[k-1][nod]];
    dp[0][nod]=p[tata];
    for(k=1;(1<<k)<lev;++k) dp[k][nod]=min(dp[k-1][nod],dp[k-1][dad[k-1][nod]]);

    poz=nod;

    for(;k>=0;--k)
        if(dad[k][poz])
            if(s[nod]-s[dad[0][dad[k][poz]]]<=c)
            {
                minn=min(minn,dp[k][poz]);
                poz=dad[k][poz];
            }

    if(s[nod]-s[dad[0][poz]]<=c)
    {
        if(dad[0][poz]) minn=min(minn,dp[0][poz]);
        res=max(res,p[nod]-minn);
    }

    for(auto it:G[nod]) if(it!=tata) dfs(it,nod,lev+1);

}

int main()
{
    int i,x,y;
    fin>>n>>c;
    for(i=1;i<=n;++i) fin>>s[i];
    for(i=1;i<=n;++i) fin>>p[i];
    for(i=1;i<n;++i)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1,0,1);
    cout<<res;
    return 0;
}
