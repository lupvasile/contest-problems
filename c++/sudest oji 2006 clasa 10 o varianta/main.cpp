#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
ifstream f("sudest.in");
ofstream g("sudest.out");
int a[101][101],costmax[101][101],i,j,n,k,pas,tati_curenti,tati_viitori;
struct elem
    {
    int x,y;
    } el,primu,aux;
queue <elem> q;
elem tata[101][101];
int main()
    {
    f>>n;
    foor(i,1,n) foor(j,1,n) f>>a[i][j];
    f>>k;
    el.x=el.y=1;
    q.push(el);
    costmax[1][1]=a[1][1];
    tati_curenti=1;
    for(; k; k--)
        {
        f>>pas;
        tati_viitori=0;
        for(; tati_curenti; tati_curenti--)
            {
            primu=q.front();
            q.pop();
            if(primu.x+pas<=n)
                if (costmax[primu.x][primu.y]+a[primu.x+pas][primu.y]>costmax[primu.x+pas][primu.y])
                    {
                    costmax[primu.x+pas][primu.y]=costmax[primu.x][primu.y]+a[primu.x+pas][primu.y];
                    el.x=primu.x+pas;
                    el.y=primu.y;
                    q.push(el);
                    tati_viitori++;
                    tata[el.x][el.y]=primu;
                    }
            if(primu.y+pas<=n)
                if (costmax[primu.x][primu.y]+a[primu.x][primu.y+pas]>costmax[primu.x][primu.y+pas])
                    {
                    costmax[primu.x][primu.y+pas]=costmax[primu.x][primu.y]+a[primu.x][primu.y+pas];
                    el.x=primu.x;
                    el.y=primu.y+pas;
                    q.push(el);
                    tati_viitori++;
                    tata[el.x][el.y]=primu;
                    }
            }
        tati_curenti=tati_viitori;
        }
    i=j=n;
    el.x=el.y=0;
    while(i!=0 && j!=0)
        {
        aux=tata[i][j];
        tata[i][j]=el;
        el.x=i;
        el.y=j;
        i=aux.x;
        j=aux.y;

        }
    cout<<costmax[n][n]<<'\n';
    i=j=1;
    while (i!=0 && j!=0)
        {
        cout<<i<<' '<<j<<'\n';
        el=tata[i][j];
        i=el.x;
        j=el.y;
        }
    return 0;
    }