#include <iostream>
#include <fstream>

using namespace std;

ifstream f("copii.in");
ofstream g("copii.out");

int v[100010],m,n,i,q,poz,j;
struct {int x,y;} op[10010];

#define cout g

int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>v[i];
    f>>m;
    for(i=1;i<=m;++i) f>>op[i].x>>op[i].y;
    f>>q;
    for(;q;--q)
    {
        f>>poz;
        for(j=m;j;--j)
        if(op[j].x<=poz && op[j].y>=poz) poz=op[j].y-(poz-op[j].x);
        cout<<v[poz]<<'\n';
    }
    return 0;
}
