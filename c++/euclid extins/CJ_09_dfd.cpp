#include <iostream>
#include <fstream>

using namespace std;
int euclidExtins(int a,int b, int&lastX,int&lastY)
{
    int x=0,y=1,q;lastX=1;lastY=0;
    int tA,tX,tY;
    while (b!=0)
    {
        //if(a>b) swap(a,b);
        q=a/b;
        tA=b;b=a%b;a=tA;

        tX=x;x=lastX-q*x;lastX=tX;
        tY=y;y=lastY-q*y;lastX=tY;
    }
    return a;
}
int main()
{
  ifstream f("date.in");
  int a,b,x,y;
  f>>a>>b;
  cout<<euclidExtins(a,b,x,y)<<'\n';
  cout<<x<<' '<<5555555;
    return 0;
}
