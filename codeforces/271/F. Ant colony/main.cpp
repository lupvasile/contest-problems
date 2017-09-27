#include <iostream>
#include <fstream>
using namespace std;

//ifstream f("date.in");
//#define cin f

#define nmax 100010


struct elem
    {
    int val,nr;
    };

elem aint[nmax<<2];//aint ii val si nr de valori egale cu aia
int log[nmax];
int n,i,k,x,t,a,b;

int gcd(int d,int i)
{
    int r;
    do
    {
        r=d%i;
        d=i;
        i=r;
    }
    while (r);
    return d;
}
elem combine(elem a,elem b)
{
    elem res={0,0};
    int g=gcd(a.val,b.val);
    if(g==a.val) res.nr+=a.nr;
    if(g==b.val) res.nr+=b.nr;
    res.val=g;
    return res;
}
void build(int st,int dr,int nod)
{
    int m;
    if(st==dr)
    {
        cin>>m;
        aint[nod]={m,1};
        return;
    }

    int l=nod<<1;
    int r=nod<<1|1;
    m=(st+dr)>>1;
    build(st,m,l);
    build(m+1,dr,r);

    aint[nod]=combine(aint[l],aint[r]);
}

elem query(int st,int dr,int nod,int a,int b)
{
    if(a<=st && b>=dr) return aint[nod];

    int m=(st+dr)>>1;
     int l=nod<<1,r=nod<<1|1;

    if(b<=m) return query(st,m,l,a,b);
    if(a>m) return query(m+1,dr,r,a,b);
    return combine(query(st,m,l,a,b),query(m+1,dr,r,a,b));
}

int main()
    {
    cin>>n;
    build(1,n,1);

    cin>>t;
    for(;t;--t)
    {
        cin>>a>>b;
        cout<<b-a+1-query(1,n,1,a,b).nr<<'\n';
    }
    return 0;
    }
