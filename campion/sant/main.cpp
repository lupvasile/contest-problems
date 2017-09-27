#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("sant.in");
ofstream g("sant.out");

#define cout g
#define inf 10100

int s,n,c,i,j,k;
int dp[102][1002],sol[102];
char prin[102][1002];
struct {int l,p;} cat[22];
void afis(int n,int s)
{
    if(n>1) afis(n-1,s-cat[prin[n][s]].l);
    cout<<(int)prin[n][s]<<' ';

}
int main()
{
    f>>s>>n>>c;
    for(i=1;i<=c;++i) f>>cat[i].l>>cat[i].p;
    for(i=0;i<=n;++i) for(j=1;j<=s;++j) dp[i][j]=inf;

    for(i=1;i<=c;++i) if(dp[1][cat[i].l]>cat[i].p)
    {
        dp[1][cat[i].l]=cat[i].p;
        prin[1][cat[i].l]=i;
    }

    for(i=1;i<n;++i) for(j=1;j<=s;++j)
        if(dp[i][j]!=inf)
        for(k=1;k<=c;++k)
        if(cat[k].l+j<=s)
        if(dp[i+1][cat[k].l+j]>dp[i][j]+cat[k].p || (dp[i+1][cat[k].l+j]==dp[i][j]+cat[k].p && prin[i+1][cat[k].l+j]>k))
    {
        dp[i+1][cat[k].l+j]=dp[i][j]+cat[k].p;
        prin[i+1][cat[k].l+j]=k;
    }
    if(dp[n][s]==inf)
    {
        cout<<0;
        return 0;
    }
    cout<<dp[n][s]<<'\n';
    //afis(n,s);
    for(;n;s-=cat[sol[sol[0]]].l,--n) sol[++sol[0]]=prin[n][s];
    sort(sol+1,sol+sol[0]+1);
    for(i=1;i<=sol[0];++i) cout<<sol[i]<<' ';
    return 0;
}
