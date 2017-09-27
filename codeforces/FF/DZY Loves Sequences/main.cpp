#include <iostream>

using namespace std;

#define nmax 100001

int a[nmax],ps[nmax],pd[nmax];
int n,rez,i;

int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        ps[i]=1;
        if(a[i]>a[i-1]) ps[i]+=ps[i-1];

    }
    for(i=n;i;--i)
    {
        pd[i]=1;
        if (a[i]<a[i+1]) pd[i]+=pd[i+1];
    }
    for(i=1;i<=n;++i)
    {
        if(a[i+1]-a[i-1]>=2) rez=max(rez,ps[i-1]+1+pd[i+1]);
        else rez=max(rez,max(ps[i-1]+1,pd[i+1]+1));
    }
    cout<<rez;
    return 0;
}
