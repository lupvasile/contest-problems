#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("robot2.in");
ofstream fout("robot2.out");
/// ////////////////////////////////

void read();

#define nmax 1010
#define inf 0x3f3f3f3f

bool a[nmax][nmax],inq[nmax][nmax];
int dst[2][nmax][nmax][2];///0 pt orizontala si 1 pt verticala
///0 pt distanta de la start si 1 pt distanta de la finish
int n,x_start,y_start,x_fin,y_fin,minn,nr,gminn;
queue<pair<int,int>> q;
int depl[2][2][2]= { { {0,-1},{0,1} } , { {1,0} , {-1,0} } };
int added[nmax][nmax];

struct eee
{
    int dir,k=0,ox,oy,x,y;

    void sett(int _x,int _y)
    {
        ox=_x,oy=_y;
        dir=0;
        k=-1;
    }

    bool next()
    {
        ++k;
        if(k==2) ++dir,k=0;

        if(dir>1) return false;

        x=ox+depl[dir][k][0];
        y=oy+depl[dir][k][1];


        return true;

    }

} p1,p2;

void calc_dist(int d[nmax][nmax][2],int x,int y)
{
    int nx,ny,dir,h,k;
    d[x][y][0]=d[x][y][1]=0;
    inq[x][y]=0;

    q.push({x,y});
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        inq[x][y]=0;

        for(dir=0; dir<2; ++dir)
            for(h=0; h<2; ++h)
                for(k=0; k<2; ++k)
                {
                    nx=x+depl[h][k][0];
                    ny=y+depl[h][k][1];

                    if(a[nx][ny]) continue;

                    if(d[x][y][dir]+(dir!=h)<d[nx][ny][h])
                    {
                        d[nx][ny][h]=d[x][y][dir]+(dir!=h);
                        if(!inq[nx][ny])
                        {
                            inq[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }

    }

    for(x=1; x<=n; ++x)
        for(y=1; y<=n; ++y)
            if(!a[x][y])
                for(dir=0; dir<2; ++dir)
                    d[x][y][dir]=min(d[x][y][dir],1+d[x][y][dir^1]);

}

void make_dp()
{
    int i,j,dist;
    bool ok=true;
    minn=inf;

    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            if(a[i][j])
            {
                p1.sett(i,j);
                p2.sett(i,j);

                while(p1.next())
                    if(a[p1.x][p1.y]==0)
                    {
                        p2.sett(i,j);
                        while(p2.next() && ok)
                            if(a[p2.x][p2.y]==0)
                            {
                                dist=dst[0][p1.x][p1.y][p1.dir]+dst[1][p2.x][p2.y][p2.dir]+(p1.dir!=p2.dir);
                                if(minn>dist)
                                {
                                    minn=dist;
                                    nr=1;
                                    added[i][j]=dist;
                                }
                                else if(minn==dist)
                                {
                                    if(added[i][j]!=dist)++nr;
                                    added[i][j]=dist;
                                }
                            }


                    }
            }
        somn:;
        }
}

int main()
{
    read();
    calc_dist(dst[0],x_start,y_start);
    calc_dist(dst[1],x_fin,y_fin);

    gminn=minn=min(dst[0][x_fin][y_fin][0],dst[0][x_fin][y_fin][1]);


    make_dp();

    if(minn>=gminn)
    {
        minn=gminn;
        nr=0;
        int i,j;
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
                nr+=a[i][j];
    }

    cout<<gminn<<' '<<minn<<' '<<nr;
    return 0;

}

void read()
{
    int i,j;
    fin>>n;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            fin>>a[i][j];

    for(i=0; i<=n+1; ++i)
        a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=1;

    for(i=0; i<=n+1; ++i)
        for(j=0; j<=n+1; ++j)
            dst[0][i][j][0]=dst[0][i][j][1]=dst[1][i][j][0]=dst[1][i][j][1]=inf;

    fin>>x_start>>y_start>>x_fin>>y_fin;
}
