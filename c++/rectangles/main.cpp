#include <iostream>
#include <fstream>
using namespace std;

ifstream f("rectangles.in");
ofstream g("rectangles.out");
#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
/*short a[8000][8000];
int nr,n,i,x1,x2,y1,y2,x,y,mx1=2000000000,my1=2000000000,mx2,my2;
void incearca(int i,int j)
    {
    int x,y,xx,yy;
    x=i+1;
    y=j+1;
    while (a[x][j] && a[i][y])
        {
        yy=j+1;
        xx=i+1;
        while(a[x][yy] && a[xx][y])
            {
            if ((xx==x) && (yy==y))
                {
                nr++;
                break;
                }
            yy++;
            xx++;
            }
        x++;
        y++;
        }
    }*/
int main()
    {
    /*f>>n;
    foor(i,1,n)
        {
        f>>x1>>y1>>x2>>y2;
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
        foor(x,x1,x2) a[x][y1]=1,a[x][y2]=1;
        foor(y,y1,y2) a[x1][y]=1,a[x2][y]=1;
        if (mx1>x1) mx1=x1;
        if (mx2<x2) mx2=x2;
        if(my1>y1) my1=y1;
        if(my2<y2) my2=y2;
        }
    foor(x,mx1,mx2) foor(y,my1,my2) if (a[x][y]) incearca(x,y);
    //cout<<mx1<<" "<<my1<<" "<<mx2<<' '<<my2;
    //foor(x,0,4){foor(y,0,4) cout<<a[x][y]<<" ";cout<<"\n";}*/
    cout<<0;
    return 0;
    }
