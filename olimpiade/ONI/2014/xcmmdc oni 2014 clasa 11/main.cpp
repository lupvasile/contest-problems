#include <bits/stdc++.h>

using namespace std;

ifstream f("xcmmdc.in");
ofstream g("xcmmdc.out");

#define cout g
#define nmax 1010

int n,m,k,q,x,i,cmc,j,step,maxl,minl;
int llog[nmax],v[nmax];
int rmq[10][nmax][nmax];

inline int gcd(int a,int b)
{
    while(a%=b) swap(a,b);
    return b;
}

inline int ggcd(int i,int j,int l)
{
    int lg=llog[l];
    return gcd(rmq[lg][i][j],gcd(rmq[lg][i+l-(1<<lg)][j],gcd(rmq[lg][i][j+l-(1<<lg)],rmq[lg][i+l-(1<<lg)][j+l-(1<<lg)])));
}

int main()
{
    f>>n>>m>>cmc>>q;
    x=max(m,n);
    for(i=2;i<=x;++i) llog[i]=llog[i>>1]+1;
    x=min(m,n);

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            f>>rmq[0][i][j];

    for(k=1;k<=llog[x];++k)
        for(i=1;i+(1<<k)-1<=n;++i)
        for(j=1;j+(1<<k)-1<=m;++j)
            rmq[k][i][j]=gcd(rmq[k-1][i][j], gcd( rmq[k-1][i][j+(1<<(k-1))], gcd(rmq[k-1][i + (1<<(k-1)) ][j],rmq[k-1][ i + (1<<(k-1)) ][ j + (1<<(k-1)) ])));

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        x=min(n-i+1,m-j+1);
        step=(1<<llog[x]);
        maxl=0;
        minl=x;
        for(;step;step>>=1)
        {
            if(maxl+step<=x)if(ggcd(i,j,maxl+step)>=cmc) maxl+=step;
            if(minl-step>0)if (ggcd(i,j,minl-step)<=cmc) minl-=step;
        }
        if(ggcd(i,j,minl)==cmc)
        {
            ++v[minl];
            --v[maxl+1];
        }
    }
    x=min(n,m)+1;
    for(i=1;i<=x;++i) v[i]+=v[i-1];
    for(;q;--q)
    {
        f>>x;
        cout<<v[x]<<'\n';
    }
    return 0;
}

