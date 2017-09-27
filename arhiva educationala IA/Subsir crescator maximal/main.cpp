#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("scmax.in");
ofstream fout("scmax.out");
/// ////////////////////////////////

#define nmax 100010

int dad[nmax],v[nmax],dp[nmax],n,lmax;

void afis(int p)
{
    if(dad[p]) afis(dad[p]);
    cout<<v[p]<<' ';
}

int search(int val)
{
    int res(0),step;
    for(step=1;step<=lmax;step<<=1);
    for(;step;step>>=1)
        if(res+step<=lmax)
            if(v[dp[res+step]]<val) res+=step;

    return res;
}

int main()
{
    int i,pos;
    fin>>n;
    v[0]=INFINITY;
    for(i=1;i<=n;++i)
    {
        fin>>v[i];
        pos=search(v[i]);
        lmax=max(lmax,pos+1);
        dp[pos+1]=i;
        dad[i]=dp[pos];
    }

    cout<<lmax<<'\n';
    afis(dp[lmax]);
    return 0;
}
