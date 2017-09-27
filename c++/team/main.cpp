#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ofstream fout("team.out");
/// //////////////////////////////////////////

#define nmax 601
#define pmax 61
#define inf 0x3f3f3f3f

vector<pair<int,int>> G[nmax];
int p,n,m;
int d[pmax],dist[nmax],dd[pmax][pmax],dp[pmax][pmax][pmax];
priority_queue<pair<int,int>> q;

void read();
void dijkstra(const int &nod);
void make_dist()
{
    int i,j,k;
    d[0]=1;
    for(i=0; i<=p; ++i)
    {
        dijkstra(d[i]);
        for(j=0; j<=p; ++j)
            dd[i][j]=dist[d[j]];
    }
    for(i=0; i<=p; ++i)
        for(j=0; j<=p; ++j)
            for(k=0; k<=p; ++k)
                dp[i][j][k]=-1;
}

int get_dp(const int &k,const int &x,const int &y)
{
    if(x>y) return 0;
    if(x==y && x==k) return 0;
    if(dp[k][x][y]>=0) return dp[k][x][y];

    for(int h=x; h<=y; ++h)
        dp[k][x][y]=dp[k][x][y]>=0 ? min(dp[k][x][y],get_dp(h,x,h-1)+get_dp(h,h+1,y)+dd[k][h]):(get_dp(h,x,h-1)+get_dp(h,h+1,y)+dd[k][h]);

    return dp[k][x][y];
}
int main()
{
      int i,j,c;
    //fin>>p>>n>>m;
    freopen("team.in","r",stdin);
    freopen("team.out","w",stdout);
    /*p=gi();
    n=gi();
    m=gi();*/
    scanf("%d%d%d",&p,&n,&m);
    for(; m; --m)
    {
        /*i=gi();
        j=gi();
        c=gi();*/
        //fin>>i>>j>>c;
        scanf("%d%d%d",&i,&j,&c);
        G[i].push_back({j,c});
        G[j].push_back({i,c});

    }
    for(i=1; i<=n; ++i)
        //d[i]=gi();
        scanf("%d",d+i);
        //fin>>d[i];
    make_dist();
    cout<<get_dp(0,1,p);
    return 0;
}

void read()
{

}

void dijkstra(const int &nod)
{
    int i;
    pair<int,int> top;
    for(i=1; i<=n; ++i) dist[i]=inf;
    dist[nod]=0;
    q.push({0,nod});
    while(!q.empty())
    {
        top=q.top();
        q.pop();
        for(auto vec:G[top.second])
        {
            if(dist[vec.first]>-top.first+vec.second)
            {
                dist[vec.first]=-top.first+vec.second;
                q.push({-dist[vec.first],vec.first});
            }
        }
    }
}
