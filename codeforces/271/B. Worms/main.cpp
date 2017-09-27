#include <iostream>
//#include <fstream>

using namespace std;

#define nbuf 131072
//#define cin f
#define nmax 1000010

//ifstream f("date.in");

char buf[nbuf];
int pos(nbuf);
int gI()
{
    int n=0;
    while (buf[pos]<'0' || buf[pos]>'9')
    {
        if(++pos>=nbuf) cin.read(buf,nbuf),pos=0;
    }
    while (buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=nbuf) cin.read(buf,nbuf),pos=0;
    }
    return n;
}

int v[nmax];
int i,x(1),a,n;
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        for(;a>0;--a,++x) v[x]=i;
    }
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        cout<<v[a]<<'\n';
    }
    return 0;
}
