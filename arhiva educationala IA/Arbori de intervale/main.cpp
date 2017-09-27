#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("arbint.in");
ofstream fout("arbint.out");
/// ////////////////////////

#define nmax 100010

int arb[nmax<<2],pos,val,x,y,n,m;

void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        fin>>arb[nod];
        return;
    }

    int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    build(left,st,mid);
    build(right,mid+1,dr);

    arb[nod]=max(arb[left],arb[right]);
}

void update(int nod,int st,int dr)
{
    if(st==dr)
    {
        arb[nod]=val;
        return;
    }

    int mid=(st+dr)>>1;

    if(pos<=mid) update(nod<<1,st,mid);
    else update(nod<<1|1,mid+1,dr);

    arb[nod]=max(arb[nod<<1],arb[nod<<1|1]);
}

int query(int nod,int st,int dr)
{
    if(x<=st && dr<=y) return arb[nod];

     int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    if(y<=mid) return query(left,st,mid);
    else if(x>=mid+1) return query(right,mid+1,dr);
    else return max(query(left,st,mid),query(right,mid+1,dr));
}

int main()
{
    int tip;
    fin>>n>>m;

    build(1,1,n);

    for(;m;--m)
    {
        fin>>tip;
        if(tip==0)
        {
            fin>>x>>y;
            cout<<query(1,1,n)<<'\n';
        }
        else
        {
            fin>>pos>>val;
            update(1,1,n);
        }
    }

    return 0;
}
