#include <bits/stdc++.h>

using namespace std;
ifstream f("volum.in");
ofstream g("volum.out");

#define cout g
#define nmax 760

int i,j,m,n,x,y,nx,ny,k,sx,sy;
unsigned long long rasp;
int depl[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int a[nmax][nmax];
bool viz[nmax][nmax];
struct eee
    {
    int x,y;
    bool operator<(eee v)const
        {
        return a[x][y]>a[v.x][v.y];
        }
    };
priority_queue<eee> heap;
queue <eee> q;

inline bool on_map(int x,int y)
{
    return (x>=1 && y>=1 && x<=n && y<=m);
}

int main()
    {
    f>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            f>>a[i][j];
            if(i==1 || i==n || j==1 || j==m) heap.push({i,j}),viz[i][j]=true;
            }
    while(!heap.empty())
        {
        sx=heap.top().x;
        sy=heap.top().y;
        heap.pop();
        q.push({sx,sy});
        while(!q.empty())
            {
            x=q.front().x;
            y=q.front().y;
            q.pop();
            for(k=0; k<4; ++k)
                {
                nx=x+depl[k][0];
                ny=y+depl[k][1];
                if(viz[nx][ny] || !on_map(nx,ny)) continue;
                viz[nx][ny]=true;
                if(a[nx][ny]<a[sx][sy])
                    {
                    q.push({nx,ny});
                    rasp+=a[sx][sy]-a[nx][ny];
                    }
                else heap.push({nx,ny});
                }
            }
        }
    cout<<rasp;
    return 0;
    }
