#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

long long step;
int i,rep,n,k;
stringstream ss;
int main()
    {
    freopen("teanc.in","r",stdin);
    freopen("teanc.out","w",stdout);

    scanf("%d",&n);
    if(n>1999996635) k=63245;
    else
        {
        for(step=1; step*step<1ll*2*n; step<<=1);
        step>>=1;
        for(; step; --step)
            {
            if(1ll*(k+step)*(k+step+1)<((1ll*n)*2)) k+=step;
            }
        }
    rep=1ll*(n-k*(k+1)/2);
    ss<<k+1<<'\n';
    if(rep>k) ss<<rep<<' ';
    for(i=k; i>0; --i) if(i==rep) ss<<i<<' '<<i<<' ';
        else ss<<i<<' ';
    cout<<ss.str();
    return 0;
    }
