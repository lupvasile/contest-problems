#include <bits/stdc++.h>


using namespace std;

ifstream f("xmoto.in");
ofstream g("xmoto.out");

#define cout g
#define nmax 50001

int n,i,x,q;
int val[nmax];
vector<double> ss;
double L,a_now,k_now,sol;
struct
    {
    double a,b,ka,kb;
    int lim;
    } drum[nmax];
set<int> S;
unordered_map<int,int> mm;
pair<double,double> change[nmax];

int main()
    {
    f>>n>>L;
    for(i=1; i<=n; ++i)
        {
        f>>drum[i].a>>drum[i].b>>drum[i].ka>>drum[i].kb>>drum[i].lim;
        S.insert(drum[i].lim);
        }

    x=0;
    for(auto it:S) mm[it]=++x,val[x]=it;
    q=x;
    for(i=1; i<=n; ++i)
        {
        x=mm[drum[i].lim];
        change[x].first+=drum[i].b-drum[i].a;
        change[x].second+=drum[i].kb-drum[i].ka;
        a_now+=drum[i].a;
        k_now+=drum[i].ka;
        }
    if(val[q]<10000) val[++q]=10000;
    for(i=1;i<=q;++i)
    {
        if(val[i-1]>10000) break;
        sol=(L-k_now)/a_now;
        k_now+=change[i].second;
        a_now+=change[i].first;
        if(sol>10000) continue;
        if(sol>val[i-1] && sol<=val[i]) ss.push_back(sol);
    }
    cout<<ss.size()<<'\n';
    for(auto it:ss) cout<<fixed<<setprecision(6)<<it<<' ';
    return 0;
    }
