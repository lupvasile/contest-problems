#include <iostream>

using namespace std;
int n,k,i,j;
int main()
{cin>>n>>k;
    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) if (i==j)cout<<k<<" ";
            else cout<<"0 ";
            cout<<'\n';
    }
    return 0;
}
