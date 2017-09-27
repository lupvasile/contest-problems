#include <iostream>
#include <cmath>

using namespace std;
#define nmax 1000000010
int n,x,y,maxy(-nmax),miny(nmax),maxx(-nmax),minx(nmax);
unsigned long long l;

int main()
{
    cin>>n;
    for(;n;--n)
    {
        cin>>x>>y;
        maxy=max(y,maxy);
        miny=min(y,miny);
        maxx=max(x,maxx);
        minx=min(x,minx);
    }
    l=max(abs(maxy-miny),abs(maxx-minx));
    cout<<l*l;

    return 0;
}
