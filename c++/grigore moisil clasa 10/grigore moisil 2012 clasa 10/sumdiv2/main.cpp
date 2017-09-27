#include <iostream>
#include<fstream>

using namespace std;

ifstream f("sumdiv2.in");
ofstream g("sumdiv2.out");
#define cout g
int n,i,b_max,j;
struct {int a,b;} v[100001];
long long sum[1000001],q[1000001];
int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>v[i].a>>v[i].b,b_max=max(b_max,v[i].b);
    for(i=1;i<=b_max;++i)
    {
        for(j=i;j<=b_max;j+=i) sum[j]+=i;
        q[i]=q[i-1]+sum[i];
    }
    for(i=1;i<=n;++i) cout<<q[v[i].b]-q[v[i].a-1]<<'\n';
        return 0;
}
