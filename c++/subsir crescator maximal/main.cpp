#include <iostream>
#include <fstream>

using namespace std;
#define nmax 100001
#define cout g
ifstream f("scmax.in");
ofstream g("scmax.out");
int n,v[nmax],i,p[nmax],poz;
int l[nmax],nr;
int cauta(int val)
{
    int s(0),d(nr),m;
    while (s<=d)
    {
        m=(s+d)/2;
        if(v[l[m]]<val && v[l[m+1]]>=val) return m;
        else if (v[l[m]]<val) s=m+1;
        else d=m-1;
    }
    return nr;
}
void afis(int x)
{
    if(p[x]) afis(p[x]);
    cout<<v[x]<<' ';
}
void afis2(int x)
{
    int c[nr],l(0);
    while (p[x]) c[++l]=v[x],x=p[x];
    c[++l]=v[x];
    for(;l;--l) cout<<c[l]<<' ';

}
int main()
{

    f>>n;
    for (i=1;i<=n;++i)
    {
        f>>v[i];
        poz=cauta(v[i]);
        l[poz+1]=i;
        p[i]=l[poz];
        nr=max(nr,poz+1);
    }
    cout<<nr<<'\n';
    afis(l[nr]);//afis2 nu se merita: nu is diferente de memorie sau timp
return 0;
}
