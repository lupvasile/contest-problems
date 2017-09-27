#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA


ifstream fin("poligon.in");
ofstream fout("poligon.out");

#define nmax 810
#define EPS 1e-5
struct point
    {
    int x,y;
    };

point vf[nmax];//varfurile poligonului
int n,m,csort[60010],nr_benzi,rasp,nrvbenzi;///csort pentru counting sort la x-ul varfurilor
class STRIP;

struct ppoint
    {
    long double y1,y2;
    long double mid;
    bool operator<(ppoint a) const
        {
        //return max(y1,y2)<max(a.y1,a.y2);
        return mid<a.mid;
        }
    };
struct pppoint
    {
     int y1,y2;
    bool operator<(pppoint a) const
        {
        return max(y1,y2)<max(a.y1,a.y2);
        }
    };

bool contine(int x1,int x2,point a,point b);///daca latura cu capetele a,b e continuta intre x1 si x2

long double cross_prod(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
    return x1*y2+x2*y3+x3*y1-x3*y2-x2*y1-x1*y3;
}

class STRIP
    {
    public:
        int x1,x2;
        vector<ppoint> lat;//y-ul capetelor laturii ce sunt pe fasie
        void define(int a,int b)
            {
            x1=a;
            x2=b;
            }

        void get_lat()
            {
            int i;
            long double m;
            point a,b;

            for(i=1; i<=n; ++i)
                if(contine(x1,x2,vf[i],vf[i+1]))
                    {
                        a=vf[i];
                        b=vf[i+1];

                        if(a.x>b.x) swap(a,b);
                        m=(b.y-a.y)/(long double)(b.x-a.x);
                        lat.push_back({m*(x1-a.x)+a.y,m*(x2-a.x)+a.y,(m*(x1-a.x)+a.y+m*(x2-a.x)+a.y)/(long double)2});

                    }

            sort(lat.begin(),lat.end());

            }

        bool find_h(point P)
        {
            int step,n=lat.size(),pos=0;

            if(cross_prod(x1,lat.front().y1,x2,lat.front().y2,P.x,P.y)<0-EPS) return false;
            if(cross_prod(x1,lat.back().y1,x2,lat.back().y2,P.x,P.y)>0+EPS) return false;

            for(step=1;step<n;step<<=1);
            for(;step;step>>=1)
                if(step+pos<n)
                    if(cross_prod(x1,lat[step+pos].y1,x2,lat[step+pos].y2,P.x,P.y)>=0-EPS) pos+=step;


            if(abs(cross_prod(x1,lat[pos].y1,x2,lat[pos].y2,P.x,P.y))<=0+EPS) return true;

            return (pos+1)&1;

        }


    };

class V_LINE
{
    public:
    int x;
    vector<pppoint> lat_v;
    void define(int a)
            {
            x=a;
            }
    void get_lat()
            {
            int i;
            point a,b;

            for(i=1; i<=n; ++i)
                if(vf[i].x==vf[i+1].x && vf[i].x==x)
                    {
                        a=vf[i];
                        b=vf[i+1];

                        if(a.y>b.y) swap(a,b);
                        lat_v.push_back({a.y,b.y});///y1 ii ala de jos
                    }
             sort(lat_v.begin(),lat_v.end());
            }
    bool find_v(point P)
        {
            int step,n=lat_v.size(),pos=0;

            for(step=1;step<n;step<<=1);
            for(;step;step>>=1)
                if(pos+step<n)
                    if(P.y>=lat_v[pos+step].y1) pos+=step;
            if(pos>=n) return false;
            if(P.y>=lat_v[pos].y1 && P.y<=lat_v[pos].y2) return true;
            return false;
        }

};
STRIP benzi[nmax];
V_LINE vbenzi[nmax];

int main()
    {
    int i,a,b,pos,step;
    point P;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        {
        fin>>vf[i].x>>vf[i].y;
        ++csort[vf[i].x];
        }
    vf[n+1]=vf[1];

    a=b=-1;
    for(i=0; i<=60000; ++i)
        {
        if(csort[i])
            {
            a=b;
            b=i;
            if(a!=-1)
                benzi[++nr_benzi].define(a,b);

            vbenzi[++nrvbenzi].define(i);
            }
        }
    for(i=1;i<=nr_benzi;++i) benzi[i].get_lat();
    for(i=1;i<=nrvbenzi;++i) vbenzi[i].get_lat();
    ///pana aici ai citit datele si stii de unde pana unde ii o banda si ce laturi contine

    for(;m;--m)
    {
        fin>>P.x>>P.y;
        if(P.x<benzi[1].x1 || P.x>benzi[nr_benzi].x2) continue;

        pos=0;

        for(step=1;step<=nr_benzi;step<<=1);
        for(;step;step>>=1)
            if(pos+step<=nr_benzi)
                if(benzi[pos+step].x2<P.x) pos+=step;

        ++pos;

        if(benzi[pos].find_h(P) ) ++rasp;
        else {

            pos=0;

        for(step=1;step<=nrvbenzi;step<<=1);
        for(;step;step>>=1)
            if(pos+step<=nrvbenzi)
                if(vbenzi[pos+step].x<=P.x) pos+=step;

        if(P.x==vbenzi[pos].x) if(vbenzi[pos].find_v(P))
                    ++rasp;
    }
    }

    cout<<rasp;
    return 0;
    }
bool contine(int x1,int x2,point a,point b)
    {
        if(a.x>b.x) swap(a,b);
        if(a.x==b.x) return false;
        return (a.x<=x1 && b.x>=x2);
    }
