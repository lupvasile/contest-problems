#include <bits/stdc++.h>
using namespace std;
ifstream fin("flower.in");
ofstream fout("flower.out");
#ifdef INFOARENA 1
#define cout fout
#endif // INFOARENA
/// ///////////////////////////////////////////////////////////

#define nmax 200010
#define lint long long
#define inf (1LL<<60)
int l,r,n,nr;
bool loculununumaiunu;
struct sKonKs
{
    int c,m,p;
    void calatineacasa()
    {
        fin>>c>>m>>p;
    }
} skonx[nmax*3];

struct
{
    lint val=-inf,leftVal=-inf,rightVal=-inf;
    int bossu;
    bool updated;
} aib[4*nmax];

#define get_valuare(bastanu,x) (1ll*(skonx[bastanu].m-skonx[bastanu].p*abs(skonx[bastanu].c-x)))

void propagate(int nod,int st,int dr)
{
    if(!aib[nod].updated)
    {
        aib[nod].updated=1;
        aib[nod].leftVal=get_valuare(aib[nod].bossu,st);
        aib[nod].rightVal=get_valuare(aib[nod].bossu,dr);
        aib[nod].val=min(aib[nod].leftVal,aib[nod].rightVal);

        if(st==dr) return;

        aib[nod<<1].updated=0;
        aib[nod<<1|1].updated=0;
        aib[nod<<1].bossu=aib[nod].bossu;
        aib[nod<<1|1].bossu=aib[nod].bossu;

    }
}


long long query(int nod,int st,int dr)
{
    propagate(nod,st,dr);
    if(l<=st && dr<=r) return aib[nod].val;

    int mid=(st+dr)>>1;
    if(r<=mid) return query(nod<<1,st,mid);
    else if (l>mid) return query(nod<<1|1,mid+1,dr);
    else return min(query(nod<<1,st,mid),query(nod<<1|1,mid+1,dr));
}
void update(int nod,int st,int dr)
{
    propagate(nod,st,dr);
    if(skonx[nr].c<=st && aib[nod].leftVal>=get_valuare(nr,st) || skonx[nr].c>=dr && aib[nod].rightVal>=get_valuare(nr,dr)) return;

    if(aib[nod].leftVal<=get_valuare(nr,st) && aib[nod].rightVal<=get_valuare(nr,dr))
    {
        aib[nod].updated=0;
        aib[nod].bossu=nr;
        propagate(nod,st,dr);
        return;
    }

    if(st==dr) return;

    int mid=(st+dr)>>1;
    int left=nod<<1,right=nod<<1|1;

    update(left,st,mid);
    update(right,mid+1,dr);

    aib[nod].leftVal=aib[left].leftVal;
    aib[nod].rightVal=aib[right].rightVal;
    aib[nod].val=min(aib[left].val,aib[right].val);

}

int main()
{
    int c,q,tip;
    fin>>n>>q;
    aib[1].updated=1;

    for(; q; --q)
    {
        fin>>tip;
        if(tip==1)
        {
            skonx[++nr].calatineacasa();
            update(1,1,n);
        }
        else
        {
            fin>>l>>r;
            cout<<query(1,1,n)<<'\n';
        }
    }
    return 0;
}
