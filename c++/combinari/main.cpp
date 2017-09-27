#include <iostream>
#include <fstream>

using namespace std;

ifstream f("combinari.in");
ofstream g("combinari.out");
int s[20],n,l;
#define cout g
void back(int k)
{
  int i;
  for(i=s[k-1]+1; i<=n; ++i)
    {
      s[k]=i;
      if(k==l)
        {
          for(int j=1; j<=l; ++j) cout<<s[j]<<' ';
          cout<<'\n';
        }
        else back(k+1);
    }
}
int main()
{
  f>>n>>l;
  back(1);
  return 0;
}
