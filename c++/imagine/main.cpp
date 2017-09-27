#include <iostream>
#include <cstdio>
using namespace std;

FILE *f=freopen("imagine.in","r",stdin);
FILE *g=freopen("imagine.out","w",stdout);


int a[251][251],n,i,j;
bool pixeli_egali(int x1,int y1,int x2,int y2)
{
    int pixel=(a[x1][y1]),i,j;
    for(i=x1;i<=x2;++i) for(j=y1;j<=y2;++j) if (a[i][j]!=pixel) return false;
    return true;

}
int compresie(int x1,int y1,int x2,int y2)
{
    if (pixeli_egali(x1,y1,x2,y2)) return 2;
    else return 1+compresie((x1+x2)/2+1,y1,x2,(y1+y2)/2) + compresie(x1,y1,(x1+x2)/2,(y1+y2)/2) + compresie((x1+x2)/2+1,(y1+y2)/2+1,x2,y2)+ compresie(x1,(y1+y2)/2+1,(x1+x2)/2,y2);
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    for (j=1;j<=n;++j)
    scanf("%d",&a[i][j]);
    printf("%d",compresie(1,1,n,n));
    return 0;
}
