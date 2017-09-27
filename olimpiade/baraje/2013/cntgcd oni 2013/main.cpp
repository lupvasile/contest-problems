#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("cntgcd.in");
ofstream fout("cntgcd.out");

/// ///////////////////////////////////////////////////

#define nmax 1000010

int N,D;
long long v[nmax];
unordered_map<long long,long long> m;

void precalc()
{
    int i,j;
    for(i=1;i<nmax;++i) v[i]=i;
    for(i=2;i<nmax;++i)
    {
        if(v[i]==i)
            for(j=i;j<nmax;j+=i) v[j]=1ll* v[j]/i * (i-1);
    }

    for(i=2;i<nmax;++i)
        v[i]=2*v[i]+v[i-1];
}

long long gett(long long n)
{
    if(n<nmax) return v[n];
    if(m[n]) return m[n];

    int sqr=sqrt(n),i;
    long long res=1ll*n*n;

    for(i=2;i<=sqr;++i)
        res-=gett(n/i);

    ++sqr;
    for(i=n/sqr;i>=1;--i)
    {
        res-=1ll*(n/i-n/(i+1))*gett(i);
    }

    m[n]=res;

    return res;
}

int main()
{
    int i,n,j;
    long long res(1);
    fin>> N >> D;

    precalc();

    res=gett(N/D);
    cout<<(res-1)/2+1;
    return 0;
}

