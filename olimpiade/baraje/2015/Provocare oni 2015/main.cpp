#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

ifstream fin("provocare.in");
ofstream fout("provocare.out");

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
/// /////////////////////////////

int n,A,B;
map<pair<int,int> ,long long> c;
#define inf 9223372036854775807
long long get_comb(int n,int k)
{
    if(n-k<k) return get_comb(n,n-k);
    if(n==k || k==0) return 1;
    if(k==1) return n;
    if(k>n) return 0;

    if(c[{n,k}]) return (c[{n,k}]);

    if(k<=6)
    {
        int kfact=1,i,gg;
        long long res=1;
        for(i=2;i<=k;++i) kfact*=i;

        for(i=n;i>n-k;--i)
        {
            res=res*i;
            if(res<0)
            {
                res=inf;
                break;
            }
            gg=__gcd(res,1ll*kfact);
            kfact/=gg;
            res/=gg;
        }
        c[{n,k}]=res;
        return c[{n,k}];
    }

    c[{n,k}]=get_comb(n-1,k)+get_comb(n-1,k-1);
    if(c[{n,k}]<0) c[{n,k}]=inf;
    return c[{n,k}];

}

bool posibil(long long H)
{
    long long nr=0;
    int x,y;

    for(y=0;y<=H/B;++y)
    {
        x=1ll*(H-1ll*y*B)/A;
        nr+=get_comb(x+y+1,y+1);
        if(nr>=n) return true;
    }
    return false;
}

int main()
{
    int T;
    long long st,dr,mid,sol;

    fin>>T;
    for(;T;--T)
    {
        fin>>n>>A>>B;
        if(A>B) swap(A,B);

        st=0,dr=1ll*(n-1)*A;

        while(st<=dr)
        {
            mid=(st+dr)/2;

            if(posibil(mid))
            {
                sol=mid;
                dr=mid-1;
            }
            else st=mid+1;
        }

        cout<<sol<<'\n';
    }
    return 0;
}
