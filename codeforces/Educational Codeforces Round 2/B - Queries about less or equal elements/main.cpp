#include <bits/stdc++.h>
using namespace std;

#define nmax 200010

int a[nmax];

int main()
{
    int n,m,i,x;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];

    sort(a+1,a+n+1);
    for(;m;--m)
    {
        cin>>x;
        cout<<upper_bound(a+1,a+n+1,x)-a-1<<' ';
    }
    return 0;
}
