#include <iostream>

using namespace std;

int a[20][20];

int summ(int x1,int y1,int x2,int y2)

{
    return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}

int main()
{
    int r,c,n,k,i,j,x,y,sol(0),i1,i2,j1,j2;
    cin>>r>>c>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>x>>y;
        a[x][y]=1;
    }

    for(i=1;i<=r;++i)
        for(j=1;j<=c;++j)
        a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];

    for(i1=1;i1<=r;++i1)
        for(j1=1;j1<=c;++j1)
        for(i2=i1;i2<=r;++i2)
        for(j2=j1;j2<=c;++j2)
        if(summ(i1,j1,i2,j2)>=k) ++sol;

    cout<<sol;
    return 0;
}
