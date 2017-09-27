#include <iostream>
#include <fstream>
#include <queue>
//#include <iomanip>
using namespace std;

ifstream f("insule.in");
ofstream g("insule.out");

#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
struct arme
    {
    short int x,y;
    };
queue <arme> q;
arme element;
char c;
short int vizitat[102][102],j,i,m,n,map[102][102],nr,ng,nb,p,maxx,a[102][102],vecin_cu_r[102][102],depl[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};

short int vecin(short int i,short int j, short int k)
    {
    int h;
    foor(h,0,3) if(map[i+depl[h][0]][j+depl[h][1]]==k || map[i+depl[h][0]][j+depl[h][1]]==k-4) return 1;
    return 0;
    }
void fillv(short int i,short int j,short int k)
    {
    int h;
    map[i][j]=k;
    foor(h,0,3) if(map[i+depl[h][0]][j+depl[h][1]]==map[i][j]-4)
        fillv(i+depl[h][0],j+depl[h][1],k);
    }
short int lee()
    {
    int h;
    //while (!q.empty())q.pop();
    while (!q.empty())
        {
        foor(h,0,3)
            {
            element.x=q.front().x+depl[h][0];
            element.y=q.front().y+depl[h][1];
            if(vizitat[element.x][element.y]==0 && element.x>=1 && element.y>=1 && element.x<=n && element.y<=m && map[element.x][element.y]==0)
                {
                vizitat[element.x][element.y]=vizitat[q.front().x][q.front().y]+1;
                q.push(element);
                if(a[element.x][element.y]) return vizitat[element.x][element.y];
                }

            }
        q.pop();
        }
    return 32000;
    }
int main()
    {
    //grija la citire trebe sa o faci cu char
    f>>n>>m;
    foor(i,1,n)
    foor(j,1,m)
        {
        f>>c;
        map[i][j]=c-'0';
        }

    foor(i,1,n)
    foor(j,1,m)
        {
        if (map[i][j]==1)
            {
            nr++;
            fillv(i,j,5);
            }
        if (map[i][j]==2)
            {
            ng++;
            fillv(i,j,6);
            }
        if (map[i][j]==3)
            {
            nb++;
            fillv(i,j,7);
            }
        if(map[i][j]==0) a[i][j]=vecin(i,j,6);
        }

    foor(i,1,n)
    foor(j,1,m)
    if (map[i][j]==0)
        if (vecin(i,j,5))
            {
            element.x=i;
            element.y=j;
            q.push(element);
            vizitat[i][j]=1;
               }
    cout<<nr<<' '<<ng<<' '<<nb<<' '<<lee();
    return 0;
    }
