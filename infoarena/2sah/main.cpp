#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("2sah.in");
ofstream g("2sah.out");

#define cout g
#define mod 100003

int n,p,k;
int m[3][3]= {{0,0,1}, {1,0,1},{0,1,1}};

int poww(int a,int p)
    {
    int res(1);
    for(; p; p>>=1)
        {
        if(p&1) res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        }
    return res;
    }

void rez_1()
    {
    cout<<poww(3,k-1);
    }

void mult(int a[][3],int b[][3])
    {
    int c[3][3],i,j,k;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            {
            c[i][j]=0;
            for(k=0; k<3; ++k) c[i][j]+=1ll*a[i][k]*b[k][j]%mod;
            c[i][j]%=mod;
            }
    memcpy(a,c,sizeof c);
    }

void m_poww(int a[][3],int p)
    {
    int res[3][3]= {{1,0,0},{0,1,0},{0,0,1}};

    for(; p; p>>=1)
        {
        if(p&1) mult(res,a);
        mult(a,a);
        }
    memcpy(a,res,sizeof res);
    }

void rez_2()
    {
    if(k>n+1)
        {
        cout<<0;
        return;
        }
    k=n+1-k;
    m_poww(m,k);
    cout<<m[2][2];
    }

int main()
    {
    f>>p>>n>>k;
    if(p==1) rez_1();
    if(p==2) rez_2();
    g.close();
    return 0;
    }
