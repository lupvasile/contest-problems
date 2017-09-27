#include <iostream>
#include <fstream>
#define mod 1999999973
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
long long rez(1),n,p,i;
#define cout g
int main()
{
 f>>n>>p;
 for(i=0;(1<<i)<=p;++i)
 {
     if(p&(1<<i)) rez=rez*n%mod;
     n=n*n%mod;
 }
 cout<<rez;
 return 0;
}
