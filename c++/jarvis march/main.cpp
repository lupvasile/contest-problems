#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
//#include <conio.h>
#include <vector>
using namespace std;

ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");

#define cout g

struct pct
{
    long double x,y;
    int nr;
    bool operator !=(const pct &a) const
    {
        return !(x==a.x && y==a.y);
    }
} p[120010];
vector <pct> v;
bool folosit[120010];
pct punct_curent( {1000000000,1000000000}),punct,punct_start;
int n,i,pluus(1);
long double unghi,ug;
long double dist(pct a,pct b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
    {
        f>>p[i].x>>p[i].y;
        p[i].nr=i;
        if(p[i].y<punct_curent.y) punct_curent=p[i];
        else if(p[i].y==punct_curent.y && p[i].x<punct_curent.x) punct_curent=p[i];
    }
    punct_start=punct_curent;
    pluus=1;
    do
    {
        v.push_back(punct_curent);
        unghi=3*M_PI;
        for(i=1; i<=n; ++i)
            if(p[i]!=punct_curent)
            {
                ug=atan2(p[i].y-punct_curent.y,p[i].x-punct_curent.x);
                if(ug<0 && pluus) ug+=2*M_PI;
                if(ug<unghi) punct=p[i],unghi=ug;
                else if (ug==unghi) if(dist(p[i],punct_curent)>dist(punct,punct_curent)) punct=p[i],unghi=ug;
            }
        if(punct_curent.y>=punct.y && punct_curent!=punct_start) pluus=0;
        punct_curent=punct;
        //getch();
    }
    while (punct_curent!=punct_start);
    cout<<v.size()<<'\n';
    for(i=0;i<v.size();++i) cout<<fixed<<setprecision(6)<<v[i].x<<' '<<v[i].y<<'\n';
    return 0;
}
