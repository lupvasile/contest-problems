#include <iostream>
#include <fstream>

using namespace std;

ifstream f("timp.in");
ofstream g("timp.out");
int n,k,v[3],p,poz,nr;
#define cout g
void rezolva(int a,int b)
{
  if(a && b)
    if (a<=b)
      {
        ++nr;
        rezolva(b-a,2*a);
        cout<<"0\n";
      }
    else
      {
          ++nr;
        rezolva(2*b,a-b);
        cout<<"1\n";
      }
      else {

          if (a==0) ++nr;
          cout<<nr<<'\n';
          if(!a)cout<<"0\n";
      }
}
int main()
{
  f>>n>>k;
  rezolva(k,n-k);
  return 0;
}
