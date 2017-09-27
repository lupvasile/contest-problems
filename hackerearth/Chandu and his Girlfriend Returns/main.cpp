#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax 50010
#define ENTER cout<<"\n";
int n,m,a[nmax],b[nmax];

void mergee()
{
    int p=1,q=1;

    while(p<=n || q<=m)
        if(p>n) cout<<b[q++]<<' ';
        else if(q>m) cout<<a[p++]<<' ';
        else if(a[p]>b[q]) cout<<a[p++]<<' ';
        else cout<<b[q++]<<' ';

}
void read(int a[],int n)
{
    for(int i=1;i<=n;++i) cin>>a[i];
}

int main()
{
    int T;

    int x=30;
    int y=5;
    double z=(x+y)/6.0;
    z=floor(z*100);
    z/=100;
    cout<<z;

    return 0;

    cin>>T;
    for(; T; --T)
    {
        cin>>n>>m;
        read(a,n);
        read(b,m);
        mergee();
        ENTER;
    }
    return 0;
}
