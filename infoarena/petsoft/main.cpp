#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream f("petsoft.in");
ofstream g("petsoft.out");

#define cout g
#define nmax 1010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,i;
int P[nmax],A[2][nmax];
int dp[nmax][nmax],v[nmax];
vector <int> G[nmax];

int best()
    {
    int n=v[0],i,j,k;
    for(i=0;i<=n+1;++i)
        for(j=0;j<=n+1;++j) dp[i][j]=0;
    for(i=1;i<=n;++i) dp[i][i]=max(A[0][v[i]],A[1][v[i]]);
    for(k=2; k<=n; ++k)
        for(i=1; i+k-1<=n; ++i)
            {
            j=i+k-1;
            dp[i][j]=max(dp[i][j],A[0][v[i]]+A[0][v[j]]+v[j]-v[i]+dp[i+1][j-1]);
            dp[i][j]=max(dp[i][j],A[1][v[i]]+dp[i+1][j]);
            dp[i][j]=max(dp[i][j],A[1][v[j]]+dp[i][j-1]);
            }
    if(n<1) return 0;
    return dp[1][n];
    }

void dp_arb(int nod)
    {
        int aux;
    foor(it,G[nod]) dp_arb(*it);
    v[0]=0;
    foor(it,G[nod]) v[++v[0]]=*it;
    A[0][nod]=best();

    v[++v[0]]=nod;
    sort(v+1,v+v[0]+1);
    aux=A[0][nod];
    A[0][nod]=0;
    A[1][nod]=best();
    A[0][nod]=aux;
    }

int main()
    {
    f>>n;
    for(i=2; i<=n; ++i)
        {
        f>>P[i];
        G[P[i]].push_back(i);
        }

    dp_arb(1);
    cout<<A[0][1];
    return 0;
    }
