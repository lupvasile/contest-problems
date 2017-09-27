#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
#define cout g
int n,i;
struct pct {double x,y;} p[120010];
pct stack[120010];
int st(1);

double cross_product(pct a,pct b,pct c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool cmp(pct a,pct b)
{
    return cross_product(p[0],a,b)>0;
}
void read()
{
    int punct(0);
    f>>n;
    for(i=0;i<n;++i)
    {
        f>>p[i].x>>p[i].y;
        if(p[i].y<p[punct].y) punct=i;
        else if (p[i].y==p[punct].y && p[i].x<p[punct].x) punct=i;
    }
    swap(p[0],p[punct]);
}
void convex_hull()
{
    sort(p+1,p+n,cmp);
    stack[0]=p[0];
    stack[1]=p[1];
    for(i=2;i<n;++i)
    {
        while (st && cross_product(stack[st-1],stack[st],p[i])<=0) --st;
        stack[++st]=p[i];
    }
}
void write()
{
    cout<<st+1<<'\n';
    for(i=0;i<=st;++i) cout<<fixed<<setprecision(9)<<stack[i].x<<' '<<stack[i].y<<'\n';
}
int main()
{
    read();
    convex_hull();
    write();
    return 0;
}
