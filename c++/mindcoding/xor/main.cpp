#include <iostream>

using namespace std;
int x,y,val,n,m,v[100002],i;
int main()
{
   cin>>n>>m;
   for(;m;--m)
   {
       cin>>x>>y>>val;
       v[y]=v[x-1]^val;
   }
   for(i=1;i<=n;++i) cout<<(v[i]^v[i-1])<<' ';
    return 0;
}
