#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#define zid 98888888
#define for(i,a,b) for (i=a;i<=b;i++)
#define cout g
using namespace std;
struct punct
    {
    int x,y;
    };
ifstream f("ai.in");
ofstream g("ai.out");
int a,b,t1,t2,s1,s2,s3,s4,r1,r2,r3,r4,v[1002][1002],v2[1002][1002],zmax,z,n,i,j,k,min1,min2,min3,min4;
int depl[5][3]= {{},{0,-1,0},{0,0,1},{0,1,0},{0,0,-1}};
bool ok;
int zidul()
    {
    for(i,1,n)
        {
        z=0;
        ok=false;
        for(j,1,n)
            {
            if (v[i][j]==zid) if (ok) z++;
                else ok=true,z=1;
            else ok=false;
            if (z>zmax) zmax=z;
            }
        }
    for(j,1,n)
        {
        z=0;
        ok=false;
        for(i,1,n)
            {
            if (v[i][j]==zid) if (ok) z++;
                else ok=true,z=1;
            else ok=false;
            if (z>zmax) zmax=z;
            }
        }
    return zmax;
    }
bool blocheaza(int x1,int y1,int x2,int y2)
    {    if (((x1>=x2 && x1<=t1) || (x1>=t1 && x1<=x2)) && ((y1>=y2 && y1<=t2) || (y1<=y2 && y1>=t2)))
    if((y1-t2)*(x2-t1)==(x1-t1)*(y2-t2)) return true;
    return false;
    }
void Lee(int i, int j,int &min1,int &min2,int v[1002][1002])
    {
    queue <punct> coada;
    punct p,p2;
    int ii;
    p.x=i;
    p.y=j;
    coada.push(p);
    if (blocheaza(p.x,p.y,s1,s2)) min1=0;
    if (blocheaza(p.x,p.y,s3,s4)) min2=0;
    while(!coada.empty())
        {
        p=coada.front();
        coada.pop();
        for(ii,1,4)
            {
            p2.x=p.x+depl[ii][1];
            p2.y=p.y+depl[ii][2];
            if (v[p2.x][p2.y]==0 && p2.x>=1 && p2.y>=1 && p2.x<=n && p2.y<=n)
                {
                v[p2.x][p2.y]=v[p.x][p.y]+1;
                if (blocheaza(p2.x,p2.y,s1,s2)) if (min1>v[p2.x][p2.y]-1) min1=v[p2.x][p2.y]-1;//,cout<<p2.x<<' '<<p2.y<<'\n';
                coada.push(p2);
                if (blocheaza(p2.x,p2.y,s3,s4)) if(min2>v[p2.x][p2.y]-1) min2=v[p2.x][p2.y]-1;
                }
            }
        }
       // cout<<min1<<" "<<min2<<"\n";
    }
void afiseaza(int a[][1002])
    {
    int i,j;
    for(i,1,n)
        {
        for(j,1,n)if (a[i][j]==zid)cout<<setw(3)<<'*';
        else if (a[i][j]==2*zid)cout<<setw(3)<<'&';
        else if (a[i][j]==3*zid)cout<<setw(3)<<'%';
        else cout<<setw(3)<<a[i][j];
                cout<<"\n";
        }
    }
int main()
    {
    zmax=0;
    f>>n;
    f>>t1>>t2>>s1>>s2>>s3>>s4>>r1>>r2>>r3>>r4;
    f>>k;
    for(i,1,k)
        {
        f>>a>>b;
        v[a][b]=zid;
        v2[a][b]=zid;
        }
    v[t1][t2]=zid;
    v2[t1][t2]=zid;
    v[r1][r2]=1;
    v2[r3][r4]=1;
    min1=min2=min3=min4=zid;
    Lee(r1,r2,min1,min2,v);
    Lee(r3,r4,min3,min4,v2);
    cout<<zidul()<<"\n"<<min(max(min1,min4),max(min2,min3));
    /*v[s1][s2]=v[s3][s4]=v2[s1][s2]=v2[s3][s4]=2*zid;
    v[t1][t2]=v2[t1][t2]=3*zid;
    afiseaza(v);
    cout<<"\n********\n\n";
    afiseaza(v2);
    cout<<"\n";
    cout<<min1<<" "<<min2<<" "<<min3<<" "<<min4<<" ";
    t1=16;t2=6;
    cout<<blocheaza(4,2,10,4);*/
    return 0;
    }
