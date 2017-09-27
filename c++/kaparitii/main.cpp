#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream f("aparitii.in");
ofstream g("aparitii.out");

#define cout g

int n,x,v[10][10],k,i,j;
int main()
{
  //f.read(b,oo),p=b;
  f>>n;
  f>>k;
  for(;n;--n)
    {
      f>>x;
      i=0;
      while (x) ++v[++i][x%10],x/=10;
    }
   for(i=9;i;--i) for(j=0;j<=9;++j)if(v[i][j]%k)cout<<j;
  return 0;
}
