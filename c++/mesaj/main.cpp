#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("mesaj.in");
ofstream g("mesaj.out");
int cate(int pos,string q);
string cuv,mesaj;
vector <string> v[26];
vector <string>::iterator it;
int n,m,i,k;
int d[1700];
int pos;
#define d (d+4)
#define hihihi 888888
#define cout g
int main()
{
  f>>n>>m;
  f>>mesaj;
  for(i=1; i<=n; ++i)
    {
      f>>cuv;
      v[cuv[cuv.length()-1]-'a'].push_back(cuv);
    }
  for(i=0; i<=m-1; ++i)
    {
      d[i]=d[i-1]+1;
      pos=mesaj[i]-'a';
      for(it=v[pos].begin(); it!=v[pos].end(); ++it)
        {
            k=cate(i,*it);
            d[i]=min(d[i],k);
        }

    }
  cout<<d[m-1];
  //cout<<'\n';
 // for(i=0;i<m;++i) cout<<i<<' '<<d[i]<<'\n';
  return 0;
}
int cate(int pos,string q)
{int i,k(0);
  for(i=q.length()-1; i>=0 && pos>=0; --i,--pos)
    while (mesaj[pos]!=q[i] && pos>=0) --pos,++k;
  if (i>=0) return hihihi;
  return k+d[pos];
}
