#include <iostream>
#include <fstream>
using namespace std;

ifstream f("medie.in");
ofstream g("medie.out");

#define cout g
int i,j,a[9001],v[14003],frecvent[7001],d,n,maxx;
long long nr;
int main()
{
   f>>n;
   for(i=1;i<=n;i++) {
       f>>a[i];
        maxx=max(maxx,a[i]);
         ++frecvent[a[i]];
   }
   for(i=1;i<=n;++i)
       for(j=i+1;j<=n;++j)
   {
       d=a[i]+a[j];
       ++v[d];

   }
    for(i=1;i<=maxx;++i)
        if (v[2*i] && frecvent[i])
        {
            nr=nr+v[2*i]*frecvent[i]-frecvent[i]*(frecvent[i]-1);
        }
        cout<<nr;
    return 0;
}
