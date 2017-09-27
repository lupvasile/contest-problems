#include <cstdio>
#include <iostream>
//#include <fstream>

using namespace std;

//ifstream f("date.in");
//#define cin f

#define nmax 50010

struct elem{long long sufix_sum,prefix_sum,max_sum,tot_sum;};
elem aint[nmax<<3];
int n,x,y,Q;

elem combine(elem a,elem b)
{
    elem r;
    r.tot_sum=a.tot_sum+b.tot_sum;
    r.prefix_sum=max(a.prefix_sum,a.tot_sum+b.prefix_sum);
    r.sufix_sum=max(b.sufix_sum,b.tot_sum+a.sufix_sum);
    r.max_sum=max(max(a.max_sum,b.max_sum),a.sufix_sum+b.prefix_sum);

    return r;
}

void Build(int st,int dr,int nod)
{
    int m,l,r;
    if (st==dr)
    {
        scanf("%d",&m);
        aint[nod].sufix_sum=aint[nod].max_sum=aint[nod].prefix_sum=aint[nod].tot_sum=m;
        return;
    }

    l=nod<<1;
    r=nod<<1|1;
    m=(st+dr)>>1;
    Build(st,m,l);
    Build(m+1,dr,r);

    aint[nod]=combine(aint[l],aint[r]);
}

elem query(int st,int dr,int nod,int a,int b)
{
    if(a<=st && b>=dr) return aint[nod];

    int m,l,r;
    m=(st+dr)>>1;
    l=nod<<1;
    r=nod<<1|1;

    if(b<=m) return query(st,m,l,a,b);
    if(a>m) return query(m+1,dr,r,a,b);
    return combine(query(st,m,l,a,b),query(m+1,dr,r,a,b));

}

int main()
{
    scanf("%d",&n);
    Build(1,n,1);
    scanf("%d",&Q);
    for(;Q;--Q)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,n,1,x,y).max_sum);

    }
    return 0;
}
