#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cumpanit.in");
ofstream g("cumpanit.out");
unsigned long long a,b,i,nr,sum_baza,prod_baza(1);
unsigned long long prim[]= {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
unsigned long long sol[7];
unsigned long long v[8000],l;
#define cout g
#define lprim 15

void d_back(unsigned long long k,unsigned long long s,unsigned long long nr)
{
  unsigned long long i,p=1;
  if(nr>b || nr<0) return;
  if(k && s)
    {
      for(i=1; i<=s-k+1; ++i)
        {
          p*=prim[sol[k]];
          if(p*nr>b) break;
          d_back(k-1,s-i,nr*p);
        }
    }
  if (s==0)
    if (nr>=a && nr<=b) v[++l]=nr;
}
void back(unsigned long long k)
{
  unsigned long long i;
  if (k<=5)
    for(i=sol[k-1]+1; i<=lprim; ++i)
      {
        sol[k]=i;
        sum_baza+=prim[sol[k]];
        if((1LL<<sum_baza)<=b)
          {
            d_back(k,sum_baza,1);
           // for(int j=1;j<=k;++j)cout<<prim[sol[j]]<<' ';
           // cout<<'\n';
            back(k+1);
          }
        sum_baza-=prim[sol[k]];
      }
      else
      {
         // for(int j=1;j<=k;++j)cout<<sol[j]<<' ';
      }
}
int main()
{
  f>>a>>b;
  back(1);
  sort(v+1,v+l+1);
  for(i=1; i<=l; ++i)cout<<v[i]<<'\n';
  return 0;
}
