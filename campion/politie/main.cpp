#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;

#define nmax 511
int n,i,tip,x,l,t,j;
struct
{
    int suma,timp;
} amenda[4];
struct eveniment
{
    int from,to,suma,tip;
    bool operator < (const eveniment &c) const
    {
        if(to!=c.to) return to<c.to;
        if(from!=c.from) return from<c.from;
        return suma<c.suma;
    }
} v[nmax];
int last[nmax];
int dp[nmax][nmax];

int search(int x)
{
    int step;
    for(step=1; step<=n; step<<=1);
    int pos=0;
    for(; step; step>>=1)
    {
        if(pos+step<=n) if (v[pos+step].to<=x) pos+=step;
    }
    return pos;
}
eveniment mk_eveniment(int a,int b,int c,int d)
{
    eveniment e;
    e.from=a;e.to=b;e.suma=c;e.tip=d;
    return e;
}
int main()
{
    freopen("politie.in","r",stdin);
    freopen("politie.out","w",stdout);

    scanf("%d",&t);
    for(i=1; i<=3; ++i) scanf("%d%d",&amenda[i].suma ,&amenda[i].timp);
    scanf("%d",&n);

    for(i=1; i<=n; ++i)
    {
        scanf("%d%d",&tip,&x);
        v[++l]= mk_eveniment(x,x+amenda[tip].timp,amenda[tip].suma,tip);
        if(v[l].to>t) --l;
    }
    n=l;
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i) last[i]=search(v[i].from);

    for(i=0; i<=n; ++i)
        for(j=0; j<=n; ++j)
        {
           if(i<j)
           {
            if(v[j].tip==3) dp[i][j]=dp[i][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i][last[j]]+v[j].suma);
           }
           if(i==j)
           {
               if(v[j].tip==3) dp[i][j]=max(dp[i-1][j-1],dp[last[i]][last[j]]+v[j].suma);
               else dp[i][j]=max(dp[i-1][j-1],dp[last[i]][j-1]+v[i].suma);
           }
           if(i>j) dp[i][j]=dp[j][i];
        }

    cout<<dp[n][n];
    /*for(i=1;i<=n;++i)
    {
        cout<<v[i].from<<' '<<v[i].to<<' '<<v[i].tip<<' '<<last[i]<<'\n';
    }
    for(i=0;i<=n;++i)
    {
        for(j=0;j<=n;++j) cout<<setw(4)<<dp[i][j];
        cout<<'\n';
    }*/
    return 0;
}
