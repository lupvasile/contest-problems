#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream f("arie.in");
ofstream g("arie.out");

#define eps 0.000001
#define inf 0x3f3f3f3f

struct PUNCT
{
    double x,y;
};
typedef PUNCT POLIGON[25];
int n,m,i;
POLIGON p1,p2;
PUNCT V[40];
int lv;

bool nul(double x)
{
    //return (x<eps) && (x>-eps);
    return x==0.0;
}
double cross_product(PUNCT A, PUNCT B, PUNCT C, PUNCT D)
{
    //vectorii AB si CD
    return (B.x-A.x)*(D.y-C.y)-(B.y-A.y)*(D.x-C.x);
}
PUNCT intersectie(PUNCT A, PUNCT B, PUNCT C, PUNCT D)
{
    PUNCT R;
    double a,b,c,d;
    if(A.x==B.x) swap(A,C),swap(B,D);
    a=A.y-B.y;
    b=A.x-B.x;
    c=C.y-D.y;
    d=C.x-D.x;
    if (!nul(a*d-b*c))
    {
        R.x= (a*d*B.x - b*c*D.x - b*d*B.y + b*d*D.y)/(a*d - b*c);
        if(!nul(b)) R.y=(a*R.x-a*B.x+b*B.y)/b;
        else R.y=(c*R.x-c*D.x+d*D.y);
        if(!(R.x>=min(A.x,B.x) && R.x<=max(A.x,B.x) && R.y>=min(A.y,B.y) && R.y<=max(A.y,B.y)
                && R.x>=min(C.x,D.x) && R.x<=max(C.x,D.x) && R.y>=min(C.y,D.y) && R.y<=max(C.y,D.y)))
            R.x=R.y=inf;
    }
    else R.x=R.y=inf;
    return R;
}
bool punct_in_poligon(PUNCT A,POLIGON P,int n)
{
    for(int i=1; i<=n; ++i) if (cross_product(P[i],P[i+1],P[i],A)<0) return false;
    return true;
}
void det_punctele_din_poligoane()
{
    for(i=1; i<=n; ++i)
    {
        if(punct_in_poligon(p1[i],p2,m)) V[++lv]=p1[i];
    }

    for(i=1; i<=m; ++i)
    {
        if(punct_in_poligon(p2[i],p1,n)) V[++lv]=p2[i];
    }
}
void det_intersectiile_laturilor()
{
    int i,j;
    PUNCT P;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            P=intersectie(p1[i],p1[i+1],p2[j],p2[j+1]);
            if(P.x!=inf) V[++lv]=P;
        }
}
bool cmp(PUNCT A,PUNCT B)
{
    return cross_product(V[1],A,V[1],B)>0;
}
void sorteaza_V()
{
    int l=1;
    for(int i=1; i<=lv; ++i) if(V[i].x<V[l].x) l=i;
        else if (V[i].x==V[l].x) if(V[i].y<V[l].y) l=i;
    swap(V[1],V[l]);
    sort(V+2,V+lv+1,cmp);
}
double aria()
{
    double s;
    sorteaza_V();
    V[++lv]=V[1];
    for(i=1; i<=lv; ++i) s+=cross_product( {0,0},V[i], {0,0},V[i+1]);
    return s/(double)2;
}
int main()
{
    PUNCT p;
    //p=intersectie({0,0},{6,4},{3,0},{3,2});
    //cout<<p.x<<' '<<p.y;
    f>>n;
    for(i=1; i<=n; ++i) f>>p1[i].x>>p1[i].y;
    if(cross_product(p1[1],p1[2],p1[1],p1[3])<0) reverse(p1+1,p1+n+1);
    p1[n+1]=p1[1];

    f>>m;
    for(i=1; i<=m; ++i) f>>p2[i].x>>p2[i].y;
    if(cross_product(p2[1],p2[2],p2[1],p2[3])<0) reverse(p2+1,p2+m+1);
    p2[m+1]=p2[1];

    det_intersectiile_laturilor();
    det_punctele_din_poligoane();

     g<<fixed<<setprecision(3)<<aria();
    //p=intersectie( {2,2}, {2,0},{0,3}, {3,0});
   // cout<<p.x<<' '<<p.y;
    return 0 ;
}
