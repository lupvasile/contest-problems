#include <iostream>
#include <fstream>

using namespace std;
ifstream f("flori4.in");
ofstream g("flori4.out");
#define mod 9001
int n,i;
int v[10001];
int main()
{
   f>>n;
   v[1]=1;v[2]=2;
   for(i=3;i<=n;++i) v[i]=(v[i-2]+v[i-1]+1)%mod;
   g<<v[n];
    return 0;
}
