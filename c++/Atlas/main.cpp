#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("atlas.in");
ofstream fout("atlas.out");

/// /////////////////////////////////

typedef long long ll;
#define nmax 100010
#define inf 0x3f3f3f3f

struct eee{
    ll maxVal,height;
    int maxRight,width;
};

int n,logg;
ll h[nmax],sum[nmax],lleft[nmax];
vector<eee> v;

class hello
{
private:
    int st[nmax];
    int len=0;
    public:
        int top()
        {
            return st[len];
        }
        int untop()
        {
            return st[len-1];
        }
        void push(int x)
        {
            st[++len]=x;
        }
        void pop()
        {
            --len;
        }
        void clr()
        {
            len=0;
        }
};
hello stiva;

void magic()
{
    int i;
    stiva.push(0);

        for(i=1;i<=n+1;++i)
        {
            while(h[stiva.top()]<=h[i])
            {
                v.push_back({1ll*(lleft[stiva.untop()]+min(h[i],h[stiva.untop()]) * (i-stiva.untop()-1) - (sum[i-1] - sum[stiva.untop()])), h[stiva.top()], i-1 , i-stiva.untop()-1 });
                stiva.pop();
            }
            lleft[i]=lleft[stiva.top()] + h[i]*(i - stiva.top() - 1) - (sum[i-1] - sum[stiva.top()]);
            stiva.push(i);
        }

    for(logg=1;logg<v.size();logg<<=1);
    logg>>=1;

}

void more_magic(ll x)
{
    int pos=v.size()-1;
    for(int step=logg;step;step>>=1)
    {
        if(pos-step>=0)
            if(v[pos-step].maxVal>=x) pos-=step;
    }
    int leftInd = v[pos].maxRight - v[pos].width;
    ll rem = x - lleft[leftInd] - (v[pos].width*v[pos].height - sum[v[pos].maxRight] + sum[leftInd]);
    rem+=v[pos].height*v[pos].width;
    ll gcd=__gcd(rem,1ll*v[pos].width);

    cout<<v[pos].maxRight<<' '<<rem/gcd<<'/'<<v[pos].width/gcd<<'\n';
}

int main()
{
    int T,i,q;
    ll x;
    fin>>T;
    for(;T;--T)
    {
        fin>>n;
        stiva.clr();
        v.clear();
        h[n+1]=inf;
        h[0]=inf+1;
        for(i=1;i<=n;++i)
        {
            fin>>h[i];
            sum[i]=h[i];
            sum[i]+=sum[i-1];
        }

        magic();

        fin>>q;
        for(;q;--q)
        {
            fin>>x;
            more_magic(x);
        }
    }

    return 0;
}
