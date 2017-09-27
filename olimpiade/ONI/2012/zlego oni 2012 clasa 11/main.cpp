#include <bits/stdc++.h>
 
using namespace std;
 
ifstream f("zlego.in");
ofstream g("zlego.out");
 
#define nmax 250001
#define cout g
int pref[nmax],s[nmax],be[nmax];
long long cost[nmax];
int t,n,i,k;
 
void prefix()
    {
    pref[1]=0;
    for(i=2; i<=n; ++i)
        {
        k=pref[i-1];
        while(s[k+1]!=s[i] && k) k=pref[k];
        if(s[k+1]==s[i]) ++k;
        pref[i]=k;
        cost[k]+=be[i];
        }
    }
 
int main()
    {
    f>>t;
    for(; t; --t)
        {
        f>>n;
        for(i=1; i<=n; ++i) f>>s[i];
        for(i=1; i<=n; ++i) f>>be[i];
        prefix();
        for(i=n; i>=1; --i)
            {
            cost[pref[i]]+=cost[i];
            cost[i]+=be[i];
            }
        for(i=1; i<=n; ++i) cout<<cost[i]<<'\n';
        for(i=0; i<=n; ++i) cost[i]=0;
        }
    return 0;
    }