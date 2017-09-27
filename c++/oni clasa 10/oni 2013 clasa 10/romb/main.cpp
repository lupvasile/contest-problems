#include <iostream>
#include <fstream>
using namespace std;

ifstream f("romb.in");
ofstream g("romb.out");
#define cout g
struct punct
{
  double x,y;
} p,o;
long long t,dx,dy,k;
long long solve(double dx,double dy,punct p,long long nivel,long long start)
{
  punct p_aux;
  long long reg;
  if(p.x==0.0)
    {
      if (p.y>0) reg=1;
      else reg=3;
    }
  else if (p.y==0)
    {
      if(p.x>0.0) reg=4;
      else reg=2;
    }
  else if(p.x>0.0 && p.y>0.0)
    {
      p_aux.x=dx/2;
      p_aux.y=dy/2;
      if(p_aux.y*p.x>p_aux.x*p.y) reg=4;
      else reg=1;
    }
  else if (p.x<0.0 && p.y>0.0)
    {
      p_aux.x=-(dx/2);
      p_aux.y=dy/2;
      if(p_aux.y*p.x>p_aux.x*p.y) reg=1;
      else reg=2;
    }
  else if(p.x<0.0 && p.y<0.0)
    {
      p_aux.x=-(dx/2);
      p_aux.y=-(dy/2);
      if(p_aux.y*p.x>p_aux.x*p.y) reg=2;
      else reg=3;
    }
  else if(p.x>0.0 && p.y<0.0)
    {
      p_aux.x=dx/2;
      p_aux.y=-(dy/2);
      if(p_aux.y*p.x>p_aux.x*p.y) reg=3;
      else reg=4;
    }
    if(nivel<k)
    {
    switch (reg)
    {
        case 1: p_aux={0,dy/2};break;
        case 2: p_aux={-(dx/2),0};break;
        case 3: p_aux={0,-(dy/2)};break;
        case 4: p_aux={dx/2,0};break;
    }
    p.x=p.x-p_aux.x;
    p.y=p.y-p_aux.y;
    return solve(dx/2,dy/2,p,nivel+1,(start+reg-1)*4-3);
    }
    else return start+reg-1;
}
int main()
{
  f>>t;
  for(; t; --t)
    {
      f>>dx>>dy>>k>>p.x>>p.y;
      cout<<solve(dx,dy,p,1,1)<<'\n';
    }
  return 0;
}