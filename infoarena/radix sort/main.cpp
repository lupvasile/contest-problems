#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("radixsort.in");
ofstream g("radixsort.out");

#define nmax 10000010
#define mask 255
#define bytes 4

int n,a,b,c,i,k;
int v[nmax],fr[256],aux[nmax];

int main()
{

    f>>n>>a>>b>>c;
    v[1]=b;
    for(i=2;i<=n;++i) v[i]=(1LL*a*v[i-1]+b)%c;

    ///radix sort
    for(k=0;k<bytes;++k)
    {
        for(i=1;i<=n;++i) ++fr[v[i]>>(k*8)&mask];//counting sort pentru un bucket
        for(i=1;i<=256;++i) fr[i]+=fr[i-1];
        for(i=n;i>0;--i) aux[fr[v[i]>>(k*8)&mask]--]=v[i];
        memset(fr,0, sizeof(fr));
        memcpy(v,aux,sizeof(aux));
    }

    for(i=1;i<=n;i+=10) g<<v[i]<<' ';
    return 0;
}
