#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define cout g

ifstream f("mission.in");
ofstream g("mission.out");

int n;
struct element{int x,y,nr;} v[1001];
int i,minn,capat,l;
element a[1001];
element stiva[1001];
bool sters[1001];
bool cmp(element a,element b)
{     int x,y;
x=(a.x-v[minn].x)*(b.y-v[minn].y);
y=(a.y-v[minn].y)*(b.x-v[minn].x);
if (x-y) return x-y<0;
else if(a.x==b.x)return a.y<b.y;
else return a.x<b.x;
}
bool turn_left(element k,element a, element b)
{
    return (a.x-k.x)*(b.y-k.y)-(a.y-k.y)*(b.x-k.x)>0;
}

void graham()
{   int i;
    stiva[0]=v[0];
    stiva[1]=v[1];
    capat=1;
    for(i=2;i<=n-1;i++)
    {
        while (capat>2 && turn_left(stiva[capat-1],stiva[capat],v[i])) capat--;
        stiva[++capat]=v[i];
    }
}
bool ccp(element a, element b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    f>>n;
    minn=0;
    for(i=0;i<=n-1;i++) {
        v[i].nr=i;
        f>>v[i].x>>v[i].y;
        if(v[i].x<v[minn].x) minn=i;
        else if (v[i].x==v[minn].y && v[i].y<v[minn].y) minn=i;
    }
    swap(v[minn],v[0]);
    sort(v+1,v+n,cmp);
    graham();
    cout<<stiva[0].nr<<' ';
    i=1;
    sters[stiva[0].nr]=1;
    while (stiva[i].x>stiva[i-1].x || stiva[i].x==stiva[i-1].x && stiva[i].y>stiva[i-1].y)
    {
        cout<<stiva[i].nr<<' ';
        sters[stiva[i].nr]=1;
        i++;
    }
    for(i=n-1;i;i--) if(sters[v[i].nr]==0)
    {
        a[++l]=v[i];
    }
    sort(a+1,a+l+1,ccp);

    for(i=l;i;i--)cout<<a[i].nr<<' ';
    return 0;
}
