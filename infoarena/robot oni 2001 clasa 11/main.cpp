#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <queue>
using namespace std;

ifstream f("robot.in");
ofstream g("robot.out");

//#define cout g
#define nmax 51
#define inf 0x3f3f3f3f3f

double xs,xf,ys,yf,x00,y00,x,y,d[210];
int n,i,k,p,j,idx,h,ph,P[210],s[210],st;
struct eee
    {
    double x,y;
    int id;
    bool operator<(eee d)const
        {
        return (y-y00)*(d.x-x00)<(x-x00)*(d.y-y00);
        }
    }point[210];
vector <eee> vf[nmax];
double cost[210][210];

void read_and_build();

inline double dist(double x1,double y1,double x2,double y2)
    {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }

inline double cross(double a1,double a2,double b1, double b2, double c1, double c2)
    {
    return a1*b2+b1*c2+a2*c1-b2*c1-b1*a2-c2*a1;
    }

bool parc_inter(int p,double x1,double y1,double x2,double y2)
    {
    int nr(0);
    double p1,p2,p3,p4;
    for(int j=1; j<vf[p].size(); ++j)
        {
        p1=cross(vf[p][j-1].x,vf[p][j-1].y,vf[p][j].x,vf[p][j].y,x1,y1);
        p2=cross(vf[p][j-1].x,vf[p][j-1].y,vf[p][j].x,vf[p][j].y,x2,y2);
        p3=cross(x1,y1,x2,y2,vf[p][j-1].x,vf[p][j-1].y);
        p4=cross(x1,y1,x2,y2,vf[p][j].x,vf[p][j].y);
        if(p1==0 && p2==0) continue;
        if(p3==0)
            {
            ++nr;
            continue;
            }
        if(p1*p2<0 && p3*p4<0) ++nr;
        }
    return nr>1;
    }

priority_queue <pair<double,int> > q;

void dijkstra(int start,int finish)
    {
    int nod,i;
    double c;
    d[start]=0;
    q.push({0,start});
    while(!q.empty())
        {
        nod=q.top().second;
        c=-q.top().first;
        q.pop();
        if(nod==finish) return;
        for(i=1; i<=idx; ++i)
            if(cost[nod][i]+c<d[i])
                {
                d[i]=cost[nod][i]+c;
                P[i]=nod;
                q.push({-d[i],i});
                }
        }
    }
int iii;
int main()
    {
    f>>xs>>ys;
    f>>xf>>yf;
    f>>n;
    for(i=1; i<=209; ++i) for(j=1; j<=209; ++j) cost[i][j]=inf;
    point[1]={xs,ys};
    point[2]={xf,yf};
    idx=2;
    read_and_build();
    for(i=1; i<=idx; ++i) d[i]=inf;
    dijkstra(1,2);
    s[++st]=2;
    for(i=2;i;i=P[i]) {
        while(st>1 && cross(point[s[st-1]].x,point[s[st-1]].y,point[s[st]].x,point[s[st]].y,point[i].x,point[i].y)==0) --st;
        s[++st]=i;
    }
    cout<<fixed<<setprecision(3);
    cout<<st<<'\n';
    for(;st;--st) cout<<point[s[st]].x<<' '<<point[s[st]].y<<'\n';

    return 0;
    }
void read_and_build()
    {
    for(i=1; i<=n; ++i)
        {
        f>>k;
        x00=y00=inf;
        for(; k; --k)
            {
            f>>x>>y;
            vf[i].push_back({x,y});
            if(x<x00 || x==x00 && y<y00)
                {
                x00=x;
                y00=y;
                p=vf[i].size()-1;
                }
            }
        swap(vf[i][0],vf[i][p]);
        sort(vf[i].begin()+1,vf[i].end());
        for(iii=0;iii<vf[i].size();++iii) cout<<vf[i][iii].x<<' '<<vf[i][iii].y<<'\n';
        for(j=0; j<vf[i].size(); ++j)  vf[i][j].id=++idx,point[idx]={vf[i][j].x,vf[i][j].y};
        vf[i].push_back(vf[i][0]);

        for(j=1; j<vf[i].size(); ++j) cost[ vf[i][j-1].id ][ vf[i][j].id ] = cost [ vf[i][j].id ][ vf[i][j-1].id ]=dist(vf[i][j-1].x,vf[i][j-1].y,vf[i][j].x,vf[i][j].y);
        }

    for(k=1; k<=i; ++k) if(parc_inter(k,xs,ys,xf,yf)) goto asdf3;
    cost[1][2]=cost[2][1]=dist(xs,ys,xf,yf);
    return;
asdf3:
    ;

    for(i=1; i<=n; ++i)
        {
        for(j=0; j+1<vf[i].size(); ++j)
            {
            for(h=1; h<i; ++h)
                {
                for(ph=0; ph+1<vf[h].size(); ++ph)
                    {
                    for(k=1; k<=i; ++k) if (parc_inter(k,vf[h][ph].x,vf[h][ph].y,vf[i][j].x,vf[i][j].y)) continue;
                    cost[ vf[i][j].id ][ vf[h][ph].id ] = cost[ vf[h][ph].id ][ vf[i][j].id ] = dist(vf[h][ph].x , vf[h][ph].y , vf[i][j].x , vf[i][j].y);
                    }
                }
            for(k=1; k<=i; ++k) if(parc_inter(k,xs,ys,vf[i][j].x,vf[i][j].y)) goto asdf;
            cost[ vf[i][j].id ][ 1 ] = cost[ 1 ][ vf[i][j].id ] = dist(xs , ys , vf[i][j].x , vf[i][j].y);
asdf:
            ;
            for(k=1; k<=i; ++k) if(parc_inter(k,xf,yf,vf[i][j].x,vf[i][j].y)) goto asdf1;
            cost[ vf[i][j].id ][ 2 ] = cost[ 2 ][ vf[i][j].id ] = dist(xf , yf , vf[i][j].x , vf[i][j].y);
asdf1:
            ;
            }
        }
    }
