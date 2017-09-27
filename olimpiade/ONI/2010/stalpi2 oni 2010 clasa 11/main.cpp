#include <bits/stdc++.h>

using namespace std;

ifstream f("stalpi2.in");
ofstream g("stalpi2.out");

#define cout g
#define nmax 52
#define inf 0x3f3f3f3f

int i,n,E,step,d;
int pos[nmax];
int dp[nmax][10001];
int dq[10002];

bool valid(int dist)
{
    int i,j,st,dr;
    memset(dp,inf,sizeof dp);
    dp[1][0]=0;
    st=0;dr=-1;
    for(i=2;i<n;++i)
        for(j=0;j<=pos[n];++j)
    {
        while(st<=dr && j-dq[st]>dist) ++st;
        while(st<=dr && dp[i-1][dq[dr]]>=dp[i-1][j]) --dr;
        dq[++dr]=j;

        dp[i][j]=dp[i-1][dq[st]]+abs(pos[i]-j);
    }
    for(i=0;i<=dist;++i) if(dp[n-1][pos[n]-i]<=E) return true;
    return false;
}

int main()
{
    f>>n>>E;
    for(i=2;i<=n;++i) f>>pos[i];
    for(step=1;step<=pos[n];step<<=1);
    step>>=1;
    d=pos[n];
    for(;step;step>>=1)
        if(valid(d-step)) d-=step;

    cout<<d;
    return 0;
}
