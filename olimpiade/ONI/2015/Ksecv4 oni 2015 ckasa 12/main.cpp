#include <cstdio>

using namespace std;

#define numar long long
#define mmax 2046
#define nmax 1000010

void citire();

numar a[mmax],b[mmax],v[nmax];
numar st=0,dr=(1ll<<60),mid;
int n,m,k;

bool posibil(numar val)
{
    numar minn,maxx;
    int nr=0,i;

    val<<=1;

    minn=maxx=v[0];
    for(i=0; i<n; ++i)
    {
        if(minn>v[i])
        {
            minn=v[i];
            if((maxx-minn)>val)
            {
                maxx=v[i];
                ++nr;
                if(nr==k) break;
            }
        }
        if(maxx<v[i])
        {
            maxx=v[i];
            if((maxx-minn)>val)
            {
                minn=v[i];
                ++nr;
                if(nr==k) break;
            }
        }


    }
    return nr<k;
}
int main()
{

    citire();

    while(st<=dr)
    {
        mid=(st+dr)>>1;
        if(posibil(mid)) dr=mid-1;
        else st=mid+1;
    }
    printf("%lld",st);
    return 0;
}
void citire()
{
    freopen("ksecv4.in","r",stdin);
    freopen("ksecv4.out","w",stdout);
    int i;
    scanf("%d%d%d",&n,&k,&m);
    for(i=0; i<m; ++i) scanf("%lld",a+i);
    for(i=0; i<m; ++i) scanf("%lld",b+i);
    for(i=0; i<n; ++i) v[i]=a[i%m]^b[i/m];
}
