#include <bits/stdc++.h>

using namespace std;

ifstream f("albinuta.in");
ofstream g("albinuta.out");
#define nmax 52
#define cout g
int n,q,i,j,period(1),now,t,nnext,decalaj,nr,x;
int sz[nmax],mom[1000000],ad[nmax][nmax];

int main()
    {
    f>>n>>q;
    for(i=1; i<=n; ++i)
        {
        f>>sz[i];
        for(j=0; j<sz[i]; ++j) f>>ad[i][j];
        period=sz[i]*period/__gcd(sz[i],period);
        }


    now=ad[1][0];
    mom[1]=1;
   for(t=2; t<=n*period; ++t)
        {
        mom[t]=now;
        nnext=(t-1)%sz[now];
        now=ad[now][nnext];
        }
    period=n*period;
    for(;q;--q)
    {
        f>>x;
        //if(x<=period) cout<<mom[x]<<'\n';
         cout<<mom[(x-1)%period+1]<<'\n';
    }

    return 0;
    }

