#include <iostream>
#include <cstdio>
using namespace std;

#define nr 3 //numaru de locomotive
#define nmax 50001
FILE *f=freopen("tren1.in","r",stdin);
FILE *g=freopen("tren1.out","w",stdout);
int n,m,i,j,a[nmax][nr+1],v[nmax];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        v[i]+=v[i-1];
    }
    scanf("%d",&m);
    for(i=1;i<=m;++i) for(j=1;j<=nr;++j) a[i][j]=v[i];
    for(i=m+1;i<=n;++i)
    for(j=1;j<=nr;++j)
    a[i][j]=max(a[i-1][j],a[i-m][j-1]+v[i]-v[i-m]);
    printf("%d",a[n][nr]);

    return 0;
}
