#include <iostream>
#include <fstream>

using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");

#define cout g

int n,m,i,x,y,l,k,j;
int rmq[100010][17];
int log[100010];

int main()
{
    f>>n>>m;
    for(i=2;i<=n;++i) log[i]=log[i>>1]+1;
    for(i=1;i<=n;++i) f>>rmq[i][0];

    for(k=1;(1<<k)<=n;++k)
        for(j=1;j+(1<<k)-1<=n;++j)
        {
            rmq[j][k]=min(rmq[j][k-1],rmq[j+(1<<(k-1))][k-1]);
        }

    for(;m;--m)
    {
        f>>x>>y;
        l=log[y-x+1];
        cout<<min(rmq[x][l],rmq[y-(1<<l)+1][l])<<'\n';
    }
    return 0;
}
