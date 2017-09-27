#include <iostream>

using namespace std;
int n,k,i;
int main()
    {
    cin>>n>>k;
    if (n==k-1) for(i=1; i<=n; i++) cout<<i<<' ';
    else if(n==k) cout<<-1;
    else if (k==0)
        {
        for(i=1; i<n; i++)cout<<i+1<<' ';
        cout<<'1';
        }
    else if(k+2<=n)
        {
        cout<<k+2<<' ';
        for(i=2;i<=k+1;i++) cout<<i<<' ';
        for(i=k+2;i<=n-1;i++)cout<<i+1<<' ';
        cout<<1;
        }
        else {
        for(i=1;i<=n;i++)cout<<i<<' ';
        }
    return 0;
    }
