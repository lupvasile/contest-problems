#include <iostream>

using namespace std;
int a,i,n,k,s[1000001],minn,maxx,nr,d;
int main()
{
    minn=99999999;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        s[a]++;
        if (a<minn) minn=a;
        if (a>maxx) maxx=a;
    }
    if(k>=minn-1) cout<<minn;
    else
    {
    for(i=1;i<=maxx+k;i++) s[i]+=s[i-1];
    nr=0;
    d=minn;
    while(nr<n)
    {
        nr=s[k];
        for(i=1;i<=maxx/d;i++) nr+=s[d*i+k]-s[d*i-1];
        d--;
    }
    cout<<d+1;
    }
    return 0;
}
