#include <iostream>

using namespace std;

int v[100010];

int main()
{
    int n,i,res(0),j;
    bool ok;
   cin>>n;
   for(i=1;i<=n;++i) cin>>v[i];

   for(i=10;i<=n;++i)
   {
       if(i+9>n) break;

       ok=true;
       for(j=1;j<=9;++j) if(v[i-j]>=v[i-j+1]) ok=false;
       for(j=0;j<8;++j) if( v[i+j]<=v[i+j+1]) ok=false;
       if(!(v[i]>v[i-1] && v[i]>v[i+1])) ok=false;

       if(ok) ++res;
   }
   cout<<res;

    return 0;
}
