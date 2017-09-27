#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("ciocolata.in");
ofstream g("ciocolata.out");

#define cout g
#define nmax (1<<15)

int r,nr_buc,x,i,t;
int dp[nmax];

int dif(int x)
{
    int k,i,nx;
    if(dp[x]<3) return dp[x];

    //for(k=14;(((1<<k)&x)==0) && k>=0;--k);
    for(k=0;k<15;++k)
        if((1<<k)&x){
    if(k==0)
    {
        dp[x]=min(dp[x],2);
     //   return dp[x];
    }
    if(k==1)
    {
        dp[x]=min(dp[x],1-dif(x^(1<<k)^1));
       // return dp[x];
    }
    if(k>1){
    nx=x^(1<<k)^(1<<(k-1));
    dp[x]=min(dp[x],1-dif(nx));
    for(i=2;i<=(k+2)/2;++i)
    {
        nx=x^(1<<k)^(1<<(i-2))^(1<<(k-i));
        dp[x]=min(dp[x],-dif(nx));
    }
    }
    }
    return dp[x];
}
int gi();
int main()
{
    t=gi();
    for(i=0;i<nmax;++i) dp[i]=3;
    dp[0]=0;
    int a,b;
    for(;t;--t)
    {
        r=0;
        nr_buc=0;
        for(i=0;i<15;++i)
        {
            x=gi();
            r=r^((x&1)<<i);
            nr_buc=nr_buc+x*(i+2);
        }
        a=(nr_buc+dif(r))/2;
        b=nr_buc-a;
        cout<<a<<' '<<b<<'\n';
    }
  ///  for(i=1;i<=100;++i) cout<<-dif(i)<<'\n';
//cout<<-dif(50);
    return 0;
}

#define nb 1600
int p(nb);
char b[nb];
int gi()
{
    int n=0;
    while (b[p]<'0' || b[p]>'9')
        if(++p>=nb) f.read(b,nb),p=0;
    while (b[p]>='0' && b[p]<='9')
    {
        n=n*10+b[p]-'0';
        if(++p>=nb) f.read(b,nb),p=0;
    }
    return n;
}
