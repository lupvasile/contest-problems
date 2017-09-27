#include <cstdio>
#include <vector>


using namespace std;

#define nmax 100001
#define foor(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();++it)
int n,m,i,x;
vector<int> G[nmax];
int val[nmax],dp[nmax][2];//0 daca nodul nu e ales si 1 daca e ales

void dfs(int nod)
{
    dp[nod][1]=val[nod];
    foor(it,G[nod])
    {
        dfs(*it);
        dp[nod][0]+=max(dp[*it][1],dp[*it][0]);
        dp[nod][1]+=dp[*it][0];
    }
}

int main()
{

    freopen("arbsum.in","r",stdin);
    freopen("arbsum.out","w",stdout);

    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        G[x].push_back(i);
    }
    for(i=1;i<=n;++i) scanf("%d",&val[i]);
    dfs(1);
    printf("%d",max(dp[1][0],dp[1][1]));
    return 0;
}
