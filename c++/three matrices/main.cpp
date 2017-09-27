#include <iostream>
#include <iomanip>
//#include <fstream>
using namespace std;
//ifstream f("date.in");
#define nmax 172
//#define cin f
int z[nmax][nmax];
double a[nmax][nmax],b[nmax][nmax];
int n,i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j) cin>>z[i][j];
    for(i=1;i<=n;++i)
    for(j=i;j<=n;++j)
    {
        a[j][i]=a[i][j]=(z[i][j]+z[j][i])/(double)2;
        b[i][j]=z[i][j]-a[i][j];
        b[j][i]=z[j][i]-a[j][i];
    }
    for(i=1;i<=n;++i){
    for(j=1;j<=n;++j)
    cout<<fixed<<setprecision(8)<<a[i][j]<<' ';
    cout<<'\n';
    }
    for(i=1;i<=n;++i){
    for(j=1;j<=n;++j)
    cout<<fixed<<setprecision(8)<<b[i][j]<<' ';
    cout<<'\n';
    }
    return 0;
}
