#include <iostream>
#include <fstream>

using namespace std;

ifstream f("flip.in");
ofstream g("flip.out");
#define nmax 17
#define foor(i,a,b) for(i=1;i<=b;++i)
#define cout g
int a[nmax][nmax],n,m;
int limita_linii,limita_coloane,l,c;
long long sum,maxx(-9999999999),s;
int i,j;

int main()
{
  f>>n;
  f>>m;
  foor(i,1,n)
  foor(j,1,m) f>>a[i][j];
  limita_linii=(1<<n);
  for(l=0; l<limita_linii; ++l)
      {
        sum=0;
        foor(j,1,m)
        {
            s=0;
            foor(i,1,n)
            if ( (l&(1<<(i-1))) ^ (c&(1<<(j-1))) ) s-=a[i][j];
        else s+=a[i][j];
        sum+=max(s,-s);
        }
        maxx=max(sum,maxx);
      }
  cout<<maxx;
  return 0;
}
