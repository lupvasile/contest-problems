#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

//ifstream f("date.in");
FILE *f=fopen("date.in","r");
int i,x,n;
int nr_1[50000],ciur[50000],nr_2[50000];
void descomp_1(int x)
{
  int i;
  while ((x&1)==0) ++nr_1[2],x>>=1;
  for(i=3; i*i<=x; i+=2) while (x%i==0)
      {
        ++nr_1[i];
        x/=i;
      }
  if (x>1) ++nr_1[x];
}
void erast(int n)
{
  long long j;
  int i;
  for(i=2; i<=n; ++i)
    {
      if(ciur[i]==0)
        {
          for(j=1LL*i*i; j<=n; j+=i) ciur[j]=i;
          ciur[i]=i;
        }
    }
}
void descomp_2(int x)
{
  if (x<=1)return;
  ++nr_2[ciur[x]];
  return descomp_2(x/ciur[x]);
}
void eval()
{
  for(int i=1; i<=50000; ++i) if(nr_1[i]!=nr_2[i])
      {
        cout<<"eroare "<<x<<'\n';
        return;
      }
  //  cout<<"ok "<<x<<'\n';
}
#define maxb 65536
char buf[maxb];
int p(maxb);
/*int gI()
{
  int nr(0);
  while (buf[p]<'0' || buf[p]>'9') if(++p>=maxb) f.read(buf,maxb),p=0;
  while (buf[p]>='0' && buf[p]<='9')
    {
      nr=nr*10+buf[p]-'0';
      if(++p>=maxb) f.read(buf,maxb),p=0;
    }
  return nr;
}*/
int main()
{
  fscanf(f,"%d",&n);
  //erast(50000);
  //cout<<n<<'\n';
  for(i=1; i<=n; ++i)
    {
      fscanf(f,"%d",&x);
      //cout<<x<<'\n';
      for(int i=1; i<=50000; ++i) nr_2[i]=0;
      descomp_1(x);
      //descomp_2(x);
      //   eval();
    }
//f.close();
//ofstream f("date.in");
  /*f<<50000<<'\n';
  for(i=1;i<=50000;++i) f<<i<<'\n';*/
  return 0;
}
