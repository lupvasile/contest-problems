#include <iostream>

using namespace std;

#define ll long long
#define nmax 100010

ll a[nmax],b[nmax];

int main()
{
    int t,i,j,n,res;
    cin>>t;

    for(;t;--t)
    {
        cin>>n;
        for(i=1;i<=n;++i) cin>>a[i];
        for(i=1;i<=n;++i) cin>>b[i];

        res=0;

        for(i=1,j=0;i<=n;++i)
        {
            while(b[j+1]>=a[i]) ++j;
            if(!j) continue;
            if(j>n) break;
            res=max(res,j-i);
        }

        cout<<res<<'\n';
    }

    return 0;
}
