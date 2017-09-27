#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream f("minusk.in");
ofstream g("minusk.out");

#define cout g
long long int n,k,m[1000001],i,p[1000001];

int main()
{
    f>>n>>k;
    //v[k]=1;
    //putere[0]=1;
    p[1]=m[1]=1;
    for(i=2;i<=k;i++) p[i]=m[i]=(p[i-1]*2)%2011;
    m[k]--;
    for(i=k+1;i<=n;i++)
         {
             p[i]=(p[i-1]+m[i-1])%2011;
             m[i]=(p[i-1]+m[i-1]-p[i-k]+2*2011)%2011;
         }
    cout<<(p[n]+m[n])%2011;
    return 0;
}
