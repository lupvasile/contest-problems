#include<bits/stdc++.h>

using namespace std;

ifstream f("poligon5.in");
ofstream g("poligon5.out");

#define nmax 201
#define inf 0x3f3f3f3f
#define int long long

struct punct
    {
    int x,y;
    bool operator !=(punct a)const
        {
        return x!=a.x || y!=a.y;
        }
    };
punct operator+(punct a,punct b)
    {
    punct res;
    res= {a.x+b.x,a.y+b.y};
    return res;
    }

int n,T,i,pstart,rasp;
vector<punct> PCT[nmax];
punct v[nmax];
int dp[2][20001];

void make_PCT(int now)
    {
    int ant=(n+now-2)%n+1;
    punct p,r;

    if(abs(v[now].x-v[ant].x) && abs(v[now].y-v[ant].y))
        {
        int gcd=__gcd(abs(v[now].x-v[ant].x),abs(v[now].y-v[ant].y));
        r= {abs(v[now].x-v[ant].x)/gcd,abs(v[now].y-v[ant].y)/gcd};
        }
    else
        {
        if(v[now].x==v[ant].x) r= {0,1};
        if(v[now].y==v[ant].y) r= {1,0};
        }
    if(v[now].x-v[ant].x<0) r.x=-r.x;
    if(v[now].y-v[ant].y<0) r.y=-r.y;

    for(p=v[ant]+r; p!=v[now]; p=p+r)
        PCT[now].push_back(p);
    }

int dist(punct a,punct b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int make_dp(int lstart,int p)
{
    int i,stp=0,now=lstart,j,ant;
    for(i=0;i<PCT[now].size();++i) dp[0][i]=inf;
    dp[0][p]=0;
    ant=now;
    for(stp^=1,now=now%n+1;now!=lstart;now=now%n+1,stp^=1)
    {
        for(i=0;i<PCT[now].size();++i) dp[stp][i]=inf;
        for(i=0;i<PCT[now].size();++i)
            for(j=0;j<PCT[ant].size();++j)
                dp[stp][i]=min(dp[stp][i],dp[stp^1][j]+dist(PCT[ant][j],PCT[now][i]));

        ant=now;
    }
    dp[stp][p]=inf;
    for(j=0;j<PCT[ant].size();++j)
        dp[stp][p]=min(dp[stp][p],dp[stp^1][j]+dist(PCT[ant][j],PCT[now][p]));

    return dp[stp][p];
}
#undef int
int main()
    {
    f>>T;
    for(; T; --T)
        {
        f>>n;
        for(i=1; i<=n; ++i) f>>v[i].x>>v[i].y;
        for(i=1; i<=n; ++i)
            {
            make_PCT(i);
            if(PCT[i].size()<PCT[pstart].size() || pstart==0) pstart=i;
            }

        rasp=inf;
        for(i=0;i<PCT[pstart].size();++i)
            rasp=min(make_dp(pstart,i),rasp);

        g<<rasp<<'\n';
        }


    return 0;
    }
