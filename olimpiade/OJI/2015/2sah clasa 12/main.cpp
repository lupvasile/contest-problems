#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("2sah.in");
ofstream fout("2sah.out");
/// ////////////////////////////////

#define mod 100003
int n,t,k;
int a[3][3]=
{
    {0,0,1},
    {1,0,1},
    {0,1,1}
};


int poww(int x,int p)
{
    int res(1);
    for(; p; p>>=1)
    {
        if(p&1) res=1ll*res*x%mod;
        x=1ll*x*x%mod;
    }
    return res;
}

void mult(int a[][3],int b[][3])
{
    int i,j,res[3][3];
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            res[i][j]=0;

    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            for(k=0; k<3; ++k)
            {
                res[i][j]+=1ll*a[i][k]*b[k][j]%mod;
                if(res[i][j]>=mod) res[i][j]-=mod;
            }

    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            a[i][j]=res[i][j];
}

void poww(int x[][3],int p)
{
    int res[3][3]= {{1,0,0},{0,1,0},{0,0,1}};
    int i,j;
    for(; p; p>>=1)
    {
        if(p&1) mult(res,x);
        mult(x,x);
    }

    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            x[i][j]=res[i][j];
}

void afis(int a[][3])
{
    int i,j;
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            cout<<a[i][j]<<" \n"[j==2];
}
int main()
{
    fin>>t>>n>>k;

    if(t==1) cout<<poww(3,k-1);
    else
    {
        k=n+1-k;
        if(k<0)
        {
            cout<<0;
            return 0;
        }

        poww(a,k);
        cout<<a[2][2];
    }
    return 0;
}
