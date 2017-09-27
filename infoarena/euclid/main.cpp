#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");
int gI();

#define nmax 410
#define cout g

int t,n,m,h,w,i,j,maxx,k,l;
int rmq[9][9][nmax][nmax];
int log[nmax];

int gcd(int d,int i)
    {
    /*int r;
    do
        {
        r=d%i;
        d=i;
        i=r;
        }
    while (r);
    return d;
    */
    while(d!=i)
    {
        if(d<i) swap(d,i);
        d=d-i;
    }
    return d;
     }
int query(int x,int y)
{
    int a=gcd(rmq[log[h]][log[w]][x][y],rmq[log[h]][log[w]][x][y+w-(1<<log[w])]);
    int b=gcd(rmq[log[h]][log[w]][x+h-(1<<log[h])][y],rmq[log[h]][log[w]][x+h-(1<<log[h])][y+w-(1<<log[w])]);
    return gcd(a,b);
}

int main()
    {
    t=gI();
    for(i=2; i<nmax; ++i) log[i]=log[i>>1]+1;
    for(int tt=1; tt<=t; ++tt)
        {
        maxx=0;
        n=gI(),m=gI(),h=gI(),w=gI();
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j) rmq[0][0][i][j]=gI();


        for(k=1; k<=log[h]; ++k)
            for(l=0; l<=log[w]; ++l)
                for(i=1; i+(1<<k)-1<=n; ++i)
                    for(j=1; j+(1<<l)-1<=m; ++j)
                    {
                        if(l>0) rmq[k][l][i][j]=gcd(rmq[k][l-1][i][j],rmq[k][l-1][i][j+(1<<(l-1))]);
                        else rmq[k][l][i][j]=gcd(rmq[k-1][l][i][j],rmq[k-1][l][i+(1<<(k-1))][j]);
                    }


        for(i=1;i+h-1<=n;++i)     ///coltul dreapta sus in i,j
            for(j=1;j+w-1<=m;++j)
                maxx=max(maxx,query(i,j));

        cout<<"Case #"<<tt<<": "<<maxx<<'\n';
        }
    return 0;
    }

#define nbuf 3276800
char buf[nbuf];
int pbuf(nbuf);

int gI()
    {
    int n=0;
    while (buf[pbuf]<'0' || buf[pbuf]>'9')
        {
        if(++pbuf>=nbuf) f.read(buf,nbuf),pbuf=0;
        }
    while (buf[pbuf]>='0' && buf[pbuf]<='9')
        {
        n=n*10+buf[pbuf]-'0';
        if(++pbuf>=nbuf) f.read(buf,nbuf),pbuf=0;
        }
    return n;
    }


