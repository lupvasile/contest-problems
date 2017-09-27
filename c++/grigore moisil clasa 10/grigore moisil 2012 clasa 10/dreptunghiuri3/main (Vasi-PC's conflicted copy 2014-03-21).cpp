#include <iostream>
#include <fstream>


using namespace std;

ifstream f("dreptunghiuri3.in");
ofstream g("dreptunghiuri3.out");

#define pb push_back

struct {long long x1,x2,y1,y2,val;} d[1010];
long long n,m,k,i,xx1,xx2,yy1,yy2,maxx(1LL<<63),j,nr;
int a[3010][3010];

int main()
{
    f>>n>>m>>k;
    for(i=1;i<=k;++i)
    {
        f>>d[i].x1>>d[i].y1>>d[i].x2>>d[i].y2>>d[i].val;
       a[d[i].x1][d[i].y1]+=d[i].val;
       a[d[i].x2+1][d[i].y1]-=d[i].val;
       a[d[i].x1][d[i].y2+1]-=d[i].val;
       a[d[i].x2+1][d[i].y2+1]+=d[i].val;
    }
    for(i=1;i<=3000;++i)
    for(j=1;j<=3000;++j)
    {
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        if(a[i][j]>maxx)
        {
            maxx=a[i][j];
            nr=1;
        }
        else if(a[i][j]==maxx) nr++;
    }

    g<<maxx<<' '<<nr;
    return 0;
}
