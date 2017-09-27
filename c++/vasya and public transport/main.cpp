#include <iostream>

using namespace std;
#define foor(i,a,b) for(i=a;i<=b;i++)
int c1,c2,c3,c4,m,n,autobuz[1001],trolebuz[1001],i,mina,minb;
int cost(int a[1001],int l)
{
    int minn(0),i,min2(0);
    minn=c3;
    foor(i,1,l) min2+=min(c2,c1*a[i]);
    if (min2<minn) minn=min2;
    return minn;
}
int main()
{   cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    foor(i,1,n) cin>>autobuz[i];
    foor(i,1,m) cin>>trolebuz[i];
    mina=cost(autobuz,n);
    minb=cost(trolebuz,m);
    if (mina+minb<c4)cout<<mina+minb;
    else cout<<c4;
    return 0;
}
