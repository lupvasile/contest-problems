#include <bits/stdc++.h>

using namespace std;

ifstream f("radare.in");
ofstream g("radare.out");

#define cout g
#define nmax 3020
#define pmax 3510
#define foor(it,v) for(it=(v).begin();it!=v.end();++it)
#define mod 31333
vector<int> G[nmax];
vector<int> ::iterator it;
bool viz[nmax];
int n_sub[nmax],dp[nmax][pmax],cost[nmax],pow2[nmax],nnext[nmax];
int n,p,i,j,x,y,nod;
int v[nmax];

void dfs(int nod)
    {
    viz[nod]=true;
    n_sub[nod]++;
    v[++v[0]]=nod;
    for(auto vecin:G[nod]) if(!viz[vecin])
            {
            dfs(vecin);
            n_sub[nod]+=n_sub[vecin];
            }
    nnext[nod]=v[0]+1;
    }

#define maxb 200000
int pos(maxb);
char buf[maxb];
int gi()
    {
    int n(0);
    while(!(buf[pos]>='0' && buf[pos]<='9')) if(++pos>=maxb) f.read(buf,maxb),pos=0;
    while(buf[pos]>='0' && buf[pos]<='9')
        {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    return n;
    }


int main()
    {
    n=gi();
    p=gi();
    pow2[0]=1;
    for(i=1; i<=n; ++i)
        {
        pow2[i]=(pow2[i-1]<<1);
        if(pow2[i]>=mod) pow2[i]-=mod;
        }
    for(i=1; i<n; ++i)
        {
        x=gi();
        y=gi();
        G[x].push_back(y);
        G[y].push_back(x);
        }
    for(i=1; i<=n; ++i) cost[i]=gi();
    dfs(1);

    dp[1][0]=1;
    for(i=0; i<=n; ++i)
        {
        for(j=0; j<=p; ++j)
            if(dp[i][j])
                {
                nod=v[i];
                if(j+cost[nod]<=p)
                    {
                    dp[i+1][j+cost[nod]]+=dp[i][j];
                    if(dp[i+1][j+cost[nod]]>=mod) dp[i+1][j+cost[nod]]-=mod;
                    }

                dp[nnext[nod]][j]+=(dp[i][j]*pow2[n_sub[nod]-1])%mod;
                if(dp[nnext[nod]][j]>=mod) dp[nnext[nod]][j]-=mod;

                }
        }
    cout<<dp[n+1][p];
    return 0;
    }
