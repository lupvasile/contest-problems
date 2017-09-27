#include <iostream>
#include <fstream>

using namespace std;

ifstream f("compus.in");
ofstream g("compus.out");

#define cout g

int i,c,m,sol,h,imax,n;

int main()
{
    f>>m;
    for(c=(m-2)/8;c<=(m-5)/5;++c)
    {
        n=m-5*c-5;
        if(n<0) continue;
        i=max(0,n-2*c+2);
        imax=min(n,c);
        if((i&1)^(n&1)) ++i;
        h=n-3*i;
        if(h>=0 && i<=imax) sol+=min(h/6+1,(imax-i)/2+1);
    }
    cout<<sol;
    return 0;
}
