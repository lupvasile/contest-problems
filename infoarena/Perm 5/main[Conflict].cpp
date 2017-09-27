#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("perm5.in");
ofstream fout("perm5.out");
/// ////////////////////////////////

#define nmax 2010
int pprev[nmax],fr[nmax];
double dp[nmax];
int dsc[nmax][320];
vector<int> primes;

bool prim(int x)
{
    for(int i=3;i<x;++i) if(x%i==0) return 0;
    return 1;
}


int main()
{
    int i,j,n,k;
    unsigned long long d,divv,aux;
    fin>>n;


    for(i=1;i<=n;++i)
        for(j=1;j<=i;++j)
    {
        if(j==i) d=i;
        else
        {
            descomp(j,vaux);
            for()
        }
        if(d>dp[i])
        {
            dp[i]=d;
            pprev[i]=j;
        }

    }

    j=n;
    for(;j;j-=pprev[j]) ++fr[pprev[j]];
    for(i=1;i<=n;++i)
        for(;fr[i];--fr[i])
    {
        for(j=start+1;j-start<i;++j) cout<<j<<' ';
        cout<<start<<' ';
        start+=i;
    }

    return 0;
}
