#include <iostream>
#include <fstream>
using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

#define cout g

int n,m,stramos[18][250001];
int i,k,q,p;

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>stramos[0][i];
    for(k=1;(1<<k)<=n;k++)
    {
        for(i=1;i<=n;i++) stramos[k][i]=stramos[k-1][stramos[k-1][i]];
    }
    for(;m;m--)
    {
        f>>q>>p;
        for(i=0;(1<<i)<=p;i++)
            if (p & (1<<i)) q=stramos[i][q];
        cout<<q<<'\n';

    }
    return 0;
}
