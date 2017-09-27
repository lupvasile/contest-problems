#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
# define copac 990000
# define foor(i,a,b) for(i=a;i<=b;i++)
ifstream f("alee.in");
ofstream g("alee.out");
struct s {int x; int y;};
s el;
queue <s> q;
int x,y,a[200][200],n,c,px,py,i,h,d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int main()
{
    f>>n>>c;
    for(;c;c--)
    {
        f>>x;
        f>>y;
        a[x][y]=copac;
    }
    foor(i,0,n+1) a[i][0]=1,a[i][n+1]=1,a[0][i]=1,a[n+1][i]=1;
    f>>el.x>>el.y>>px>>py;
    q.push(el);
    a[el.x][el.y]=1;
    while (!q.empty())
    {
        foor(h,0,3)
        if (a[q.front().x+d[h][0]][q.front().y+d[h][1]]==0)
        {
            el.x=q.front().x+d[h][0];
            el.y=q.front().y+d[h][1];
            a[el.x][el.y]=a[q.front().x][q.front().y]+1;
            if (el.x==px && el.y==py) while (!q.empty()) q.pop();
            q.push(el);
        }
        q.pop();
    }
    g<<a[px][py];
    return 0;
}
