#include <iostream>
#include <fstream>
#include <algorithm>
using  namespace std;
ifstream f("colaj.in");
ofstream g("colaj.out");
#define cout g
int n,k,x[200],y[200],x6(0),y6(0),m,p;
char a[201][201];
bool okx(false),oky(false);
struct
    {
    int a,b,c,d;
    } v[100];
bool verf(int a,int b,int c,int d, int n)
    {
    for(int i=1; i<=n; i++)
        if((a>=v[i].a) && (b>=v[i].b) && (c<=v[i].c) && (d<=v[i].d)) return false;
    return true;
    }
void init_matrice()
    {
    int i,j;
    for(i=0; i<=p; i++) for(j=0; j<=m; j++) a[i][j]=0;
    }
void citire()
    {
    int xa,xb,xc,xd,r(0),i;
    f>>n>>m>>p;
    for(i=1; i<=n; i++)
        {
        f>>xa>>xb>>xc>>xd;
        if(verf(xa,xb,xc,xd,r))
            {
            r++;
            v[r].a=xa;
            v[r].b=xb;
            v[r].c=xc;
            v[r].d=xd;
            x[++k]=xa;
            y[k]=xb;
            x[++k]=xc;
            y[k]=xd;
            if(xa==0) x6=-1;
            if(xb==0) y6=-1;
            if(xc==m) okx=true;
            if(xd==p) oky=true;
            }
        }
    n=r;
    }
int poz(int val,int z[])
    {
    int s(1),d(k),m;
    while(s<=d)
        {
        m=(s+d)/2;
        if(z[m]==val) return m;
        else if(z[m]<val)s=m+1;
        else d=m-1;
        }
    }
void normalizare()
    {
    for(int i=1; i<=n; i++)
        {
        v[i].a=poz(v[i].a,x);
        v[i].b=poz(v[i].b,y);
        v[i].c=poz(v[i].c,x);
        v[i].d=poz(v[i].d,y);
        }
    }
void matrice()
    {
    int i,j,k;
    for (int k=1; k<=n; k++)
        for(i=v[k].b; i<v[k].d; i++)
            for(j=v[k].a; j<v[k].c; j++)a[i+y6][j+x6]=1;
    }
void fill(int i,int j)
    {
    a[i][j]=1;
    if(i-1>=0 && a[i-1][j]==0) fill(i-1,j);
    if(j+1<=m && a[i][j+1]==0) fill(i,j+1);
    if(i+1<=p && a[i+1][j]==0) fill(i+1,j);
    if(j-1>=0 && a[i][j-1]==0) fill(i,j-1);
    }
int rezolva()
    {
    int i,j,nr(0);
    for(i=0; i<=p; i++) for(j=0; j<=m; j++)
            if(a[i][j]==0)
                {
                nr++;
                fill(i,j);
                }
    return nr;
    }
int main()
    {
    citire();
    sort(x+1,x+k+1);
    sort(y+1,y+k+1);
    if(okx) m=poz(x[k],x)+x6;
    else m=poz(x[k],x)+x6+1;
    if(oky) p=poz(y[k],y)+y6;
    else p=poz(y[k],y)+1+y6;
    m--;
    p--;
    normalizare();
    init_matrice();
    matrice();

    /*for(int i=p; i>=0;i--)
        {
        for(int j=0; j<=m; j++) cout<<(int)a[i][j]<<' ';
        cout<<'\n';
        }
*/
    cout<<rezolva();
    return 0;
    }
