#include <iostream>

using namespace std;

#define lung unsigned long long

lung nr(lung x)
{
    lung res=0;

    lung sum=0,aux=x,p=1;
    aux=x/10/10;

    int i,uc,q;

    while(aux)
    {
        aux/=10;
        p*=10;
        sum+=(aux*p);
    }

    res=res + sum*45;
    res=res + (sum+x/10)*25;

    uc=x%10;
    for(i=1;i<=uc;i+=2) res+=i;

    p=5;
    q=10;
    for(aux=x/10;aux;aux/=10,p*=10,q*=10)
    {
        uc=aux%10;
        for(i=1;i<uc;++i) res+=1ull*i*p;
        res+=1ull*uc*((x%q + 1));
    }
    return res;




}

int ssum(int x)
{
    int s=0;
    for(;x;x/=10)
    {
        s+=x%10;
    }
    return s;
}

lung gs(int a,int b)
{
    lung res;
    for(int i=a;i<=b;++i)
        if(i%2==1) res+=ssum(i);
    return res;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<(1ull*(nr(b)-nr(a-1)));
    cout<<"\n"<<gs(a,b);
    return 0;
}
