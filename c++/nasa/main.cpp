//#include <iostream>
//#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;

//ifstream f("nasa.in");
//ofstream g("nasa.out");

char prim[3129],ciur[12500010];
long long  x;
int a,b,pp,bb,nr,i;
#define cout g
void make_prime(int n)
{
  int i,j;
  for(i=1; ((i*i)<<2)+(i<<2)+1<=n; ++i)
    if (((prim[i>>3]&(1<<(i&7)))==0))
      for(j=((i*i)<<1) + (i<<1); (j<<1)+1<=n; j+=(i<<1)+1)
        prim[j>>3] |= (1<<(j & 7));

}
int main()
{
  //f>>a>>b;
  FILE *f=freopen("nasa.in","r",stdin);
  FILE *g=freopen("nasa.out","w",stdout);
  scanf("%d %d",&a,&b);
  bb=sqrt(b);
  make_prime(bb);
  nr=b-a+1-(b>>2)+(a>>2);
  if((a&3)==0) --nr;
  b=b-a;
  for(i=1; (i<<1)+1<=bb; ++i) if ((prim[i>>3]&(1<<(i&7)))==0)
      {
        pp=((i*i)<<2)+(i<<2)+1;
        x=a%pp;
        if (x) x=pp-x;
        for(; x<=b; x+=pp)
          {
            if((x+a)%4) if((ciur[x>>3]&(1<<(x & 7)))==0) --nr;
            ciur[x>>3] |= (1<<(x & 7));
          }
      }
  /*x=a&3;
  if (x) x=4-x;
  for(; x<=b; x+=4)
    {
      if((ciur[x>>3]&(1<<(x & 7)))==0) --nr;
      ciur[x>>3] |= (1<<(x & 7));
    }*/
  //for(i=0;i<=b;++i) if ((ciur[i>>3]&(1<<(i&7)))==0) ++nr;
  /*cout<<2<<' ';
  for(i=1;(i<<1)+1<=bb;++i){++nr;if(nr%60==0) cout<<"\n";
   if ((prim[i>>3]&(1<<(i&7)))==0) cout<<2*i+1<<' ';
  }*/
  printf("%d",nr);
  return 0;
}
