#include <iostream>
#include <fstream>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("xor.in");
ofstream fout("xor.out");
/// ////////////////////////////////

int mod,x1,y1,x2,y2;

inline int calc(const int &x,const int &k)
{
    if((1<<k)>x) return 0;
    int res;
    res=((x>>(k+1))<<k);
    if(x&(1<<k)) res+=((x&((1<<k)-1))+1);
    return res;
}

inline int sum(const int &x,const int &y)
{
    int res=0,k,nx,ny,kmax=max(x,y);
    for(k=0;(1<<k)<=kmax;++k)
    {
        nx=calc(x,k);
        ny=calc(y,k);
        res=(res+(1ll*((1ll*nx*(y+1-ny)+1ll*(x+1-nx)*ny)%mod)<<k))%mod;
    }
    return res;
}

inline int solve()
{
   return (sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1)+2*mod)%mod;
}

#define maxb 100000
int pos(maxb);
char buf[maxb];

int gi()
{
    int n=0;
    while(buf[pos]<'0' || buf[pos]>'9')
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;

    while(!(buf[pos]<'0' || buf[pos]>'9'))
       {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
       }
       return n;
}

int main()
{
    int t;
    t=gi();
    mod=gi();
    for(;t;--t)
    {
        x1=gi();
        y1=gi();
        x2=gi();
        y2=gi();
        cout<<solve()<<'\n';
    }
    return 0;
}
