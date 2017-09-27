#include <iostream>
#include <fstream>
using namespace std;

ifstream f("z.in");
ofstream g("z.out");
int xx,yy,n,k;
int parcurge(int x_s,int y_s,int l,int val)
{
    if (l==1) return val;
    l>>=1;
    if (xx>=x_s+l) if (yy>=y_s+l) return parcurge(x_s+l,y_s+l,l,val+3*l*l);
    else return parcurge(x_s+l,y_s,l,val+2*l*l);
    else if (yy>=y_s+l) return parcurge(x_s,y_s+l,l,val+l*l);
    else return parcurge(x_s,y_s,l,val);
}

int main()
{
    f>>n>>k;
    for(;k;--k)
    {
        f>>xx>>yy;
        g<<parcurge(1,1,(1<<n),1)<<'\n';
    }
    return 0;
}
