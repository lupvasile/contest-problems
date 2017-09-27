#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("lacusta.in");
ofstream g("lacusta.out");
#define NMAX 58
#define foor(i,a,b) for(i=a;i<=b;i++)
#define inf 0x3f3f3f;
int a[NMAX][NMAX];
int b[NMAX][NMAX],min2,minn,pm,pm2,i,j,n,m;
void afisare(int z[][NMAX])
{
int i,j;
foor(i,1,n)
{
    foor(j,1,m) cout<<setw(3)<<z[i][j];
    cout<<'\n';
}
cout<<'\n';
}
int main()
{
    f>>n>>m;
    foor(i,1,n) foor(j,1,m) f>>a[i][j];
    b[n][m]=a[n][m];
    a[n-1][m]=inf;
    foor(j,1,m-1) b[n][j]=a[n][j]+a[n][m];
    for(i=n-1; i; i--)
    {
        minn=min2=inf;
        foor(j,1,m) if(minn>a[i][j]+b[i+1][j])
        {
            min2=minn;
            pm2=pm;
            pm=j;
            minn=a[i][j]+b[i+1][j];
        }
        else if (min2>a[i][j]+b[i+1][j])
        {
            pm2=j;
            min2=a[i][j]+b[i+1][j];
        }
        for(j=1; j<=m; j++) if(j!=pm) b[i][j]=a[i][j]+minn;
        b[i][pm]=a[i][j]+min2;
        afisare(b);
    }

    //cout<<a[3][3];
    cout<<b[1][1];

                                return 0;
}
