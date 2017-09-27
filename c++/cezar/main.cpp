#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#define cout g
ifstream f("cezar.in");
ofstream g("cezar.out");
string p,s,v[260];
int lcuv[260],nrcuv;
int l,i,k[10],poz,m,j;
bool litera(char c)
{
  return (c>='A' && c<='Z');
}
char depl(char c,int d)
{ char x;
    x=c-d;
    if(x<'A') x+=26;
    return x;
}
int main()
{
  do
    {
      f>>p;
      lcuv[++nrcuv]=p.size();
      if(litera(p[0])) s+=p;
    }
  while (litera(p[0]));
  --nrcuv;
  //cout<<s;
  k[0]=atoi(p.c_str());
  for(i=1; i<=9; ++i) f>>k[i];
  poz=0;
  m=0;
  while (poz<s.size())
    {
      v[++m]=s.substr(poz,10);
      poz+=10;
    }
  s="";
  for(i=1; i<=m; ++i)
    {
      for (j=0; j<v[i].size(); ++j) v[i][j]=depl(v[i][j],k[j]);
      s+=v[i];
   //   cout<<v[i]<<'\n';
    }
  poz=0;
  for(i=1; i<=nrcuv; ++i)
    {
      cout<<s.substr(poz,lcuv[i])<<' ';
      poz+=lcuv[i];
    }

//cout<<s;
  return 0;
}
