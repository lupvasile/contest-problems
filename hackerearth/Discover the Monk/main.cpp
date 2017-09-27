#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,q;
vector<int> v;

int main()
{
    int i;
    cin>>n>>q;
    v.resize(n);
    for(i=0;i<n;++i) cin>>v[i];
    sort(v.begin(),v.end());
    for(;q;--q)
    {
        cin>>i;
        if(binary_search(v.begin(),v.end(),i)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
