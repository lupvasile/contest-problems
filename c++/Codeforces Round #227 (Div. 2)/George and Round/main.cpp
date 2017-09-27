#include <iostream>

using namespace std;
int n,m,i,v[3002],l,x;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i) cin>>v[i];
    for(i=1;i<=n && l<m;++i)
    {
        cin>>x;
            ++l;
        while (l<m && v[i]>x)
        {
            cin>>x;
            ++l;
        }
    }
    if(v[i]>x) --i;
    cout<<(n-i+1);
    return 0;
}
