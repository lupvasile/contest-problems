#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("insula2.in");
ofstream fout("insula2.out");
/// ////////////////////////////////

void read();
void convex_hull();

#define nmax 310
#define inf 1e9

struct point
{
    double x,y;
    int ind;
    bool operator < (const point &o) const
    {
        if(y==o.y) return x<o.x;
        return y<o.y;
    }
};

point p[nmax],st[nmax];
int lst,n,K;
double dp[nmax][nmax],memo[nmax][nmax];

inline double det(point a,point b,point c)
{
    return (a.x*b.y + b.x*c.y + a.y*c.x - c.x*b.y - b.x*a.y - a.x*c.y);
}

inline double calc_right(point &a,point &b,point &c)
{
    double x=det(a,b,c);
    return ( (b.x-a.x) * (c.y-a.y) / (b.y-a.y) + a.x );
}

void make_dp()
{

    int i,j,h,s;
    double dist;

    for(i=0;i<=lst;++i)
        for(j=0;j<=K;++j)
        dp[i][j]=inf;

    for(i=0;i<=lst;++i)
        for(j=0;j<=lst;++j)
            memo[i][j]=-1;

    dp[0][0]=0;

    for(i=1;i<=lst;++i)
        for(j=1;j<=K;++j)
    {

        if(j>i) continue;

        for(h=0;h<i;++h)
        {
            dist=0.0;
            if(memo[i][h]<0)
            {
                for(s=st[h-1].ind+1;s<st[i-1].ind;++s)
                {
                    if(h) dist+=min(calc_right(st[h-1],st[h],p[s]),calc_right(st[i-1],st[i],p[s])) - p[s].x;
                    else dist+=calc_right(st[i-1],st[i],p[s]) - p[s].x;
                }

                memo[i][h]=dist;
            }
            else dist=memo[i][h];

            dist+=dp[h][j-1];

            dp[i][j]=min(dp[i][j],dist);
        }
    }


    for(i=1;i<=lst;++i)
    {
        if(st[i].x>=st[i-1].x) continue;
        if(i<K) continue;
        dist=0.0;
         for(s=st[i].ind+1;s<=n;++s)
                {
                    dist+=calc_right(st[i-1],st[i],p[s]) - p[s].x;
                }

        dp[i][K]+=dist;
        dp[i][K]=min(dp[i][K],dp[i-1][K]);
    }


}

int main()
{
    read();
    convex_hull();

    if(st[lst-1].x>=st[lst].x)
    {
        st[lst+1]={0,(-st[lst-1].x) * (st[lst].y-st[lst-1].y) / (st[lst].x-st[lst-1].x) + st[lst-1].y };
        ++lst;
    }
    else
    {
        st[lst+1]=st[lst];
        ++lst;
        st[lst].y+=10;
    }
    st[lst].ind=n+1;

    if(K>lst) K=lst;

    make_dp();
    int i;
    //for(i=0;i<=lst;++i) if(dp[i][K]!=inf) cerr<<"ADF";
    cout<<fixed<<dp[lst][K];
    return 0;
}

void read()
{
    fin>>n>>K;
    for(int i=1;i<=n;++i)
        fin>>p[i].x>>p[i].y;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i) p[i].ind=i;
}

void convex_hull()
{
    int i;

    st[0]=p[0];
    st[++lst]=p[1];

    for(i=2;i<=n;++i)
    {
        while(lst>0 && det(st[lst-1],st[lst],p[i])<=0) --lst;
        st[++lst]=p[i];
    }

}
