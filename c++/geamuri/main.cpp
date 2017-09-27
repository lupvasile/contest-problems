#include <iostream>
#include <fstream>

using namespace std;

ifstream f("geamuri.in");
ofstream g("geamuri.out");

#define cout g
int n,c,i,j,x,x1,x2,y1,y2;
int a[1100][1100],nr[50100];

int main()
{
f>>c>>n;
for(;n;--n)
{
    f>>x1>>y1>>x2>>y2;
    //++x1,++x2,++y1,++y2;
    ++a[x1][y1];
    --a[x1][y2+1];
    --a[x2+1][y1];
    ++a[x2+1][y2+1];
}
for(i=1;i<=c;++i) for(j=1;j<=c;++j)
{
    a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    ++nr[a[i][j]];
}
f>>n;
for(;n;--n)
{
    f>>x;
    cout<<nr[x]<<'\n';
}
    return 0;
}
