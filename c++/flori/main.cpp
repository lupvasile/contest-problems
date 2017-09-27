#include <iostream>
#include <fstream>
using namespace std;

ifstream f("flori.in");
ofstream g("flori.out");
int floarea[1001],grupa[1001],l,gr,v[1001];
#define maxb 8192
char b[maxb];
int p=maxb-1;
int maxx,i,j,k,n,x,m,q;
#define cout g
int getInt()
{
    int nr=0;
    while (b[p]<'0' || b[p]>'9') if (++p>=maxb)f.read(b,maxb),p=0;
    while (b[p]>='0' && b[p]<='9')
    {
        nr=nr*10+b[p]-'0';
        if (++p>=maxb)f.read(b,maxb),p=0;
    }
    return nr;
}
int main()
{
  n=getInt();
  k=getInt();
  for(i=1; i<=n; ++i)
    {
      gr=l+1;
      v[gr]=i;
      grupa[i]=gr;
      for(q=1; q<=k; ++q)
        {
          x=getInt();
          if (floarea[x])
            {
              gr=min(gr,floarea[x]);
              v[floarea[x]]=i;
            }
          else floarea[x]=gr,v[floarea[x]]=i;
          maxx=max(x,maxx);
        }
      m=max(maxx,n);
      for(; m>=0; --m)
        {
          if (v[floarea[m]]==i) floarea[m]=gr;
          if (v[grupa[m]]==i) grupa[m]=gr;
        }
      l=max(l,gr);
      //for(j=1;j<=n;++j) cout<<grupa[j]<<' ';
      //cout<<" asdfa ";
      //for(j=1;j<=n;++j) cout<<floarea[j]<<' ';
      //cout<<'\n';
    }

  //for(i=1; i<=l; ++i)v[i]=1;
  for(i=1; i<=n; ++i) if(grupa[i])
      {
        cout<<i<<' ';
        for(j=i+1; j<=n; ++j)
          if (grupa[i]==grupa[j]) cout<<j<<' ',grupa[j]=0;
        cout<<'\n';
        grupa[i]=0;
      }
  return 0;
}
