#include <iostream>
#include <fstream>
using namespace std;




ifstream f("xp.in");
ofstream g("xp.out");
//varianta de 50 p
/*unsigned long long a,b,val,l_a,l_b,n,p,q,i,j,f_a,f_b,phi;
unsigned long long prod,rez;

void calc_phi(unsigned long long q)
{
    unsigned long long i;
    phi=q;
    for(i=2;i*i<q;++i)
    {
        if(q%i==0)
        {
            phi=phi*(i-1)/i;
            while (q%i==0) q/=i;
        }
    }
    if (q) phi=phi*(q-1)/q;
}
unsigned long long pow(unsigned long long a,unsigned long long p)
{
    unsigned long long res(1);
    for(;p;p>>=1)
    {
        if(p&1) res=res*a%q;
        a=a*a%q;
    }
    return res;
}
int main()
{
f>>n>>a>>b>>p>>q;
prod=val=max(1ULL, ((1 % p) ^ (((a + 1) & (b + 1)) % p)) % p);
l_a=a;l_b=b;
f_a=a;f_b=b;

for(i=2;i<=n;++i)
{
    a=((l_a + p - 1) ^ (l_b + 1)) % p;
    b=((l_a + p - 1) | (l_b + 1)) % p;
    val=max(1ULL, ((i % p) ^ (((a + 1) & (b + 1)) % p)) % p);
    prod=prod*val%q;
    l_a=a;
    l_b=b;
}
calc_phi(q);
a=f_a;b=f_b;
l_a=a;l_b=b;
val=max(1ULL, ((1 % p) ^ (((a + 1) & (b + 1)) % p)) % p);
rez^=(prod*pow(val,phi-1)%q);
for(i=2;i<=n;++i)
{
    a=((l_a + p - 1) ^ (l_b + 1)) % p;
    b=((l_a + p - 1) | (l_b + 1)) % p;
    val=max(1ULL, ((i % p) ^ (((a + 1) & (b + 1)) % p)) % p);
    rez^=(prod*pow(val,phi-1)%q);
    l_a=a;
    l_b=b;
}

cout<<rez;
    return 0;
}
*/
unsigned long long n,a,b,p,q,prod_cur,l_a,l_b,size,k,i;
unsigned long long val,f_a,f_b,prs,j,res,cnt;
unsigned long long pr[3000],prd[3000],v[3000],pp[3000];
#define vall(i) (max(1ULL, ((i % p) ^ (((a + 1) & (b + 1)) % p)) % p))
#define aaa (((l_a + p - 1) ^ (l_b + 1)) % p)
#define bbb (((l_a + p - 1) | (l_b + 1)) % p)
//#define cout g
int main()
{
    f>>n>>a>>b>>p>>q;
    for(size=1;size*size<=n;++size);
    --size;
    f_a=l_a=a;f_b=l_b=b;
    k=0;
    for(i=1;i<=n;++i)
        {
            if ((i-1)%size==0)
            {
                pr[k]=prod_cur;
                ++k;
                prod_cur=1;
            }
            val=vall(i);
            l_a=a;l_b=b;
            a=aaa;
            b=bbb;
            prod_cur=prod_cur*val%q;
        }
    pr[k]=prod_cur;
    for(i=k-1;i>0;--i) prd[i]=prd[i+1]*pr[i]%q;


    a=l_a=f_a;b=l_b=f_b;
    prs=1;
    for(i=1;i<k;++i)
    {
        for(j=1;j<=size;++j)
        {
            ++cnt;
            v[j]=vall(cnt);
            l_a=a;l_b=b;
            a=aaa;
            b=bbb;
        }
        pp[j]=0;
        for(j=size-1;j>0;--j) pp[j]=pp[j+1]*v[j]%q;
        for(j=1;j<=size;++j)
        {
            res=res^(prs*pp[j+1]*prd[i+1]%q);
            prs=prs*v[j]%q;
        }
    }
    //cout<<size;
    cout<<res;
    size=n-(k-1)*size;
    for(j=1;j<=size;++j)
        {
            ++cnt;
            v[j]=vall(cnt);
            l_a=a;l_b=b;
            a=aaa;
            b=bbb;
        }
        pp[j]=0;
        for(j=size-1;j>0;--j) pp[j]=pp[j+1]*v[j]%q;
        for(j=1;j<=size;++j)
        {
            res=res^(prs*pp[j+1]*prd[i+1]%q);
            prs=prs*v[j]%q;
        }
    cout<<res<<'\n';
    return 0;
}
