#include <iostream>
#include <fstream>
using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("perioada01.in");
ofstream fout("perioada01.out");

#define pmax 1000010

long long n,a[pmax],bet;
int p;

bool verifica(int k)
{
    int t=p/k,i;
    //t de 1 sunt intr-o perioada

    for(i=t+1;i<=p;++i)
    {
        if((i-1)%t==0)
        {
            if(a[i]-a[i-1]!=bet) return false;
        }
        else if(a[i]-a[i-1]!=a[i-t]-a[i-t-1]) return false;
    }
    return true;
}
#define maxb 100000
char buf[maxb];
int pos(maxb);

int gi()
{
    long long n(0);
    while(buf[pos]<'0' || buf[pos]>'9')
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;

    while(buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    }
    return n;
}

int main()
    {
    int i,k;
    fin>>n;
    p=gi();
    for(i=1;i<=p;++i) a[i]=gi();
    bet=a[1]+n-a[p];
    /*if(verifica(p))
                {
                cout<<n/p;
                fout.close();
                return 0;
                }*/
    for(k=p/2; k>=2; --k)
        if(p%k==0 && n%k==0)
            if(verifica(k))
                {
                cout<<n/k;
                fout.close();
                return 0;
                }

    cout<<-1;
    fout.close();
    return 0;
    }
