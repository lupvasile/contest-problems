#include <set>
#include <iostream>
#include <fstream>
#include <tr1/unordered_map>
#include <cstring>

using namespace std;

ifstream f("pikachu.in");
ofstream g("pikachu.out");

#define cout g
#define nmax 100001
#define int long long

int v[nmax],val[nmax];
set<int> s;
tr1::unordered_map<int,int> mp;
int n,k,lim,i,timp,tmin(1ll<<60),new_med,ss,sd,x;
int on[nmax];
class c_aib
    {
    public:
        int aib[nmax];
        void add(int pos,int val)
            {
            for(int i=pos; i<=lim; i+=(i&(-i))) aib[i]+=val;
            }
        int query(int pos)
            {
            int res(0);
            if(pos)
                for(; pos; pos-=(pos&(-pos))) res+=aib[pos];
            return res;
            }
        void reset()
            {
            memset(aib,0,sizeof aib);
            }
        int find_med(int k)
            {
            int x=0,step;
            for(step=1; step<=lim; step<<=1 );
            step>>=1;
            for(; step; step>>=1)
                {
                if(x+step<=lim)
                    if(query(x+step)<((k+1)>>1) || (on[x+step] && query(x+step)==((k+1)>>1)))
                        x+=step;
                }
            return x;
            }
    };

c_aib aib,sum_aib;
#undef int
int main()
#define int long long
    {
    f>>n>>k;
  //  aib.reset();
   // sum_aib.reset();
    for(i=1; i<=n; ++i)
        {
        f>>v[i];
        s.insert(v[i]);
        }
    for(auto it:s) mp[it]=++lim,val[lim]=it;

    for(i=1; i<=n; ++i)
        {
        aib.add(mp[v[i]],1);
        ++on[mp[v[i]]];
        sum_aib.add(mp[v[i]],v[i]);
        if(i-k>0)
            {
            aib.add(mp[v[i-k]],-1);
            --on[mp[v[i-k]]];
            sum_aib.add(mp[v[i-k]],-v[i-k]);
            }
        new_med=aib.find_med(min(i,k));

        ss=sum_aib.query(new_med-1);
        sd=sum_aib.query(lim)-sum_aib.query(new_med);

        timp=val[new_med]*aib.query(new_med-1)-ss+sd-val[new_med]*(aib.query(lim)-aib.query(new_med));
        if(i>=k)tmin=min(tmin,timp);
        }
    cout<<tmin;
    return 0;
    }
