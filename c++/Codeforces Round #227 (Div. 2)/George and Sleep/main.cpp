#include <iostream>

using namespace std;
string s,t;
int cifra(char c)
{
  return c-'0';
}
char lit(int n)
{
  return n+'0';
}
int hs,ht,hr,ms,mt,mr;
int main()
{
  cin>>s;
  cin>>t;
  hs=cifra(s[0])*10+cifra(s[1]);
  ms=cifra(s[3])*10+cifra(s[4]);
  ht=cifra(t[0])*10+cifra(t[1]);
  mt=cifra(t[3])*10+cifra(t[4]);
  hr=hs-ht;
  mr=ms-mt;
  if(mr<0)
    {
      --hr;
      mr+=60;
    }
  if(hr<0) hr+=24;
  s[0]=lit(hr/10);
  s[1]=lit(hr%10);
  s[3]=lit(mr/10);
  s[4]=lit(mr%10);
  cout<<s;
  return 0;
}
