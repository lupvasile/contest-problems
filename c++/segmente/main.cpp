#include <iostream>
#include <fstream>

using namespace std;

ifstream f("segmente.in");
ofstream g("segmente.out");
int n,i,j;
bool c[502];
struct {int a,b,c;} v[502];
int minn,nr(0);
bool intersectie(int a,int b,int x,int y)
{
    return ((((a>=x) && (a<=y))) || ((b>=x) && (b<=y)) || ((x>=a) && (x<=b)));
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>v[i].a>>v[i].b;
        minn=0;
        for(j=1;j<i;++j)
        {
            if (intersectie(v[i].a,v[i].b,v[j].a,v[j].b))
            {
               ++minn;
            }
        }
        nr=max(nr,minn);
    }
   /* g<<500<<'\n';
    for(i=1;i<=500;++i)
    {
        g<<1<<' '<<i+1<<'\n';
    }
    cout<<nr;*/
    cout<<nr;
    return 0;
}
