#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream f("dreptunghiuri2.in");
ofstream g("dreptunghiuri2.out");

#define cout g
int n,m,a[1010][1010],nr(1),i,j,numar_zone,nr_patratele,h,v[1010][1010];
bool on[1010*101];
int grad_max,nr_gmax;
int deplx[]= {-1,-1,0,1,1,1,0,-1};
int deply[]= {0,1,1,1,0,-1,-1,-1};
struct
{
    int x1,y1,x2,y2;
} d;//colt stanga sus si dreapta jos
void fill(int x,int y)
{
    a[x][y]=nr;
    ++nr_patratele;
    if(x<d.x1 || x==d.x1 && y<=d.y1) d.x1=x,d.y1=y;
    if(x>d.x2 || x==d.x2 && y>=d.y2) d.x2=x,d.y2=y;
    int i,nx,ny;
    for(i=0; i<=7; ++i)
    {
        nx=x+deplx[i];
        ny=y+deply[i];
        if(a[nx][ny]==1) fill(nx,ny);
    }
}
int main()
{
    f>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            f>>a[i][j];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i][j]==1)
            {
                ++nr;
                on[nr]=true;
                nr_patratele=0;
                d= {n,m,0,0};
                fill(i,j);
                if(d.x1!=d.x2 && d.y1!=d.y2) h=(d.y2-d.y1+1)*2+(d.x2-d.x1-1)*2;
                else h=d.y2-d.y1+d.x2-d.x1+1;
                if(nr_patratele!=h) on[nr]=false;
                else
                {
                    ++v[d.x1][d.y1];
                    --v[d.x1][d.y2+1];
                    --v[d.x2+1][d.y1];
                    ++v[d.x2+1][d.y2+1];
                }
            }
    for(i=1; i<=nr; ++i) if(on[i]) ++numar_zone;

    for(i=1; i<=n+1; ++i)
        for(j=1; j<=m+1; ++j)
        {
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            if(grad_max<v[i][j])
            {
                nr_gmax=1;
                on[a[i][j]]=false;
                grad_max=v[i][j];
            }
            else if (grad_max==v[i][j] && on[a[i][j]]) ++nr_gmax,on[a[i][j]]=false;
        }
    cout<<numar_zone<<' '<<grad_max<<' '<<nr_gmax;
    return 0;
}
