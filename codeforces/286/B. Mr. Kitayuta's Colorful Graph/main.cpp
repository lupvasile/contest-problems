#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
#define nmax 110

int n,m,i,nc,nr,a,j,b,c;
int dad[nmax][nmax];

int ddad(int a,int c)
{
    if(dad[c][a]!=a) dad[c][a]=ddad(dad[c][a],c);
    return dad[c][a];
}

int main()
{

    cin>>n>>m;
    for(i=1;i<=m;++i) for(j=1;j<=n;++j) dad[i][j]=j;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        nc=max(nc,c);
        if(ddad(a,c)!=ddad(b,c)) dad[c][ddad(b,c)]=dad[c][ddad(a,c)];
    }
    cin>>m;
    for(;m;--m)
    {
        cin>>a>>b;
        nr=0;
        for(i=1;i<=nc;++i) if(ddad(a,i)==ddad(b,i)) ++nr;
        cout<<nr<<'\n';
    }
    return 0;
}
