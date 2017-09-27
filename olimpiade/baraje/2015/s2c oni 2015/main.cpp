#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;

ifstream fin("s2c.in");
ofstream fout("s2c.out");

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

#define nmax 2010

int a[nmax],n,dp[nmax][nmax];
map<int,int> m;

void read_test();

class CAIB
{
private:
    int v[nmax];
public:
    void reset()
    {
        for(int i=0; i<=n; ++i) v[i]=0;
    }
    void update(int pos,int val)
    {
        if(v[pos]>=val) return;
        //for(;pos<=n;pos+=(pos&-pos)) v[pos]=max(v[pos],val);
        v[pos]=val;
    }
    int query(int pos)
    {
        /*int res=0;
        for(;pos;pos-=(pos&-pos)) res=max(res,v[pos]);
        return res;*/
        return v[pos];
    }
    void calc()
    {
        for(int i=0; i<=n; ++i) v[i]=max(v[i],v[i-1]);
    }
} aib[nmax];

void solve_test()
{
    int res=0,i,j;
    memset (dp,0,sizeof dp);
    for(i=0; i<=n; ++i) aib[i].reset();

    for(i=1; i<=n; ++i)
    {
        for(j=0; j<i; ++j)
        {
            dp[i][j]=max(dp[i][j],1+aib[j].query(a[i]-1));
            res=max(res,dp[i][j]);
            aib[i].update(a[j],dp[i][j]);
        }
        aib[i].calc();
    }
    cout<<res<<'\n';
}

int main()
{
    int t;
    fin>>t;
    for(; t; --t)
    {
        read_test();
        solve_test();
    }
}

void read_test()
{
    int i;
    m.clear();

    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>a[i];
        m[a[i]]=1;
    }

    a[0]=i=1;
    for(auto &it:m) it.second=++i;
    //for(auto it:m) cerr<<it.first<<' '<<it.second<<'\n';
    for(i=1; i<=n; ++i) a[i]=m[a[i]];
}
