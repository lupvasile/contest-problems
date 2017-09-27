#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("praslea.in");
ofstream fout("praslea.out");
/// ////////////////////////////////

void read();

#define nmax 520

static int dp[2][nmax],n,rmax,x;
struct szm
{
    int f,r;
} zmeu[nmax];
struct sev
{
    int timp,tip,z;
    bool operator < (const sev &o) const
    {
        if(timp!=o.timp) return timp<o.timp;
        return tip<o.tip;
    }
};
vector<sev> ev;
set<int> zmei;
long long res;

int make_dp()
{
    int i;
    x=0;
    memset(dp,0,sizeof dp);

    for(auto it:zmei)
    {
        x^=1;
        for(i=1; i<=rmax; ++i)
        {
            if(dp[x][i-1]>dp[x^1][i]) dp[x][i]=dp[x][i-1];
            else dp[x][i]=dp[x^1][i];
            if(i>=zmeu[it].r && dp[x][i]<zmeu[it].f+dp[x^1][i-zmeu[it].r]) dp[x][i]=zmeu[it].f+dp[x^1][i-zmeu[it].r];
        }
    }
    return dp[x][rmax];
}

int cont_dp(int it)
{
    x^=1;
    for(int i=1; i<=rmax; ++i)
    {
        if(dp[x][i-1]>dp[x^1][i]) dp[x][i]=dp[x][i-1];
        else dp[x][i]=dp[x^1][i];
        if(i>=zmeu[it].r && dp[x][i]<zmeu[it].f+dp[x^1][i-zmeu[it].r]) dp[x][i]=zmeu[it].f+dp[x^1][i-zmeu[it].r];
    }
    return dp[x][rmax];
}

int main()
{
    read();
    sort(ev.begin(),ev.end());
    int n=ev.size();
    for(int i=0; i<n; ++i)
    {
        if(i && ev[i].timp!=ev[i-1].timp)
        {
            if(i>1 && ev[i-1].tip==1 && ev[i-2].tip==1 && ev[i-1].timp!=ev[i-2].timp) res+=1ll*cont_dp(ev[i-1].z)*(ev[i].timp-ev[i-1].timp);
            else res+=1ll*make_dp()*(ev[i].timp-ev[i-1].timp);
        }

        if(ev[i].tip==1) zmei.insert(ev[i].z);
        else zmei.erase(ev[i].z);

    }

    cout<<res;

    return 0;
}

void read()
{
    int i,a,b;
    fin>>n>>rmax;

    for(i=1; i<=n; ++i)
    {
        fin>>a>>b>>zmeu[i].f>>zmeu[i].r;
        ev.push_back({a,1,i});
        ev.push_back({b+1,0,i});
    }
}
