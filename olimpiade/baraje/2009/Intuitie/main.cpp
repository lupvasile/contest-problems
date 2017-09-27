#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("intuitie.in");
ofstream fout("intuitie.out");
/// ////////////////////////////////
#define mod 999017

#define combine(n,p,q,a,b)  (((((((((n)<<9)|(p))<<9)|(q))<<1)|(a))<<1)|(b))
#define get_p(x) ( (x>>11)&511 )
#define get_q(x) ( (x>>2)&511 )
#define get_n(x) ( (x>>20)&511 )
#define get_a(x) ( (x>>1)&1    )
#define get_b(x) (  x&1        )

int lim,plim,qlim;
unordered_map<int,int> dp;
unordered_map<int,bool> viz;


void af(vector<int> &v)
{
    for(auto it:v) cout<<it<<' ';
    cout<<'\n';
}

void rez_back()
{
    vector<int> v;
    int p,q,i,res=0;
    for(i=1;i<=lim;++i) v.push_back(i);

    do
    {
        p=0;q=0;
        for(i=1;i<lim-1;++i)
            if(v[i]>v[i-1]&&v[i]>v[i+1]) ++p;
        else if(v[i]<v[i-1] && v[i]<v[i+1]) ++q;

    if(p==plim && q==qlim) ++res;//,af(v);
    } while(next_permutation(v.begin(),v.end()));

    cerr<<res;
}

int gdp(int x)
{
    if(viz[x]) return dp[x];

    int p=get_p(x),q=get_q(x);

    if(abs(p-q)>1) return 0;
    int n=get_n(x),a=get_a(x),b=get_b(x);
    if(p+q>n-2) return 0;

    if(a==0 && b==0)
    {
        dp[x] =( gdp(combine(n-1,p,q,0,0))*(2*p+1) + ((p>0 && q>0) ? gdp(combine(n-1,p-1,q-1,0,0))*(n-1-2*p):0) + (q ? gdp(combine(n-1,p,q-1,1,0)):0) + (p ? gdp(combine(n-1,p-1,q,0,1)):0) )%mod;
    }

    else if(a==0 && b==1)
    {
        dp[x]=( gdp(combine(n-1,p,q,0,1))*(2*p+2) + ((p>0 && q>0) ? gdp(combine(n-1,p-1,q-1,0,1))*(n-2-2*p):0) + (q ? gdp(combine(n-1,p,q-1,1,1)):0) + (q ? gdp(combine(n-1,p,q-1,0,0)):0) )%mod;
    }
    else if(a==1 && b==0)
    {
        dp[x]=( gdp(combine(n-1,p,q,1,0))*(2*p)   + ((p>0 && q>0) ? gdp(combine(n-1,p-1,q-1,1,0))*(n-2*p):0)   + (p ? gdp(combine(n-1,p-1,q,1,1)):0) + (p ? gdp(combine(n-1,p-1,q,0,0)):0) )%mod;
    }
    else
    {
        dp[x]=( gdp(combine(n-1,p,q,1,1))*(2*p+1) + ((p>0 && q>0) ? gdp(combine(n-1,p-1,q-1,1,1))*(n-1-2*p):0) + (p ? gdp(combine(n-1,p-1,q,0,1)):0) + (q ? gdp(combine(n-1,p,q-1,1,0)):0) )%mod;
    }
    viz[x]=true;
    return dp[x];
}

int main()
{

    fin>>lim>>plim>>qlim;

    dp[combine(3,0,0,0,0)]=dp[combine(3,0,0,1,1)]=1;
    dp[combine(3,1,0,1,0)]=dp[combine(3,0,1,0,1)]=2;

    viz[combine(3,0,0,0,0)]=viz[combine(3,0,0,1,1)]=1;
    viz[combine(3,1,0,1,0)]=viz[combine(3,0,1,0,1)]=1;


    cout<<(gdp(combine(lim,plim,qlim,0,0)) + gdp(combine(lim,plim,qlim,0,1)) + gdp(combine(lim,plim,qlim,1,0)) + gdp(combine(lim,plim,qlim,1,1)))%mod;

    //rez_back();

    return 0;
}
