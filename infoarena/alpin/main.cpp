#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("alpin.in");
ofstream g("alpin.out");

#define cout g
#define nmax 1100
#define foor(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)


struct element{int x,y,val;
bool operator <(const element a) const
{
    return val<a.val;
}
};


vector <element> v;
int depl[4][2]={ {-1,0},{0,1},{1,0},{0,-1} };
int n,i,j,x,y,nx,ny,maxx;
int a[nmax][nmax],dp[nmax][nmax];
element finish;

void afis(int x,int y)
{
    if(dp[x][y]==1)
    {cout<<x<<' '<<y<<'\n';
    return;
    }
    for(int i=0;i<=3;++i)
        if(dp[x][y]-1==dp[x+depl[i][0]][y+depl[i][1]])
    {
        afis(x+depl[i][0],y+depl[i][1]);
        cout<<x<<' '<<y<<'\n';
        return;
    }
}
void bordare();
int gi();
int main()
{
    n=gi();
    bordare();
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
    {
        a[i][j]=gi();
        v.push_back({i,j,a[i][j]});
    }
    sort(v.begin(),v.end());
    foor(it,v)
    {
        x=it->x;
        y=it->y;
        dp[x][y]=1;
        for(i=0;i<=3;++i)
        {
            nx=x+depl[i][0];
            ny=y+depl[i][1];
            if(a[x][y]>a[nx][ny]) dp[x][y]=max(dp[x][y],dp[nx][ny]+1);
        }
        if(maxx<dp[x][y])
        {
            maxx=dp[x][y];
            finish=*it;
        }
    }
    cout<<maxx<<'\n';
    afis(finish.x,finish.y);
    return 0;
}
void bordare()
{
    for(int i=0;i<=n+1;++i) a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=32000;
}

#define nb 10000
char buf[nb];
int p(nb);
int gi()
{
    int n=0;
    while (buf[p]<'0' || buf[p]>'9') if(++p>=nb) f.read(buf,nb),p=0;
     while (buf[p]>='0' && buf[p]<='9')
    {
        n=n*10+buf[p]-'0';
        if(++p>=nb) f.read(buf,nb),p=0;
    }
    return n;
}
