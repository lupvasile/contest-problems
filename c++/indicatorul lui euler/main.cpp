#include <iostream>

using namespace std;
int phi[6000],n,i,j;
int main()
{int n=5555,x;
    for(i=2;i<=n;++i)
    {
        for(j=2*i;j<=n;j+=i) ++phi[j];
    }
    while(1)
    {
        cin>>x;
        cout<<(phi[x]);
    }
    return 0;
}
