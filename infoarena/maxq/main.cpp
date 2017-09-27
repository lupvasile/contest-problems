#include <iostream>
#include <fstream>

using namespace std;

ifstream f("maxq.in");
ofstream g("maxq.out");

#define cout g

struct tip_nod
{
    long long secv_max,pref_max,suf_max,sum;
};
tip_nod arb[1<<19],sol;
int n,x,a,b,m;

tip_nod combine(tip_nod a,tip_nod b)
{
    tip_nod res;

    res.sum=a.sum+b.sum;
    res.pref_max=max(a.pref_max,a.sum+b.pref_max);
    res.suf_max=max(b.suf_max,b.sum+a.suf_max);
    res.secv_max=max(a.suf_max+b.pref_max,max(a.secv_max,b.secv_max));

    return res;
}

void build(int nod,int st,int dr)//practic citesti datele de intrare
{
    if(st==dr)
    {
        f>>arb[nod].sum;
        arb[nod].pref_max=arb[nod].suf_max=arb[nod].secv_max=max(arb[nod].sum,0LL);
        return;
    }

    int left,right,mid;
    left=nod<<1;
    right=nod<<1|1;
    mid=(st+dr)>>1;

    build(left,st,mid);
    build(right,mid+1,dr);

    arb[nod]=combine(arb[left],arb[right]);

}

tip_nod query(int nod, int st,int dr,int a,int b)
{
    if(st>=a && dr<=b) return arb[nod];

    int left,right,mid;
    left=nod<<1;
    right=nod<<1|1;
    mid=(st+dr)>>1;

    if(b<=mid) return query(left,st,mid,a,b);
    if(a>mid) return query(right,mid+1,dr,a,b);
    return combine(query(left,st,mid,a,b),query(right,mid+1,dr,a,b));
}

void update(int nod,int st,int dr,int pos, int val)
{
    if(st==dr)
    {
        arb[nod].pref_max=arb[nod].secv_max=arb[nod].suf_max=max(val,0);
        arb[nod].sum=val;
        return;
    }

    int left,right,mid;
    left=nod<<1;
    right=nod<<1|1;
    mid=(st+dr)>>1;

    if(pos<=mid) update(left,st,mid,pos,val);
    else update(right,mid+1,dr,pos,val);

    arb[nod]=combine(arb[left],arb[right]);
}

int main()
{

    f>>n;
    build(1,0,n-1);
    f>>m;
    for(;m;--m)
    {
        f>>x>>a>>b;
        if(x)
        {
            sol=query(1,0,n-1,a,b);
            cout<<sol.secv_max<<'\n';
        }
        else
        {
            update(1,0,n-1,a,b);
        }
    }
    return 0;
}
