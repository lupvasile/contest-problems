#include <bits/stdc++.h>
using namespace std;
ifstream f("ikebana.in");
ofstream g("ikebana.out");

#define cell(x,y) ((x)*3+(y))
#define mod 666013
#define vmx 70

int rec[vmx][vmx],init[vmx],ff[vmx];
int n,p,t,i,j,sum;

void mult(int a[][vmx],int b[][vmx])
    {
    int n=vmx-1,m=vmx-1,pp=vmx-1;
    int i,j,k;
    int c[vmx][vmx];
    memset(c,0,sizeof c);

    for(i=0; i<=n; ++i)
        for(j=0; j<=pp; ++j)
            for(k=0; k<=m; ++k)
                c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j]%mod)%mod;
    memcpy(a,c,sizeof c);
    }

void poww(int a[][vmx],int p)
    {
    int res[vmx][vmx];
    memset(res,0,sizeof res);
    for(int i=0;i<=vmx-1;++i) res[i][i]=1;
    for(; p; p>>=1)
        {
        if(p&1) mult(res,a);
        mult(a,a);
        }
    }

int main()
    {
    f>>n>>p>>t;

    for(j=1; j<=p; ++j)
        {
        rec[cell(j,0)][cell(j-1,0)]=2;
        rec[cell(j,0)][cell(j-1,2)]=2;
        rec[cell(j,0)][cell(j-1,1)]=1;

        rec[cell(j,1)][cell(j-1,0)]=1;

        rec[cell(j,2)][cell(j-1,2)]=t-4;
        rec[cell(j,2)][cell(j-1,0)]=t-4;
        }

    rec[cell(p,0)][cell(p,0)]=2;
    rec[cell(p,0)][cell(p,2)]=2;
    rec[cell(p,0)][cell(p,1)]=1;

    rec[cell(p,1)][cell(p,0)]=1;

    rec[cell(p,2)][cell(p,2)]=t-4;
    rec[cell(p,2)][cell(p,0)]=t-4;

    rec[cell(0,2)][cell(p,0)]=1;
    rec[cell(0,2)][cell(p,2)]=1;

    poww(rec,n-1);

    init[cell(0,2)]=1;
    init[cell(p,0)]=2;
    init[cell(p,2)]=t-4;
    n=vmx-1;
    for(i=0;i<=n;++i)
        for(j=0;j<=n;++j) ff[i]=(ff[i]+rec[i][j]*init[j])%mod;
    for(j=0;j<=p;++j) sum=(sum+ff[cell(j,0)]+ff[cell(j,2)])%mod;
    cout<<sum;
    return 0;
    }
