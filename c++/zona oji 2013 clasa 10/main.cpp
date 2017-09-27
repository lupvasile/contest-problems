#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("zona.in");
ofstream g("zona.out");

int c,n,x,y,l,a[51][51],i,k,j,p,s,v[51][51];
int d[5][2]= {{},{-1,0},{0,1},{1,0},{0,-1}};
bool ok;
int main()
    {
    f>>x>>y>>n>>l;
    a[x][y]=1;
    for(i=2; i<=l; i++)
        {
        f>>k;
        x+=d[k][0];
        y+=d[k][1];
        a[x][y]=i;
        if (k==3) v[x][y]=1;
        else if (k==1) v[x+1][y]=1;
        }
    f>>k;
    x+=d[k][0];
    y+=d[k][1];
    if (k==3) v[x][y]=1;
    else if (k==1) v[x+1][y]=1;
//a[x][y]=99;

    p=a[x][y]-1;
    a[x][y]=l+1;
    for (i=0; i<=n; i++)
        {
        ok=false;
        for (j=0; j<=n; j++)
            {
            if ((a[i][j]>p )&& (a[i-1][j]>p) && (v[i][j]>0)) ok=!ok;
            if (ok) s++;
            }

        }
    g<<l-p<<"\n";
    g<<s<<"\n";

    return 0;
    }
