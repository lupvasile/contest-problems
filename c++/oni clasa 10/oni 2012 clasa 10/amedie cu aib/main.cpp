#include <iostream>
#include <fstream>

using namespace std;

#define nmax 1000
#define val_max 140000
//#define cout g

ifstream f("amedie.in");
ofstream g("amedie.out");
//ifstream h("5-amedie.ok");

long long a[nmax][nmax],aib[val_max];
bool sters[nmax][nmax];
long long n,m,i,j,q,nr_elemente,x;
char c;

void add(long long val,long long pos)
{
    for(; pos<val_max; pos+=(pos&(-pos)))
    {
        aib[pos]+=val;
   }
}
long long query(long long val)
{
    long long step=1;
    long long pos=0;
    while (aib[step]<val) step<<=1;
    while (val && step)
    {
        if(val>=aib[pos+step]) val-=aib[pos+step],pos+=step;
        step>>=1;
    }
    if(val) ++pos;
    return pos;
}
int main()
{
    f>>m>>n>>q;
    nr_elemente=m*n;
    for(i=1; i<=n; ++i) for(j=1; j<=m; ++j)
        {
            f>>a[i][j];
            add(1,a[i][j]);
        }
    for(; q; --q)
    {
        f>>c;
        if(c=='Q')
        {
            g<<query((nr_elemente+1)/2)<<'\n';
        }
        else
        {
            f>>x;
            if(c=='L') for(i=1; i<=m; ++i) if(!sters[x][i]) sters[x][i]=true,add(-1,a[x][i]),--nr_elemente;
                            else;
                    else for(i=1; i<=n; ++i) if(!sters[i][x]) sters[i][x]=true,add(-1,a[i][x]),--nr_elemente;
        }
    }
    return 0;
}
