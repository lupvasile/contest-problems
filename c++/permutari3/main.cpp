#include <iostream>
#include <fstream>
using namespace std;

ifstream f("perm3.in");
ofstream g("perm3.out");

#define cout g

int n,a[1001],b[1001],p;
int i,j,mici;
int split,factorial[3000],lf;
int nrpem[3000],lnr;
int v[101];


void bktr(int k);
void afisare();
bool valid(int k);

void primufactorial(int k)
{
    int i,j,minte(0);
    factorial[lf]=1;
    for(i=2;i<=k;i++)
    {   minte=0;
        for(j=0;j<=lf;j++)
        {
        factorial[j]=factorial[j]*i+minte;
        minte=factorial[j]/10;
        factorial[j]%=10;
        }
        while (minte)
        {
            factorial[++lf]=minte%10;
            minte/=10;
        }
    }
}
int pos(int val)
{
    int s(1),d(n),m;
    while (s<=d)
    {
        m=(s+d)/2;
        if(a[m]==val) return m;
        else if(a[m]<val) s=m+1;
        else d=m-1;
    }
}

int calculeaza_elemente_mai_mici(int k)
{
 int nr(0);
 while(k)
 {
     nr+=a[k];
     k-=(k^(k-1)&k);
 }
 return nr;
}
void adauga_la_aib(int pos)
{
    while (pos<=n)
    {
        a[pos]++;
        pos+=pos^(pos-1)&pos;
    }
}
void fa_nou_nrpem()
{
    int j,p,minte;
     minte=0;
      for(j=0;j<=lf;j++)
        {
        p=factorial[j]*mici+minte;
        minte=p/10;
        nrpem[j]+=p%10;
        nrpem[j+1]+=nrpem[j]/10;
        nrpem[j]%=10;
        }
        lnr=max(lnr,lf);
        if(nrpem[lnr+1]) lnr++;
        p=lf;
        while (minte)
        {
            nrpem[++p]+=minte%10;
            nrpem[p+1]+=nrpem[p]/10;
            nrpem[p]%=10;
            minte/=10;
        }
        while (nrpem[p]>9)
        {
            nrpem[p+1]+=nrpem[p]/10;
            nrpem[p]%=10;
            p++;
        }
        lnr=max(p,lnr);
        while (nrpem[lnr]==0) lnr--;
}
void adauga_factorial(int val)
{int minte,j;
    minte=0;
        for(j=0;j<=lf;j++)
        {
        factorial[j]=factorial[j]*val+minte;
        minte=factorial[j]/10;
        factorial[j]%=10;
        }
        while (minte)
        {
            factorial[++lf]=minte%10;
            minte/=10;
        }
}
int main()
{
    f>>n;
   for(i=1; i<=n; i++) f>>a[i];
    for(i=1; i<=n; i++)
    {
        f>>b[i];
        b[i]=pos(b[i]);
    }
    for(i=1; i<=n; i++) a[i]=0;
    split=n;

    while(b[split]>b[split-1] && split>1)
    {
        adauga_la_aib(b[split]);
        split--;
    }
    nrpem[lnr]=1;
    if(split>1)
    {
       adauga_la_aib(b[split]);
       split--;
       primufactorial(n-split);
        while (split)
        {
            mici=calculeaza_elemente_mai_mici(b[split]-1);
            adauga_la_aib(b[split]);
            fa_nou_nrpem();
            split--;
            adauga_factorial(n-split);
        }
    }
    for(i=lnr;i>=0;i--) cout<<nrpem[i];
       /* primufactorial(5);
        nrpem[lnr]=1;
        mici=10;
        fa_nou_nrpem();
    for(i=lnr;i>=0;i--) cout<<nrpem[i];*/
      //  cout<<'\n';
    //bktr(1);
    return 0;
}
////////////////////////////////////


bool valid(int k)
{
    int i;
    for(i=1; i<k; i++) if (v[i]==v[k]) return false;
    return true;
}
void afisare()
{
    for(int i=1; i<=n; i++)cout<<v[i]<<" ";
    cout<<'\n';
}
void bktr(int k)
{
    int i;
    for(i=1; i<=n; i++)
    {
        v[k]=i;
        if (valid(k)) if (k==n) afisare();
            else bktr(k+1);
    }
}
