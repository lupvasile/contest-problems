#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
#define cout fout
ifstream fin("terenuri.in");
ofstream fout("terenuri.out");
/// ////////////////////////////////

void magic();
void read();
void convex_hull();

#define nmax 100010
#define abs(x) (x<0.0 ? -x:x)
#define eps 1e-10


struct point
{
    double x,y;

    bool operator <(const point &other) const
    {
        if(abs(x-other.x)<eps) return y<other.y;
        return x<other.x;
    }

    void operator +=(const point &other)
    {
        x+=other.x;
        y+=other.y;
    }
    void operator -=(const point &other)
    {
        x-=other.x;
        y-=other.y;
    }
};

double det(const point &a,const point &b,const point &c)
{
    return a.x*b.y + b.x*c.y + a.y*c.x - c.x*b.y - b.x*a.y - a.x*c.y;
}

struct eee
{
    double angle;
    point p;
    bool operator < (const eee &other) const
    {
        return angle<other.angle;
    }
};

point P[nmax];
set<eee> S;
set<eee>:: iterator it,it1,it2;
int n,m,st[nmax];
point G {0,0};

bool cmp(const point &a,const point &b)
{
    double x=det(P[0],a,b);
    if(-eps<x && x<eps) return a<b;
    return x>0.0;
}

bool scoate(const point &a,const point &b,const point &c)
{
    double x=det(a,b,c);
    if(-eps<x && x<eps) return b<c;
    return x<0.0;
}

inline set<eee>::iterator pprev(set<eee>::iterator it)
{
    if(it==S.begin()) it=S.end();
    --it;
    return it;
}

inline set<eee>::iterator nnext(set<eee>::iterator it)
{
    ++it;
    if(it==S.end()) it=S.begin();
    return it;
}

int main()
{
    read();
    convex_hull();
    magic();
    return 0;
}

void magic()
{
    double angle;
    bool ok;
    point p;
    cout<<S.size()<<'\n';
    for(;m;--m)
    {
        fin>>p.x>>p.y;
        p-=G;
        angle=atan2(p.y,p.x);

        it=S.upper_bound({angle,p});
        if(it==S.end()) it=S.begin();
        it1=pprev(it);
        it2=pprev(it1);

        point p1=it->p;
        point p2=it1->p;

        if(det(pprev(it)->p,it->p,p)>eps)
            {
                cout<<S.size()<<'\n';
                continue;
            }

        while(scoate(it2->p,it1->p,p))
        {
            S.erase(it1);
            it1=it2;
            it2=pprev(it2);
        }

        it2=it;
        it1=nnext(it2);

        while(scoate(p,it2->p,it1->p))
        {
            S.erase(it2);
            it2=it1;
            it1=nnext(it1);
        }

        S.insert({angle,p});

        cout<<S.size()<<'\n';

    }
}

void read()
{
    int i,pmin=0;
    double x,y;

    fin>>n>>m;
    for(i=0; i<n; ++i)
    {
        fin>>P[i].x>>P[i].y;
        if(P[i]<P[pmin]) pmin=i;
    }

    swap(P[0],P[pmin]);
    sort(P+1,P+n,cmp);
}

void convex_hull()
{
    int i;

    st[++st[0]]=0;
    st[++st[0]]=1;

    for(i=2; i<n; ++i)
    {
        while(st[0]>1 && det(P[st[st[0]-1]],P[st[st[0]]],P[i])<eps) --st[0];
        st[++st[0]]=i;
    }

    for(i=1; i<=st[0]; ++i)
        G+=P[st[i]];

    G.x/=st[0];
    G.y/=st[0];

    for(i=1; i<=st[0]; ++i)
    {
        P[st[i]]-=G;
        S.insert({atan2(P[st[i]].y,P[st[i]].x),P[st[i]]});
    }
}
