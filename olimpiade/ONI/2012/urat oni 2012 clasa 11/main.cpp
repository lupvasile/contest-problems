#include <bits/stdc++.h>

using namespace std;

ifstream f("urat.in");
ofstream g("urat.out");

#define cout g
#define mod 543217

int res,i,k,n,fact,a,b;

int main()
    {
    f>>n;
    cout<<1ll*n*n/2-1<<'\n';
    k=n/2;
    fact=1;
    for(i=1;i<k;++i) fact=1ll*fact*i%mod;
    if((n&1)==0) cout<<1ll*2*fact%mod*fact%mod<<'\n';
    else cout<<1ll*4*fact%mod*fact%mod*k%mod<<'\n';

    a=k+2;
    b=1;
    cout<<k<<' ';
    for(i=2;i<n;++i) if(i&1) cout<<b<<' ',++b;
    else cout<<a<<' ',++a;
    cout<<k+1;
    return 0;
    }

    /*
    bool us[nmax];
int sol[nmax];
int n;
int difmax;
bool ok;

void bback(int lev)
    {
    int i;
    if(lev==n+1)
        {
        int dif=0;
        for(i=2; i<=n; ++i) dif+=abs(sol[i]-sol[i-1]);
        difmax=max(difmax,dif);
        if(!ok) return;
        if(difmax!=dif) return;
        for(i=1; i<=n; ++i) cout<<sol[i]<<' ';
        cout<<'\n';
        }
    for(i=1; i<=n; ++i)
        if(!us[i])
            {
            us[i]=true;
            sol[lev]=i;
            bback(lev+1);
            us[i]=false;
            }
    }
    */
