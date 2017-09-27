#include <bits/stdc++.h>

using namespace std;

ifstream f("sirag2.in");
ofstream g("sirag2.out");

#define cout g
#define nmax 100001
#define ent cout<<'\n';
int n,L,i;
int nnext[nmax],dp[nmax],rasp;
char v[nmax];
deque <int> dq;

void solve()
    {
    f>>n>>L;
    f>>v+1;
    nnext[n+1]=n+1;
    dq.clear();
    rasp=0;
    for(i=n; i; --i)
        {
        if(v[i]=='*') if(i+L<=n)nnext[i]=nnext[i+L];
        else nnext[i]=n+1;
        else nnext[i]=i;
        }

    for(i=n; i; --i)

        {
        if(n-L<i)
        {
            dp[i]=1;
            continue;
        }
        if(v[i]=='*') dp[i]=1+dp[i+L];
        else if(v[nnext[i+L]]==v[i])dp[i]=1+dp[i+L];
        else if(v[i+L]=='*') dp[i]=(nnext[i+L]-i-1+L)/L;
        else dp[i]=1;
        }
    for(i=1;i<=n;++i)
    {
        while(dq.size() && i-dq.front()>=L) dq.pop_front();
        while(dq.size() && dp[dq.back()]>dp[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=L)rasp=max(rasp,dp[dq.front()]);
    }
    /*for(i=1;i<=n;++i) cout<<i<<' ';
    ent;
    for(i=1;i<=n;++i) cout<<v[i]<<' ';
    ent;
    for(i=1;i<=n;++i) cout<<nnext[i]<<' ';
    ent;
    for(i=1;i<=n;++i) cout<<dp[i]<<' ';
    ent;*/
    cout<<rasp*L<<'\n';
    }

int main()
    {
    int t;
    f>>t;
    for(;t;--t) solve();
    return 0;
    }
