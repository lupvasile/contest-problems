#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

ifstream f("sdo.in");
ofstream g("sdo.out");
int n,i,k,v[3000005];
int pivot(int i,int j)
{
    --i;++j;
    int p=i+rand()%(j-i+1);
    while (1)
    {
        do ++i; while (v[i]<v[p]);
        do --j; while (v[j]>v[p]);
        if(i<j) swap(v[i],v[j]);
        else return j;
    }
}
int quickselect(int st,int dr,int k)
{
  if (st>=dr)
    {
      if (st==k) return v[k];
      return 0;
    }
  else
    {
      int p=pivot(st,dr);
      if (k<=p) quickselect(st,p,k);
      else quickselect(p+1,dr,k);
    }
}
int main()
{
    srand(time(0));
  f>>n>>k;
  for(i=1; i<=n; ++i) f>>v[i];
  g<<quickselect(1,n,k);
  return 0;
}
