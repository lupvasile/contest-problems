#include <bits/stdc++.h>

using namespace std;

ifstream fin("arbxyz.in");
ofstream fout("arbxyz.out");

#define nmax 100010

vector<int> G[nmax],where[nmax];
int dad[20][nmax],lev[nmax],dp[nmax],n,s[3],sum;

void dfs(int nod)
{
    for(auto son:G[nod])
    {
        if(dad[0][nod]==son) continue;

        dad[0][son]=nod;
        lev[son]=lev[nod]+1;

        dfs(son);

        dp[nod]+=dp[son];
    }

    ++dp[nod];

    if(nod!=1)where[dp[nod]].push_back(nod);

}

void read_arb()
{
    int x,y,i,k;
    for(i=1; i<n; ++i)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);
    for(k=1; (1<<k)<=n; ++k)
        for(i=1; i<=n; ++i)
            dad[k][i]=dad[k-1][dad[k-1][i]];
}

int lca(int x,int y)
{
    ///warning!!! not true lca
    if(lev[y]<lev[x]) swap(x,y);

    int diff=lev[y]-lev[x],k;
    for(k=0; (1<<k)<=diff; ++k)
        if(diff&(1<<k)) y=dad[k][y];

    if(x==y) return x;
    return 1;
}

bool posibil()
{
    int k,h,wanted;
    if(sum!=n) return 0;
    for(k=0; k<3; ++k)
    {
        for(auto nod:where[s[k]])
        {
            for(h=0; h<3; ++h)
            {
                if(h==k) continue;
                wanted=dp[1]-s[h];///daca urmatoru ii stramos la nod

                for(auto nod_2:where[wanted])
                {
                    if(nod_2==nod) continue;
                    if(lev[nod_2]>=lev[nod])continue;
                    if(lca(nod_2,nod)!=nod_2) continue;

                    if(dp[nod_2]-dp[nod]==sum-s[h]-s[k]) return 1;
                }

                wanted=dp[1]-s[h]-s[k];///daca urmatoru nu ii satramos la nod

                for(auto nod_2:where[wanted])
                {
                    if(nod_2==nod) continue;
                    if(lca(nod_2,nod)!=1) continue;

                    if(dp[nod_2]==sum-s[h]-s[k]) return 1;
                }

            }
        }
    }


    return 0;
}

int main()
{
    int T,i;
    fin>>T;
    lev[1]=1;
    for(; T; --T)
    {
        fin>>n>>s[0]>>s[1]>>s[2];
        sum=s[0]+s[1]+s[2];

        for(i=1; i<=n; ++i)
        {
            G[i].clear();
            where[i].clear();
            dp[i]=0;
        }
        read_arb();
        fout<<posibil()<<'\n';
    }
    fout.close();

    return 0;
}
