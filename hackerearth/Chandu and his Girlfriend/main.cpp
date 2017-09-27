#include <algorithm>
#include <iostream>

using namespace std;

#define nmax 100010

int i,v[nmax],n;

void read_array()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>v[i];
}

int main()
{
    int T;
    cin>>T;
    for(;T;--T)
    {
        read_array();
        sort(v+1,v+n+1,greater<int>());
        for(i=1;i<=n;++i) cout<<v[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
