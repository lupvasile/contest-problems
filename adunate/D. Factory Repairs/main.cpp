#include <iostream>

using namespace std;

#define nmax 200010

int v[nmax],n,k;

class C_AIB
{
private:
    int aib[nmax];
    int v[nmax];
public:
    C_AIB()
    {
        for(int i=1;i<=n;++i)
            aib[i]=v[i]=0;
    }

    int maxx;
    int query(int pos)
    {
        int res=0;
        for(;pos>0;pos-=(pos & (-pos))) res+=aib[pos];
        return res;
    }

    void update(int pos,int val)
    {
        val=min(v[pos]+val,maxx)-v[pos];
        v[pos]=min(v[pos]+val,maxx);
        if(val==0) return;
        for(;pos<=n;pos+=(pos & (-pos))) aib[pos]+=val;
    }
} ful,dam;

int main()
{
    int q,tip,d,a;
    cin>>n>>k>>ful.maxx>>dam.maxx>>q;

    for(;q;--q)
    {
        cin>>tip;
        if(tip==1)
        {
            cin>>d>>a;
            ful.update(d,a);
            dam.update(d,a);
        }
        else
        {
            cin>>d;
            cout<<dam.query(d-1)+ful.query(n)-ful.query(d+k-1)<<'\n';
        }
    }

    return 0;
}
