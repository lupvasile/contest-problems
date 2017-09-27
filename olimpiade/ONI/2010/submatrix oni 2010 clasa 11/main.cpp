#include <iostream>
#include <fstream>
#include<tr1/unordered_map>
#include <cstring>
using namespace std;
using namespace tr1;
ifstream f("submatrix.in");
ofstream g("submatrix.out");

//#define cout g
#define nmax 302

int n,m,k,i,j,maxx,nr;
struct
    {
    int x,y;
    } start,ps,pj;
int ff[nmax*nmax];
int a[nmax][nmax];
unordered_map<int,int> um;

void add_lin(int x,int y1,int y2,int w)
    {
    for(int i=y1; i<=y2; ++i)
        {
        if(ff[a[x][i]]==0) ++nr;
        ff[a[x][i]]+=w;
        if(ff[a[x][i]]==0) --nr;
        }
    }


void add_col(int y,int x1,int x2,int w)
    {
    for(int i=x1; i<=x2; ++i)
        {
        if(ff[a[i][y]]==0) ++nr;
        ff[a[i][y]]+=w;
        if(ff[a[i][y]]==0) --nr;
        }
    }


int main()
    {
    f>>n>>m>>k;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            f>>a[i][j];
            if(um[a[i][j]]==0) um[a[i][j]]=++nr;
            }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j) a[i][j]=um[a[i][j]];
    start= {n,1};
    while(start.x>=1 && start.y<=m)
        {

        ps=pj=start;
        nr=0;
        memset(ff,0,sizeof ff);
        while(pj.x<=n && pj.y<=m)
            {
            add_col(pj.y,ps.x,pj.x,1);
            add_lin(pj.x,ps.y,pj.y,1);
            add_lin(pj.x,pj.y,pj.y,-1);
            while(nr>k)
                {
                add_col(ps.y,ps.x,pj.x,-1);
                add_lin(ps.x,ps.y,pj.y,-1);
                add_lin(ps.x,ps.y,ps.y,1);
                ++ps.x,++ps.y;
                }
            maxx=max(maxx,pj.x-ps.x+1);
            ++pj.x,++pj.y;
            }
        if(start.x==1) ++start.y;
        else --start.x;
        }
    cout<<maxx;
    return 0;
    }
