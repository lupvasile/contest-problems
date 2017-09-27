#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("telecomanda.in");
ofstream g("telecomanda.out");

#define cout g
#define nmax 101

int n,m,i,j,k,u,res;
int dp[nmax][nmax];
char n1[nmax],n2[nmax];
struct eee
    {
    char x,y,tip;
    } P[nmax][nmax],pres;
///1 =, 2 +-, 3 /, 4 *

void afis(int x,int y)
    {
    if(x==0)
        {
        for(int k=1; k<=y; ++k)  cout<<"*"<<n2[k]-'0';
        return;
        }

    if(P[x][y].x+P[x][y].y>0) afis(P[x][y].x,P[x][y].y);
    if(P[x][y].tip==1) cout<<"=";
    else if(P[x][y].tip==2)
        if(n1[x]>n2[y]) cout<<"-"<<n1[x]-n2[y];
        else cout<<"+"<<n2[y]-n1[x];
    else if(P[x][y].tip==3) cout<<"/";
    else
        {
        for(int k=P[x][y].y+1; k<y; ++k) cout<<"*"<<n2[k]-'0';
        if(n1[x]==n2[y]) cout<<"=";
        else if(n1[x]>n2[y]) cout<<"-"<<n1[x]-n2[y];
        else cout<<"+"<<n2[y]-n1[x];
        }
    }

int main()
    {
    f>>(n1+1)>>(n2+1);
    n=strlen(n1+1);
    m=strlen(n2+1);
    for(j=0; j<=m; ++j) dp[0][j]=2*j,P[0][j]= {0,0,4};
    for(i=1; i<=n; ++i) dp[i][0]=i,P[i][0]= {i-1,0,3};
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            if(n1[i]==n2[j]) u=1;
            else u=2;
            dp[i][j]=dp[i-1][j-1]+u;
            P[i][j]= {i-1,j-1,u};
            if(dp[i][j]>dp[i-1][j]+1)
                {
                dp[i][j]=dp[i-1][j]+1;
                P[i][j]= {i-1,j,3};
                }
            for(k=0; k<j; ++k) if(dp[i][j]>dp[i-1][k]+u+2*(j-k-1))
                    {
                    dp[i][j]=dp[i-1][k]+u+2*(j-k-1);
                    P[i][j]= {i-1,k,4};
                    }
            }
    pres= {n,m};
    res=dp[n][m];
    for(i=n-1; i>=0; --i) if(res>dp[i][m]+1)
            {
            res=dp[i][m]+1;
            pres= {i,m};
            }
    cout<<res<<'\n';
    afis(pres.x,pres.y);
    if(pres.x!=n && pres.y<=m) cout<<"#";
    return 0;
    }
