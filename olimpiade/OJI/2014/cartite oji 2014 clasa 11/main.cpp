#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("cartite.in");
ofstream g("cartite.out");

//#define cout g
#define nmax 205
#define foor(it,a) for(__typeof(a.begin()) it=a.begin();it!=a.end();++it)

int n,m,i,j,p,cartita_x,cartita_y,k,x,y,r,nx,ny;
int a[nmax][nmax];
int depl[13][2]= {{-1,0},{0,1},{1,0},{0,-1},{0,0},{-1,-1},{-1,1},{1,-1},{1,1},{0,-2},{0,2},{-2,0},{2,0} };
struct element
{
    int x,y;
};
vector<element> V;
element me(int a,int b)
{
    element n;
    n.x=a;n.y=b;
    return n;
}
queue <element> q;
struct
{
    int x1,y1,x2,y2;
} muchia[122];
bool on[122];//daca muchia e stearsa sau nu
vector <int> G[nmax][nmax];


/// -1 vulpe
/// -2 gaura
void euler(int x,int y)
{

    foor(it,G[x][y])
    if(on[*it]) {
        on[*it]=false;
        if(muchia[*it].x1==x && muchia[*it].y1==y) euler(muchia[*it].x2,muchia[*it].y2);
        else euler(muchia[*it].x1,muchia[*it].y1);
    }
V.push_back(me(x,y));
//cout<<x<<' '<<y<<'\n';
}
bool on_map(int x,int y)
{
    return (x>=1 && x<=n && y>=1 && y<=m);
}
int main()
{
    f>>p;
    f>>n>>m;
    f>>cartita_x>>cartita_y;
    f>>k;
    for(i=0;i<=n+1;++i) a[i][0]=a[i][m+1]=-1;
    for(j=0;j<=m+1;++j) a[0][j]=a[n+1][j]=-1;
    a[cartita_x][cartita_y]=1;
    for(i=1; i<=k; ++i)
    {
        f>>x>>y>>r;
        switch (r)
        {
        case 0:
            a[x][y]=-1;
            break;
        case 1:
            for(j=0;j<=5;++j) a[x+depl[j][0]][y+depl[j][1]]=-1;
            break;
        case 2:
            for(j=0;j<=12;++j) if(on_map(x+depl[j][0],y+depl[j][1]))a[x+depl[j][0]][y+depl[j][1]]=-1;
            break;
        }
    }
    f>>k;
    for(i=1; i<=k; ++i)
    {
        f>>muchia[i].x1>>muchia[i].y1>>muchia[i].x2>>muchia[i].y2;
        G[muchia[i].x1][muchia[i].y1].push_back(i);
        G[muchia[i].x2][muchia[i].y2].push_back(i);
        if(a[muchia[i].x1][muchia[i].y1]!=-1) a[muchia[i].x1][muchia[i].y1]=-2;
        if(a[muchia[i].x2][muchia[i].y2]!=-1) a[muchia[i].x2][muchia[i].y2]=-2;
        on[i]=true;
    }
    if(p==1)
    {
        if(a[cartita_x][cartita_y]==-2) {
            cout<<cartita_x<<' '<<cartita_y<<" 0";
            return 0;
        }
        q.push(me(cartita_x,cartita_y));
        while(!q.empty())
        {
            x=q.front().x;
            y=q.front().y;
            for(i=0; i<=3; ++i)
            {
                nx=x+depl[i][0];
                ny=y+depl[i][1];
                if(a[nx][ny]==0)
                {
                    q.push(me(nx,ny));
                    a[nx][ny]=a[x][y]+1;
                }
                else if (a[nx][ny]==-2)
                {
                    cout<<nx<<' '<<ny<<' '<<a[x][y];
                    return 0;
                }
            }
            q.pop();
        }
    }
    else{
        euler(muchia[1].x1,muchia[1].y1);
        for(int i=V.size()-1;i>=0;--i) cout<<V[i].x<<' '<<V[i].y<<'\n';
    }
    return 0;
}
