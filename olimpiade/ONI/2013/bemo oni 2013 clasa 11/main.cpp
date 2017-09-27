#include <bits/stdc++.h>

using namespace std;

ifstream f("bemo.in");
ofstream g("bemo.out");

#define nmax 1501
#define lin(x) ((x)/m)
#define col(x) ((x)%m)
#define cout g
int a[nmax][nmax],pos[nmax*nmax];
bool on[nmax][nmax];
int n,m,o,j,l,c,i,x,y,val;
#define maxb 100000

int poss(maxb);
char buf[maxb];

int gi()
{
int n(0);
while(buf[poss]<'0' || buf[poss]>'9') if(++poss>=maxb) f.read(buf,maxb),poss=0;
while(buf[poss]>='0' && buf[poss]<='9')
{
    n=n*10+buf[poss]-'0';
    if(++poss>=maxb) f.read(buf,maxb),poss=0;
}
return n;
}
int main()
{
    n=gi();
    m=gi();
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
    {
        a[i][j]=gi();
        on[i][j]=true;
        pos[a[i][j]]=i*m+j;
    }

    for(val=1;val<=n*m;++val) if(on[lin(pos[val])][col(pos[val])])
    {
        l=lin(pos[val]);
        c=col(pos[val]);

        for(i=l+1;i<n && on[i][c-1];++i)
            for(j=c-1;j>=0 && on[i][j];--j) on[i][j]=false;

        for(i=l-1;i>=0 && on[i][c+1];--i)
            for(j=c+1;j<m && on[i][j];++j) on[i][j]=false;

    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j) if(on[i][j])cout<<a[i][j]<<' ';
    }
    return 0;
}
