#include <iostream>
#include <fstream>

using namespace std;
ifstream f("datorii.in");
ofstream g("datorii.out");
#define cout g
int i,j,aib[15001],k,ce,a,b,s,n,m;
void adauga(int pos,int x)
{
    for(;pos<=n;pos+=(pos^(pos-1)&pos)) aib[pos]-=x;
}
int calc(int pos)
{   int sum(0);
    for(;pos>0;pos-=(pos^(pos-1)&pos)) sum+=aib[pos];
    return sum;
}
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
    {
        f>>s;
        for(j=i; j<=n; j+=(j^(j-1)&j)) aib[j]+=s;
    }
    for(i=1; i<=m; i++)
    {
        f>>ce>>a>>b;
        if (ce==0) adauga(a,b);
        else cout<<calc(b)-calc(a-1)<<'\n';
    }

return 0;
}
