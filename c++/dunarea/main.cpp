#include <iostream>
#include <fstream>
using namespace std;

int a,b,n,h,x,y,l[5002],i;

ifstream f("dunarea.in");
ofstream g("dunarea.out");
int main()
{
    f>>a>>b>>n;
    for(i=1;i<=n;i++)
        {
            f>>x>>y;
            if(x>=a && x<=b)
                for(h=x;h<=y && h<=b;h++)
                    if(l[h]<y) l[h]=y;
            if(x<=a && y>=a)
                for(h=a;h<=y && h<=b;h++)
                    if(l[h]<y) l[h]=y;
        }
    x=a;
    i=0;
    while(x<b)
    {
        ++i;
        x=l[x];
    }
    g<<i;
    return 0;
}