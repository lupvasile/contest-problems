#include <iostream>
#include <fstream>

using namespace std;

ifstream f("gheizere.in");
ofstream gg("gheizere.out");

//#define cout gg

struct
{
    int x,y,r,t,d;
} g[1003];

int n,m,p,v,e;
int i,j,t,stp,k;
bool c[2][300][300],a[300][300];
int main()
{
    f>>n>>m>>p;
    f>>v>>e;
    for(i=1; i<=p; ++i) f>>g[i].x>>g[i].y>>g[i].r>>g[i].t>>g[i].d;
//c[timp][i][j]=true daca pot fi la timpu timp in i,j, la inceput, inainte sa o traversez
    c[0][v][1]=true;
    for(t=1; t<=1000; ++t)
    {
        stp=(t&1);
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j) {
                c[stp][i][j]=c[stp^1][i][j-1] || c[stp^1][i-1][j] || c[stp^1][i+1][j];
                if(c[stp][i][j]) {if(a[i][j]) cout<<"asdf";
                a[i][j]=true;
                }
            }
        for(k=1; k<=p; ++k)
            if(t%(g[k].t+g[k].d)>=g[k].t)
                for(i=max(g[k].x-g[k].r,1); i<=g[k].x+g[k].r; ++i)
                    for(j=max(g[k].y-g[k].r,1); j<=g[k].y+g[k].r; ++j) c[stp][i][j]=false;
        if(c[stp][e][m])
        {
            cout<<t+1;
            return 0;
        }
    }
    return 0;
}
