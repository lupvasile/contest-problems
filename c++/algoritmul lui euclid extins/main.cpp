#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid3.in");
ofstream g("euclid3.out");
#define cout g
void euclid(int a,int b,int &d,int &x,int &y)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        int x0,y0;
        euclid(b,a%b,d,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;
    }
}
int t,d,x,y,a,b,c;
int main()
{
    f>>t;
    for(; t; t--)
    {
        f>>a>>b>>c;
        euclid(a,b,d,x,y);
        if(c%d==0) cout<<x*(c/d)<<" "<<y*(c/d)<<'\n';
        else cout<<"0 0\n";
    }
    return 0;
}
