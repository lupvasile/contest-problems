#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f("tsunami.in");
ofstream g("tsunami.out");

#define cout g

int a[1010][1010],n,m,h,nr,i,j,x,y;
queue <pair<int,int> >q;
int deplx[]={-1,0,1,0};
int deply[]={0,1,0,-1};

int main()
{
    f>>n>>m>>h;
    for(i=0; i<=n+1; ++i) a[i][0]=a[i][m+1]=20;
    for(i=0; i<=m+1; ++i) a[0][i]=a[n+1][i]=20;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            f>>a[i][j];
            if(a[i][j]==0)
            {
                if(a[i][j-1]<h && a[i][j-1]) q.push(make_pair(i,j-1)),a[i][j-1]=20;
                if(a[i-1][j]<h && a[i-1][j]) q.push(make_pair(i-1,j)),a[i-1][j]=20;
            }
            else if((a[i][j-1]==0 || a[i-1][j]==0) && a[i][j]<h ) q.push(make_pair(i,j)),a[i][j]=20;
        }
    while (!q.empty())
    {
        ++nr;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(i=0; i<=3; ++i)
            if(a[x+deplx[i]][y+deply[i]]<h && a[x+deplx[i]][y+deply[i]]>0)
            {
                a[x+deplx[i]][y+deply[i]]=20;
                q.push(make_pair(x+deplx[i],y+deply[i]));
            }

    }
    cout<<nr;
    return 0;
}
