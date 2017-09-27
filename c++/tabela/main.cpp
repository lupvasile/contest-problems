#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream f("tabela.in");
ofstream g("tabela.out");
#define cout g
int a[100][100];
int l,c,k,maxx,nr;
bool gasit(int ln,int cl,int val)
{
    int i;
    for (i=1;i<cl;++i) if(a[ln][i]==val) return true;
    for(i=1;i<ln;++i) if(a[i][cl]==val) return true;
    return false;
}
void gen_tabel(int n)
{
  int i,j,minn;
  a[1][1]=1;
  for(i=1; i<=n; ++i)
    for(j=1; j<=n; ++j)
      {
        minn=0;
        while (gasit(i,j,minn)) ++minn;
        a[i][j]=minn;
      }
  for(i=1; i<=n; ++i)
    {
      for(j=1; j<=n; ++j) cout<<setw(3)<<a[i][j];
      cout<<"\n";
    }
}
int main()
{
  //gen_tabel(10);
  //cout<<(3^4);
  f>>l>>c;
  maxx=max(l,c);
  for(;maxx>(1<<k);++k);
  while (k)
  {
    if(l>(1<<(k-1)) && c>(1<<(k-1)));
    else nr+=(1<<(k-1));
    if(l>(1<<(k-1))) l-=(1<<(k-1));
    if(c>(1<<(k-1))) c-=(1<<(k-1));
    maxx=max(l,c);
    k=0;
  for(;maxx>(1<<k);++k);
  }
  cout<<nr;
  return 0;
}
