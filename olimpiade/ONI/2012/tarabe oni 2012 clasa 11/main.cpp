#include <bits/stdc++.h>

using namespace std;

#define cout fout
#define nmax 200010
int gi();
ifstream fin("tarabe.in");
ofstream fout("tarabe.out");

long long st,dr,mid,res,n,k,x,y,nr;
int a[nmax],b[nmax],i;

inline long long ccount(long long val)
    {
    long long res(0);
    for(int i=1; i<=n; ++i) if(val>=a[i])res+=1ll*(val-a[i])/b[i]+1;
    return res;
    }

int main()
    {
    n=gi();
    k=gi();
    for(i=1; i<=n; ++i)
        {
        b[i]=gi();
        a[i]=gi();
        dr=max(dr,1ll*(k-1)*b[i]+a[i]);
        }
    st=1;
    while(st<=dr)
        {
        mid=(st+dr)/2;
        if(ccount(mid)<k) st=mid+1;
        else dr=mid-1;
        }
    for(i=1; i<=n; ++i)
        {
        if(st<a[i]) continue;
        nr=1ll*(st-a[i])/b[i]+1;
        res+=1ll*nr*a[i]+1ll*(nr-1)*nr/2*b[i];
        k-=nr;
        }
    res+=k*st;
    cout<<res;
    return 0;
    }

#define maxb 200000
int pos(maxb);
char buf[maxb];
int gi()
    {
    int nr(0);
    while(!(buf[pos]>='0' && buf[pos]<='9')) if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    while((buf[pos]>='0' && buf[pos]<='9'))
        {
        nr=nr*10+buf[pos]-'0';
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
        }
    return nr;
    }
