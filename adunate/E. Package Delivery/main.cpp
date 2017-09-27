#include <bits/stdc++.h>

using namespace std;

#define nmax 200010

pair<int,int> statie[nmax];
int cost[nmax];
int rmq[20][nmax];
int n;

#define y second
#define x first

void build()
{
    int i,k;
    for(i=1;i<=n;++i) rmq[0][i]=i;

    for(k=1;(1<<k)<=n;++k)
        for(i=1;i+(1<<k)-1<=n;++i)
            rmq[k][i]=(statie[rmq[k-1][i]].y<statie[rmq[k-1][i+(1<<(k-1))]].y ? rmq[k-1][i]:rmq[k-1][i+(1<<(k-1))]);
}

int main()
{
    int d,vol,i,k;
    cin>>d>>vol>>n;

    for(i=1;i<=n;++i)
        cin>>statie[i].x>>statie[i].y;

    statie[++n]={0,0};
    statie[++n]={d,0};

    sort(statie+1,statie+n+1);
    build();

    for(curr=1;curr!=n;;)
    {
        st_minn=curr+1;

    }

    return 0;
}
