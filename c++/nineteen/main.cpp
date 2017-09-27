#include <iostream>
#include <string>
#include <fstream>
//#define cin f
using namespace std;
//ifstream f("date.in");
string s;
int i;
int nn,ni,ne,nt,maxx;
int main()
{
  cin>>s;
  for(i=0; i<s.length(); ++i)
    {
      switch (s[i])
        {
        case 'n':
          ++nn;
          break;
        case 'i':
          ++ni;
          break;
        case 'e':
          ++ne;
          break;
        case 't':
          ++nt;
          break;
        }
    }
  ne/=3;
  maxx=ne;
  maxx=min(maxx,ni);
  maxx=min(maxx,nt);
  --nn;
  if (maxx>=0 && nn>=0)cout<<min(maxx,nn/2);
  else cout<<0;

  return 0;
}
