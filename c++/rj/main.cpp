#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;
ifstream f("rj.in");
ofstream g("rj.out");
#define nmax 101
#define zid 999
#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
int m,n,romeo[nmax][nmax],julieta[nmax][nmax],i,j,minn,ri,rj,ji,jj,raspi,raspj;
char c;
int depl[2][8]={{-1,-1,0,1,1,1,0,-1},{0,1,1,1,0,-1,-1,-1}};
struct element {int x,y;};
void citire()
{

    f>>n>>m;
    f.get();
    foor(i,1,n)
    {
        foor(j,1,m)
        {
            f.get(c);
            if(c=='X') romeo[i][j]=julieta[i][j]=zid;
            else if (c=='R')
            {
                romeo[i][j]=1;
                ri=i;
                rj=j;
            }
            else if (c=='J')
            {
                julieta[i][j]=1;
                ji=i;
                jj=j;
            }
        }
        f.get();
    }
}
void rezolva()
{
    minn=zid;
    foor(i,1,n) foor(j,1,m) if(romeo[i][j]==julieta[i][j] && romeo[i][j]<minn && romeo[i][j]>0)
    {
        minn=romeo[i][j];
        raspi=i;
        raspj=j;
    }
}
void afisare(int z[][nmax])
{
    int i,j;
    foor(i,1,n)
    {
        foor(j,1,m) cout<<setw(9)<<z[i][j];
        cout<<'\n';
    }
}
void bordare()
{
    int x;
    foor(x,0,n+1) romeo[x][0]=julieta[x][0]=romeo[x][m+1]=julieta[x][m+1]=zid;
    foor(x,0,m+1) romeo[0][x]=julieta[0][x]=romeo[n+1][x]=julieta[n+1][x]=zid;
}
void lee(int v[][nmax],int i,int j)
{
    int h;
    queue <element> coada;
    element e;
    e.x=i;
    e.y=j;
    coada.push(e);
    while (!coada.empty())
    {
        foor(h,0,7)
            if (v[coada.front().x+depl[0][h]][coada.front().y+depl[1][h]]==0)
            {
                e.x=coada.front().x+depl[0][h];
                e.y=coada.front().y+depl[1][h];
                v[e.x][e.y]=v[coada.front().x][coada.front().y]+1;
                coada.push(e);
            }
            coada.pop();
    }

}
int main()
{
    citire();
    bordare();
    /*afisare(romeo);
    cout<<"****************************************************\n";
    afisare(julieta);*/
    lee(romeo,ri,rj);
    lee(julieta,ji,jj);

    rezolva();
    cout<<minn<<' '<<raspi<<' '<<raspj;
    //cout<<"Asd"<<jj;
    return 0;
}
