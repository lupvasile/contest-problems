#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream f("pinex.in");
ofstream g("pinex.out");
#define cout g
#define bmax 1100000
#define iint long long

iint p[600000],prim[100000];
iint i;

void ciur()
{
    long long i,j;
    for(i=1; i*2+1<=bmax; ++i)
        if (p[i]==0)
        {
            prim[++prim[0]]=2*i+1;
            for(j=2*i*(i+1); j*2+1<=bmax; j+=2*i+1) p[j]=1;
        }
}

iint m,a,b,fact[1000];
void descomp(iint x)
{
   fact[0]=0;
    for(i=1; prim[i]*prim[i]<=x; ++i)
        if (x%prim[i]==0)
        {
            fact[++fact[0]]=prim[i];
            while (x%prim[i]==0) x/=prim[i];
        }
    if(x>1)
        fact[++fact[0]]=x;//,cout<<"ASDfasdfasdf";
    //--fact[0];*/
    /*#define fprim prim
    iint t = 0, d = 0;
    while (B > 1) {
        d++;
        if (B % fprim[d] == 0) {
            fact[++t] = fprim[d];
            while (B % fprim[d] == 0)
                B /= fprim[d];
        }

        if (fprim[d] > sqrt(B) && B > 1) {
            fact[++t] = B;
            B = 1;
        }
    }
    fact[0]=t;
*/
}
iint solve(iint a,iint b)
{
    iint i,nr,m,j;
    descomp(b);
    iint sol=a;//in a-sol cate numere sunt mai mici sau egale cu a si neprime cu b
    for (i=1;i<(1<<fact[0]);++i)
    {
        nr=0,m=1;
        for(j=0;(1<<j)<=i;++j) if (i&(1<<j))
        {
            m*=fact[j+1];
            ++nr;
        }
        if(nr%2==1) sol-=a/m;
        else sol+=a/m;
    }
    return sol;
}
int main()
{
    prim[++prim[0]]=2;
    ciur();
    //for(i=1;i<=prim[0];++i) cout<<prim[i]<<'\n';
    f>>m;
    for(;m;--m)
    {
        f>>a>>b;
        cout<<solve(a,b)<<'\n';
    }
    return 0;
}
