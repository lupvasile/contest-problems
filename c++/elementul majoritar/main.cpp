#include <iostream>
#include <fstream>
using namespace std;
#define cout g
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int k,v[1000001],i,n,cand;
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>v[i];
        if (k==0) cand=v[i];
        if (v[i]==cand) ++k;
        else --k;
    }
    k=0;
    for(i=1;i<=n;++i) if (v[i]==cand) ++k;
    if (k>=n/2) cout<<cand<<' '<<k;
    else cout<<-1;
    return 0;
}
