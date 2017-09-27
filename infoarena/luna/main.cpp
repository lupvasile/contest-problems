#include <iostream>
#include <fstream>

using namespace std;

ifstream f("luna.in");
ofstream g("luna.out");

#define nmax 52

int n,m,i,j,lmax,l,minn,k;
int col[nmax][nmax],a[nmax][nmax],dp[nmax*nmax][nmax];
int inf(99999);
bool viz[5100];
int main()
{
    f>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            f>>a[i][j];
            viz[a[i][j]]=true;
            col[i][j]=1;
            if(a[i][j]==a[i-1][j]) col[i][j]+=col[i-1][j];
        }

    for(l=1; l<=n; ++l)
        for(i=1; i<=m; ++i)
        {
            minn=inf;
            for(j=i; j<=m && a[l][i]==a[l][j]; ++j)
            {
                minn=min(minn,col[l][j]);
                dp[a[l][i]][j-i+1]=max(minn,dp[a[l][i]][j-i+1]);
            }
        }
    f>>k;
    for(n=1; n<=k; n++)
    {
        f>>l>>i>>j;
        if(!viz[l])
        {
            g<<"Tara de provenienta nu are parcele pe Luna!\n";
            continue;
        }
        if(dp[l][i]>=j || dp[l][j]>=i) g<<"Cererea poate fi satisfacuta!\n";
        else g<<"Cererea nu poate fi satisfacuta!\n";
    }
    return 0;
}
