//#include <iostream>
//#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//ifstream f("immortal.in");
//ofstream g("immortal.out");

#define nmax 21
//#define cout g
int n,m,i,k;
int a[nmax][nmax];
struct
    {
    int x,y;
    } im[nmax];
struct
    {
    int x1,y1,x2,y2;
    } sol[nmax];
int depl[4][2]= { {-2,0},{0,2},{2,0},{0,-2} };

inline bool on_map_ok(int x,int y)
    {
    if(x>=1 && x<=n && y>=1 && y<=m) return a[x][y]==0;
    return 0;
    }

void back(int lev)
    {
    int nx,ny,ix,iy,aux,i,j,ox,oy;
    if(lev==k)
        {
        for(i=1; i<lev; ++i)
            {
            //cout<<sol[i].x1<<' '<<sol[i].y1<<' '<<sol[i].x2<<' '<<sol[i].y2;
            //cout<<'\n';
            printf("%d %d %d %d\n",sol[i].x1,sol[i].y1,sol[i].x2,sol[i].y2);
            }
        exit(0);
        }
    for(i=1; i<=k; ++i)
        for(j=3; j>=0; --j)
            if (a[im[i].x][im[i].y])
                if(on_map_ok(im[i].x+depl[j][0],im[i].y+depl[j][1]))
                    if(a[im[i].x+(depl[j][0]>>1)][im[i].y+(depl[j][1]>>1)])
                        {
                        nx=im[i].x+depl[j][0];
                        ny=im[i].y+depl[j][1];
                        ix=im[i].x+(depl[j][0]>>1);
                        iy=im[i].y+(depl[j][1]>>1);
                        ox=im[i].x;
                        oy=im[i].y;

                        a[nx][ny]=i;
                        a[im[i].x][im[i].y]=0;
                        aux=a[ix][iy];
                        a[ix][iy]=0;
                        im[i]={nx,ny};
                        sol[lev]= {ox,oy,nx,ny};

                        back(lev+1);

                        a[nx][ny]=0;
                        a[ox][oy]=i;
                        a[ix][iy]=aux;
                        im[i]={ox,oy};
                        }
    }

int main()
    {
      freopen("immortal.in","r",stdin);
   freopen("immortal.out","w",stdout);

    //f>>n>>m>>k;//k nemuritori
    scanf("%d%d%d",&n,&m,&k);
    for(i=1; i<=k; ++i)
        {
        //f>>im[i].x>>im[i].y;
        scanf("%d%d",&im[i].x,&im[i].y);
        a[im[i].x][im[i].y]=i;
        }
    back(1);
    return 0;
    }
