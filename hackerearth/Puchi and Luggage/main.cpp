#include <iostream>

using namespace std;

#define nmax 100010
#define amax 1000010

int n,v[nmax],res[nmax];

void read_array()
{
    int i;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
}

class
{
private:
    int aib[amax];
public:
    void reset()
    {
        for(int i=0;i<amax;++i) aib[i]=0;
    }

    void add(int p)
    {
        for(;p<amax;p+=(p&(-p))) ++aib[p];
    }

    int query(int pos)
    {
        int res=0;
        for(;pos;pos-=(pos&(-pos))) res+=aib[pos];
        return res;
    }

}aib;

int main()
{
    int T,i;
    cin>>T;
    for(;T;--T)
    {
        aib.reset();
        read_array();
        for(i=n;i>0;--i)
        {
            res[i]=aib.query(v[i]-1);
            aib.add(v[i]);
        }
        for(i=1;i<=n;++i) cout<<res[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
