#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int n,k,a[51][51],poz_nou[2601],i,j,p,h,dir,lv(0),x,kk,minn;
int depl[2][4]= {{0,1,0,-1},{1,0,-1,0}};
struct
{
    int elem,rast;
} v[50];

void citire();
void initializare();
void amestecare();
void afisare(int z[],int l);
void fa_poz_nou();
void sirul_de_raspuns();
int bin_src(int val);
void raspunde();
void back(int k,int s,int p);
int cmmmc(int x,int y);
int cmmdc(int x,int y);

int main()
{
    citire();
    initializare();
    amestecare(); //acuma am in matrice la fiecare casuta initiala
    fa_poz_nou();
    sirul_de_raspuns();// v[i].elem cate elemente is pe pozitia initiala dupa v[i].rast raturnari
    raspunde();
    //cout<<"Asdfasdf";
    //printf("0");
    return 0;
}
void raspunde()
{
    minn=999999999;
    back(1,0,1);
    cout<<minn;
}
void back(int k,int s,int p)
{
    if(k<=lv)
        if(s<kk)
        {
            if(p%v[k].rast==0)back(k+1,s+v[k].elem,p);
            else
            {
                back(k+1,s,p);
                back(k+1,s+v[k].elem,cmmmc(p,v[k].rast));
            }
        }
    if (s==kk)
    {
        s=0;
        for(int i=1; i<=lv; i++) if(p%v[i].rast==0) s+=v[i].elem;
        if(s==kk)
            if(p<minn) minn=p;
    }
}
int cmmmc(int x,int y)
{
    return (x*y)/cmmdc(x,y);
}
int cmmdc(int d,int i)
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
void sirul_de_raspuns()
{
    for(i=1; i<=n*n; i++)
    {
        p=1;
        x=poz_nou[i];
        while (x!=i)
        {
            ++p;
            x=poz_nou[x];
        }
        bin_src(p);
    }
}

int bin_src(int val)
{
    int s(1),d(lv),m,i;
    while(s<=d)
    {
        m=(s+d)/2;
        if(v[m].rast==val)
        {
            v[m].elem++;
            return 0;
        }
        else if (v[m].rast<val) s=m+1;
        else d=m-1;
    }
    ++lv;
    for(i=lv; i>s; i--) v[i]=v[i-1];
    v[s].rast=val;
    v[s].elem=1;
    return 0;
}
void citire()
{
    freopen("spirala1.in","r",stdin);
    freopen("spirala1.out","w",stdout);
    scanf("%d%d",&n,&kk);
}
void initializare()
{
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=(i-1)*n+j;

}
void amestecare()
{
    for(k=1; k<=n; k++) poz_nou[k]=a[1][k];
    i=1;
    j=n;
    dir=0;
    k=n-1;
    p=n;
    while (k)
    {
        dir++;
        if(dir==4) dir=0;
        for(h=1; h<=k; h++)
        {
            i=i+depl[0][dir];
            j=j+depl[1][dir];
            p++;
            poz_nou[p]=a[i][j];
        }
        dir++;
        if(dir==4) dir=0;
        for(h=1; h<=k; h++)
        {
            i=i+depl[0][dir];
            j=j+depl[1][dir];
            p++;
            poz_nou[p]=a[i][j];
        }
        k--;
    }
    //afisare(poz_nou,p);
    //am desfasurat in spirala
    p=1;
    for(i=1; i<=n; i++)
        if (i&1) for(j=1; j<=n; j++)
            {
                a[i][j]=poz_nou[p];
                p++;
            }
        else for(j=n; j; j--)
            {
                a[i][j]=poz_nou[p];
                p++;
            }
    //afisare(a,n);
}
void afisare(int z[],int l)
{
    int i,j;
    for(i=1; i<=l; i++)
    {
        //for(j=1;j<=l;j++)
        cout<<' '<<z[i];
        //cout<<'\n';
    }
}
void fa_poz_nou()
{
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            poz_nou[a[i][j]]=(i-1)*n+j;
}
