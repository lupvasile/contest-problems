#include <iostream>
#include <fstream>

using namespace std;

ifstream f("butoane.in");
ofstream g("butoane.out");

#define cout g
#define nmax 1010

int n,i,s,minn;
int v[nmax],touch[nmax];

#define maxb 50000
int pos(maxb);
char buf[maxb];

int gi()
{
    int n=0;
    while(buf[pos]<'0' || buf[pos]>'9')
        if(++pos>=maxb) f.read(buf,maxb),pos=0;

    while(buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    return n;

}

int main()
{
    n=gi();
    for(i=1;i<=n;++i)
    {
        v[i]=gi();
        s+=v[i];
    }
    s=s/n;
    touch[2]=s-v[1];
    minn=min(touch[1],touch[2]);
    for(i=3;i<=n;++i)
    {
        touch[i]=s-touch[i-2]+2*touch[i-1]-v[i-1];
        minn=min(touch[i],minn);
    }

    for(i=1;i<=n;++i) cout<<touch[i]-minn<<'\n';
    return 0;
}
