#include <bits/stdc++.h>

using namespace std;

ifstream f("mosia.in");
ofstream g("mosia.out");

#define cout g
#define nmax 1020

struct par
{
    int x,y,d;
} p0({20000,20000}),p[nmax];
int i,n,pz;
double maxx;
bool cmp(par p1,par p2)
{
    int x=p0.x*p1.y+p1.x*p2.y+p2.x*p0.y-p2.x*p1.y-p0.x*p2.y-p1.x*p0.y;
    if(x!=0) return x>0;
    if(p1.x!=p2.x) return p1.x<p2.x;
    return p1.y>p2.y;
}
double pls[nmax],dp[nmax];

double aria(int i)
{
    return (double)p[i].d*sqrt((p[i-1].x-p[i+1].x)*(p[i-1].x-p[i+1].x)+(p[i-1].y-p[i+1].y)*(p[i-1].y-p[i+1].y))/2;
}
int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
    {
        f>>p[i].x>>p[i].y>>p[i].d;
        if(p[i].y<p0.y || p[i].y==p0.y && p[i].x<p0.x) p0=p[i],pz=i;
    }
    swap(p[pz],p[1]);
    sort(p+2,p+n+1,cmp);
    //for(i=1;i<=n;++i) cout<<p[i].x<<' '<<p[i].y<<'\n';
    p[n+1]=p[1];
    p[0]=p[n];
    pls[1]=aria(1);
    for(i=2; i<=n; ++i)
        dp[i]=max(dp[i-2]+(pls[i]=aria(i)),dp[i-1]);
    maxx=dp[n];
    dp[n]=0;
    for(i=n-1; i>=1; --i) dp[i]=max(dp[i+2]+pls[i],dp[i+1]);
    cout<<fixed<<max(maxx,dp[1])<<'\n';
    //for(i=1;i<=n;++i) cout<<pls[i]<<'\n';
    return 0;
}
