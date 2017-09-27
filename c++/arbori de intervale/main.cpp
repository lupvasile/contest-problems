#include <iostream>
#include <fstream>

using namespace std;
//#define cout g
ifstream f("arbint.in");
ofstream g("arbint.out");

int n,m,a[10000001],x,b,aa,maxx,i,pos,val;
void update(int nod,int st,int dr)
{
  if(dr==st) a[nod]=val;
  else
    {
      int div=(st+dr)/2;
      if(pos<=div) update(nod*2,st,div);
      else update(nod*2+1,div+1,dr);
      a[nod]=max(a[nod*2],a[nod*2+1]);
    }
}
void que(int nod,int st, int dr)
{
  if ((aa<=st) && (dr<=b))
    {
      if (maxx<a[nod]) maxx=a[nod];
    }
  else
    {
      int div=(st+dr)/2;
      if (aa<=div) que(nod*2,st,div);
      if (div<b)que(nod*2+1,div+1,dr);
    }
}
int main()
{
  f>>n>>m;
  for(i=1; i<=n; ++i)
    {
      f>>x;
      pos=i;
      val=x;
      update(1,1,n);
    }
  for(; m; --m)
    {
      f>>x>>aa>>b;
      if (x==1)
        {
          pos=aa;
          val=b;
          update(1,1,n);
        }
      else
        {
          maxx=-1;
          que(1,1,n);
          cout<<maxx<<"\n";
        }
    }
cout<<"asdf\n";
cout<<();
  return 0;
}
