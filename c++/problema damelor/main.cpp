#include <iostream>
#include <fstream>
using namespace std;

ifstream f("damesah.in");
ofstream g("damesah.out");
int n,sol;
#define nmax 16
bool p_diagonala[2*nmax],s_diagonala[2*nmax],coloana[nmax];
int l[nmax];
#define p_diagonala (p_diagonala+nmax)
#define cout g
void back(int k)
{
  int i;
  if(k==n+1)
    {
      if (sol==0)
        {
          for(i=1; i<=n; ++i) cout<<l[i]<<' ';
          cout<<'\n';
        }
      ++sol;
    }
    else
    {
        for(i=1;i<=n;++i)
        if (!coloana[i] && !p_diagonala[k-i] && !s_diagonala[k+i])
        {
            coloana[i]=p_diagonala[k-i]=s_diagonala[k+i]=true;
            l[k]=i;
            back(k+1);
            coloana[i]=p_diagonala[k-i]=s_diagonala[k+i]=false;
        }
    }
}
int main()
{
  f>>n;
  back(1);
  cout<<sol;
  return 0;
}
