#include <iostream>
#include <fstream>

using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
#define cout g
int i,j,aib[100001],m,ce,a,b,s,n,k;
void adauga(int pos,int x)
    {
    for(; pos<=n; pos+=(pos^(pos-1)&pos)) aib[pos]+=x;
    }
int calc(int pos)
    {
    int sum(0);
    for(; pos>0; pos-=(pos^(pos-1)&pos)) sum+=aib[pos];
    return sum;
    }
int binsrc(int val)
    {
    int s=1,d=n,m,k;
    bool gasit=false;
    while(s<=d &&  !gasit)
    {
        m=(s+d)/2;
        k=calc(m);
        if (k==val) gasit=true;
        else if(k>val) d=m-1;
        else s=m+1;
    }
    if (gasit)return m;
    else return -1;
    }
    int Search(int val)
{
    int i, step;

    for ( step = 1; step < n; step <<= 1 );

    for( i = 0; step; step >>= 1 )
    {
         if( i + step <= n)
         {
            if( val >= aib[i+step] )
            {
                i += step, val -= aib[i];
                if ( !val ) return i;
            }
         }
    }

    return -1;
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
        f>>ce;
        if (ce==0)
            {
            f>>a>>b;
            adauga(a,b);
            }
        else if (ce==1)
            {
            f>>a>>b;
            cout<<calc(b)-calc(a-1)<<'\n';
            }
        else
            {
            f>>k;
            cout<<Search(k)<<'\n';
            }
        }
    return 0;
    }
