#include <bits/stdc++.h>

using namespace std;

ifstream fin("qxy.in");
ofstream fout("qxy.out");

#define nmax 10010
#define vmax 1000

int v[nmax];
int dp[170][vmax+10];

#define maxb 10000
char buf[maxb];
int pos(maxb);
int gi()
{
    int n(0);
    while(buf[pos]<'0' || buf[pos]>'9')
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    while(!(buf[pos]<'0' || buf[pos]>'9'))
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;
    }
    return n;
}

int main()
{
    int Q,nr,n,i,j,x,y,res,pos;
    n=gi();
    ///rad=64
    nr=((n-1)>>6);

    for(i=0; i<n; ++i)
    {
        v[i]=gi();
        ++dp[i>>6][v[i]];
    }

    for(i=0; i<=nr; ++i)
        for(j=1; j<=vmax; ++j)
            dp[i][j]+=dp[i][j-1];

    Q=gi();
    for(; Q; --Q)
    {
        res=0;
        i=gi();
        j=gi();
        x=gi();
        y=gi();
        --i;
        --j;

        for(; (i&63)!=0 && i<=j; ++i)
            if(v[i]<=y && v[i]>=x) ++res;
        pos=(i>>6);
        for(; i+64<=j; i+=64,++pos)
            if(x==0) res+=dp[pos][y];
            else res+=(dp[pos][y]-dp[pos][x-1]);

        for(; i<=j; ++i)
            if(v[i]<=y && v[i]>=x) ++res;

        fout<<res<<'\n';
    }


    fout.close();
    return 0;
}
