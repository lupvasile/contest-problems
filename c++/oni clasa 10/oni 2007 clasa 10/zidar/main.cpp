#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("zidar.in");
ofstream g("zidar.out");

#define cout g
#define inf 0x3f3f3f3f

int cost[22][22][62];
//cost[i][j][k][l] costul unui zid ce pe linia i are caramizi intre j si k si are l caramizi
int a[51][21];
int z[21][62];
int n,m,nr_caramizi,bani;
int i,j,k,l,h,s,res;

int main()
{
    f>>n>>m>>nr_caramizi>>bani;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j) f>>a[i][j]; //rastorni a ca sa ai pamantu bine

    for(i=1; i<=n; ++i)
    {
        memset(&cost[0][0][0],inf,sizeof(cost));
//memset();
        for(j=1; j<=m; ++j)
            for(k=j, s=a[i][j]; k<=m && s<=bani; ++k, s+=a[i][k])
                for(l=i+k-j; l<=nr_caramizi && l<=(i-1)*m + k-j+1; ++l)
                {
                    int &p=cost[j][k][l];
                    p=inf;
                    for(h=j;h<=k;++h) p=min(p,z[h][l-(k-j+1)]+s);
                    if(p<=bani) res=max(res,l);
                }
    for(j=0;j<=m;++j) for(l=0;l<=nr_caramizi;++l) z[j][l]=inf;
    for(j=1;j<=m;++j)
        for(k=j;k<=m;++k)
            for(l=i+k-j; l<=nr_caramizi  && l<=(i-1)*m + k-j+1; ++l)
                for(h=j;h<=k;++h) z[h][l]=min(z[h][l],cost[j][k][l]);
    }
    cout<<res;
    return 0;
}
