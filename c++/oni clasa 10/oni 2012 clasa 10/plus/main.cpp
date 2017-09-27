#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("plus2.in");
ofstream fout("plus2.out");

#define cout fout
int stack[2000][60],vf;
int poz[60],inc_poz(0);
int n,x,i,nr_p,nr_p_max;
void afisare(int v[])
{
    for(; v[0]>0; --v[0])cout<<v[v[0]];
    cout<<'\n';
}
int comp(int a[],int b[])
{
    if(a[0]>b[0]) return 1;
    if(a[0]<b[0]) return -1;
    for(int i=a[0]; i; --i) if (a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    return 0;
}
void cate(int a[],int b[])
{
    int i,nr(0),nr_max(0),j,m;
    if(comp(a,b)==0) return;
    for(i=1; i<=a[0]; ++i)
    {
        nr=0;
        m=min(b[0],i);
       for (j=0; j<m; ++j) if(a[i-j]==b[b[0]-j]) ++nr;
        if(nr>nr_max)
        {
            nr_max=nr;
            poz[++poz[0]]=i;
              inc_poz=poz[0];
        }
        else if (nr==nr_max && nr) poz[++poz[0]]=i;
    }
    for(; i<=a[0]+b[0]-1; ++i)
    {
        nr=0;
        m=b[0]-(i-a[0]);
        for(j=0; j<m; ++j) if(a[a[0]-j]==b[m-j]) ++nr;
        if(nr>nr_max)
        {
            nr_max=nr;
            poz[++poz[0]]=i;
            inc_poz=poz[0];
        }
        else if (nr==nr_max && nr) poz[++poz[0]]=i;
    }
}
void aduna(int a[],int b[],int r[],int d)
{
    int p_b(1),p_a(1),t(0);
    r[0]=0;
    while (p_b<=b[0]-d) r[++r[0]]=b[p_b],++p_b;
    while (p_a<=d-b[0]) r[++r[0]]=a[p_a],++p_a;
    while (p_a<=a[0] && p_b<=b[0])
    {
        if(a[p_a]!=b[p_b])
        {
            r[++r[0]]=a[p_a]+b[p_b]+t;
            t=r[r[0]]/10;
            r[r[0]]%=10;
        }
        ++p_a,++p_b;
    }
    if (p_a<=a[0]) r[++r[0]]=a[p_a]+t,++p_a,t=0;
    while (p_a<=a[0]) r[++r[0]]=a[p_a],++p_a;
    if (p_b<=b[0]) r[++r[0]]=b[p_b]+t,++p_b,t=0;
    while (p_b<=b[0]) r[++r[0]]=b[p_b],++p_b;
    if(t) r[++r[0]]=t;
}

void plus1(int a[],int b[])
{
    int rez[60],r[60];
    rez[0]=0;
    memset(rez,0,sizeof rez);
    memset(r,0,sizeof r);
    poz[0]=0;
    inc_poz=0;
    cate(a,b);
    int p=inc_poz;
    if(poz[0])
    {
        for(; p<=poz[0]; ++p)
        {
            aduna(a,b,r,poz[p]);
            if(comp(r,rez)>0) memcpy(rez,r,(r[0]+1)*sizeof (int));
        }
    }
    else
    {
        rez[0]=1;
        rez[1]=0;
    }
    memcpy(a,rez,(rez[0]+1)*sizeof (int));
}
int main()
{
    f>>n;
    for(; n; --n)
    {
        f>>x;
        if(x==-1) stack[++vf][0]=-1,++nr_p;
        else if(x==-2)
        {
            x=vf;
            while (stack[x][0]!=-1) --x;
            memcpy(stack[x],stack[x+1],(stack[x+1][0]+1)*sizeof stack[x+1][0]);
            for(i=2; x+i<=vf; ++i) plus1(stack[x],stack[x+i]);
            vf=x;
            --nr_p;
        }
        else
        {
            ++vf;
            stack[vf][0]=0;
            do stack[vf][++stack[vf][0]]=x%10,x/=10; while (x);
        }
        nr_p_max=max(nr_p_max,nr_p);
    }
    for(i=2;i<=vf;++i) plus1(stack[1],stack[i]);
    cout<<nr_p_max<<'\n';
    afisare(stack[1]);
    return 0;
}
