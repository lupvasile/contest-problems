#include <fstream>
#include <iostream>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("flooow.in");
ofstream fout("flooow.out");

/// ////////////////////////////////////////

#define nmax 200010

struct sume
{
    int left,right,val;
};

struct elem_aib
{
    sume s[2][4];
    bool updated;
    ///0 minim si 1 maxim
    ///al 2-lea indice 0 prefix, 1 suma la toata secv, 2 sufix, 3 rezultatu(minim sau maxim)

    void _set(int x,int l,int r)
    {
        int i,j;
        for(i=0; i<2; ++i)
            for(j=0; j<4; ++j)
                s[i][j]= {l,r,x};
    }

    void update()
    {
        int i;
        for(i=0; i<4; ++i) swap(s[0][i],s[1][i]);
        for(i=0; i<4; ++i)
        {
            s[0][i].val=-s[0][i].val;
            s[1][i].val=-s[1][i].val;
        }
    }

};

int minnn(int x,int y)
{
    return min(x,y);
}

int maxxx(int x,int y)
{
    return max(x,y);
}

int k,n,l,r;
elem_aib aib[nmax*2];
void build(int,int,int);
typedef int(*fff)(int,int);
fff fnc[2]= {minnn,maxxx};
inline elem_aib combine(elem_aib &a,elem_aib &b)
{
    elem_aib res;

    int i,k;

    for(k=0; k<2; ++k)
    {
        ///prefix
        if(a.s[k][0].val==fnc[k](a.s[k][0].val,a.s[k][1].val+b.s[k][0].val))
        {
            res.s[k][0]=a.s[k][0];
        }
        else
        {
            res.s[k][0]= {a.s[k][1].left,b.s[k][0].right,a.s[k][1].val+b.s[k][0].val};
        }

        ///sufix
        if(b.s[k][2].val==fnc[k](b.s[k][2].val,a.s[k][2].val+b.s[k][1].val))
        {
            res.s[k][2]=b.s[k][2];
        }
        else
        {
            res.s[k][2]= {a.s[k][2].left,b.s[k][1].right,a.s[k][2].val+b.s[k][1].val};
        }

        res.s[k][1]= {a.s[k][1].left,b.s[k][2].right,a.s[k][1].val+b.s[k][1].val};

        ///asta ii maximu/ respectiv minimu

        if(a.s[k][3].val==fnc[k](a.s[k][3].val,b.s[k][3].val))
        {
            res.s[k][3]=a.s[k][3];
        }
        else
        {
            res.s[k][3]=b.s[k][3];
        }

        if(a.s[k][2].val+b.s[k][0].val==fnc[k](a.s[k][2].val+b.s[k][0].val,res.s[k][3].val))
        {
            res.s[k][3]= {a.s[k][2].left,b.s[k][0].right,a.s[k][2].val+b.s[k][0].val};
        }
    }

    res.updated=1;
    return res;
}


void propagate(int nod,int st,int dr)
{
    if(!aib[nod].updated)
    {
        int i;
        aib[nod].updated=true;
        aib[nod].update();

        if(st==dr) return;

        aib[nod<<1].updated^=1;
        aib[nod<<1|1].updated^=1;
    }
}

void main_query(int &s,int &l,int &r)
{
    propagate(1,1,n);
    s=aib[1].s[1][3].val;
    l=aib[1].s[1][3].left;
    r=aib[1].s[1][3].right;
}

void update_aib(int nod,int st,int dr)
{
    if(st>dr) return;
    if(l<=st && dr<=r)
    {
        aib[nod].updated^=1;
        propagate(nod,st,dr);
        return;
    }

    int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    propagate(nod,st,dr);

    if(l<=mid) update_aib(left,st,mid);
    if(mid+1<=r) update_aib(right,mid+1,dr);

    propagate(left,st,mid);
    propagate(right,mid+1,dr);
    aib[nod]=combine(aib[left],aib[right]);
}

#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
{
    int n(0),semn(1);
    while((buf[pos]<'0' || buf[pos]>'9') && buf[pos]!='-')
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;

    if(buf[pos]=='-')
    {
        semn=-1;
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    }

    while(buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    }
    return n*semn;
}

int main()
{
    int h,i,sum,res(0);
    //fin>>h>>k;
    h=gi();
    k=gi();
    for(; h; --h)
    {
        //fin>>n;
        n=gi();
        if(n==0) continue;
        build(1,1,n);

        for(i=1; i<=k; ++i)
        {
            main_query(sum,l,r);
            if(sum<=0) break;
            res+=sum;
            update_aib(1,1,n);
        }
    }

    cout<<k<<' '<<res;
    return 0;
}


void build(int nod,int st,int dr)
{
    if(st>dr) return;

    if(st==dr)
    {
        int x;
        //fin>>x;
        x=gi();
        aib[nod].updated=1;
        aib[nod]._set(x,st,dr);
        return;
    }

    int left=nod<<1;
    int right=nod<<1|1;
    int mid=(st+dr)>>1;

    build(left,st,mid);
    build(right,mid+1,dr);

    aib[nod]=combine(aib[left],aib[right]);
}
