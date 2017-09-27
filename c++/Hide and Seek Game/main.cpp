#include <bits/stdc++.h>
using namespace std;
ifstream fin("hideandseek.in");
ofstream fout("hideandseek.out");

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
/// ////////////////////////////////////////////////////

#define nmax 1000010
#define ll long long

int v[2][nmax],n,len[nmax],where[nmax],pos[nmax],nr;
ll a,b,X,Y;

void afis(int v[])
{
    for(int i=1; i<=n; ++i) cout<<v[i]<<' ';
}

void read(int v[])
{
    for(int i=1;i<=n;++i) fin>>v[i];
}

void add(int a[],int b[])
{
    int res[nmax];
    for(int i=1;i<=n;++i) res[i]=a[b[i]];
    for(int i=1;i<=n;++i) a[i]=res[i];
}

void cicle(int i,int poss,int v[])
{
    ++len[nr];
    where[i]=nr;
    pos[i]=len[nr];

    if(where[v[i]]==0) cicle(v[i],poss+1,v);

}

void make_cicle(int v[])
{
    int i;
    nr=0;
    for(i=1;i<=n;++i) where[i]=0;
    for(i=1;i<=n;++i) if(where[i]==0)
    {
        ++nr;
        cicle(i,1,v);
    }
}

void powww(int v[],ll p)
{
    int res[nmax];

}

int main()
{
    int i;
    fin>>n>>a>>b;
    read(v[0]);
    read(v[1]);

    gcd(a,b,X,Y);

    make_cicle(v[0]);
    powww(v[0],X);

    make_cicle(v[1]);
    powww(v[1],Y);

    add(v[0],v[1]);

    afis(v[0]);
    return 0;
}
