#include <iostream>

using namespace std;

typedef unsigned long long intreg;

#define mod 1000000007

intreg n,s,f[22],rez;
intreg sum;
int i;
bool semn;

void read_data();
intreg combinari(intreg n,intreg k);
intreg put(intreg x, intreg p);
intreg invers[22];
void pre();

int main()
{
    read_data();
    pre();
    rez=combinari(n+s-1,n-1);
    for(int p=(1<<n)-1; p; --p)
    {
        semn=0;//0 pentru - si 1 pentru +
        sum=0;
        for(int aux=p,i=1; aux; aux>>=1,++i) if(aux&1) semn^=1,sum+=f[i]+1;
        if(s>=sum)  if(semn)
            {
                rez=(rez-combinari(n-1+s-sum,n-1)+mod)%mod;
            }
            else rez=(rez+combinari(n-1+s-sum,n-1))%mod;
    }
    cout<<rez%mod;

    return 0;
}

intreg combinari(intreg n,intreg k)
{
//combinari de n luate cate k
    if (k>n) return 0;
    n%=mod;
    intreg rasp=1;
    for(int i=0;i<k;++i)
    {
        rasp=rasp*(n-i)%mod;
        rasp=rasp*invers[i+1]%mod;
    }
    return rasp;
}

intreg put(intreg x, intreg p)
{
    intreg rez=1;
    for(; p; p>>=1)
    {
        if(p&1) rez=rez*x%mod;
        x=x*x%mod;
    }
    return rez;
}

void pre()
{
    for(int i=1;i<=21;++i) invers[i]=put(i,mod-2);
}

void read_data()
{
    cin>>n>>s;
    for(i=1; i<=n; ++i)
    {
        cin>>f[i];
    }
}
