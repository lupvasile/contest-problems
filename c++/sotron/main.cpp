#include <fstream>
#include <iostream>

using namespace std;
ifstream f("sotron.in");
ofstream g("sotron.out");
int maxx,p,n,i,j,a[241][241];

int subsecventa(int x,int y,int stare)
{   int maxx(0),s(0);
    while(x && y<=n)
    {
        if (s>=0) s+=a[x][y];
        else s=a[x][y];
        if(s>maxx) maxx=s;
        if(stare==0) --x;
        else y++;
        stare=1-stare;
    }
    return maxx;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    for(i=1;i<=n;i+=2)
    {
        p=subsecventa(i,1,0);
        if(p>maxx) maxx=p;
    }
    if(n&1)j=2;
    else j=1;
    for(;j<=n;j+=2)
    {
        p=subsecventa(n,j,1);
        if(p>maxx) maxx=p;
    }
    g<<maxx;
    return 0;
}
