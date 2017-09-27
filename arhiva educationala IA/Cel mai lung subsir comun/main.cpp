#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
/// ///////////////////////////////////////////

#define nmax 1030
#define unite(x,y) (((x)<<11)+y)
#define get_fst(x) ((x)>>11)
#define get_sec(x) (x&2047)

int a[nmax],b[nmax],fat[nmax][nmax],dp[nmax][nmax];

void afis(int x,int y)
{
    if(fat[x][y]) afis(get_fst(fat[x][y]),get_sec(fat[x][y]));
    if(a[x]==b[y]) cout<<a[x]<<' ';
}

int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1; i<=n; ++i) fin>>a[i];
    for(i=1; i<=m; ++i) fin>>b[i];

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                fat[i][j]=unite(i-1,j-1);
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    fat[i][j]=unite(i,j-1);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    fat[i][j]=unite(i-1,j);
                }
            }

    cout<<dp[n][m]<<'\n';
    afis(n,m);
    return 0;
}
