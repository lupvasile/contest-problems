#include <iostream>
#include <fstream>
#include <queue>

#define cout g
#define cout g
#define foor(i,a,b) for(i=a;i<=b;i++)
#define inf 0x3f3f3f

using namespace std;

ifstream f("taxe1.in");
ofstream g("taxe1.out");

struct elem {int x,y;};
int n,s,i,j,a[101][101],v[101][101];
int depl[2][4]={{-1,0,1,0},{0,1,0,-1}};

int posibil(int a,int x,int k)
{
    if (x+depl[a][k]<=n && x+depl[a][k]>=1) return x+depl[a][k];
    return 0;
}
void parcurge(int x,int y)
{
    int i;
    queue <elem> q;
    elem e,prim;
    e.x=x;
    e.y=y;
    q.push(e);
    while(!q.empty())
    {
        prim=q.front();
        q.pop();
        foor(i,0,3)
        {
            e.x=posibil(0,prim.x,i);
            e.y=posibil(1,prim.y,i);
            if(e.x && e.y)
                    if(v[prim.x][prim.y]+a[e.x][e.y]<v[e.x][e.y])
                        {
                            v[e.x][e.y]=v[prim.x][prim.y]+a[e.x][e.y];
                            q.push(e);
                        }
        }

    }

}
void init()
{
    int i,j;
    foor(i,1,n) foor(j,1,n) v[i][j]=inf;
}
int main()
{
   f>>s>>n;
   foor(i,1,n) foor(j,1,n) f>>a[i][j];
   init();
   v[1][1]=a[1][1];
   parcurge(1,1);
   if(s>=v[n][n]) cout<<s-v[n][n];
   else cout<<-1;
    return 0;
}
