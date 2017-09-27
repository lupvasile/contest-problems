#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/// ////////////////////////////////

#define nmax 2010
int fr[nmax];
pair<int,int> pprev[nmax][320];
double dp[nmax][320],llg[320],add;
int primes[320],nr;
bool prim[nmax];
vector<int> v;

void movee(int &x,int &y, const pair<int,int> &p)
{
    x=p.first;
    y=p.second;
}

int main()
{
    freopen ("perm5.in","r",stdin);
    freopen ("perm5.out","w",stdout);
    int i,j,n,k,pmax;
    scanf("%d",&n);
    primes[nr++]=1;
    llg[0]=log(1);

    for(i=2;i<=n;++i)
        if(!prim[i]){
            for(j=i*i;j<=n;j+=i) prim[j]=true;
            llg[nr]=log(i);
            primes[nr++]=i;

        }

    //for(j=0;j<primes.size();++j) dp[1][j]=;

    for(i=1; i<=n; ++i)
    {
        for(j=1; j<nr; ++j)
        {
            for(k=1,add=0; k<=i; k*=primes[j],add+=llg[j])
                if(dp[i-k][j-1]+add>dp[i][j])
                {
                    dp[i][j]=dp[i-k][j-1]+add;
                    pprev[i][j]= {i-k,j-1};
                }

            if(dp[i][j-1]>dp[i][j])
            {
                dp[i][j]=dp[i][j-1];
                pprev[i][j]=pprev[i][j-1];
            }

            if(dp[i-1][j]>dp[i][j])
            {
                dp[i][j]=dp[i-1][j];
                pprev[i][j]=pprev[i-1][j];
            }

        }
    }
    for(int x=n,y=nr-1; x; movee(x,y,pprev[x][y]) ) v.emplace_back(x-pprev[x][y].first);
    int start=1;
    sort(v.begin(),v.end());
    for(auto i:v)
        {
            for(j=start+1; j-start<i; ++j) printf("%d ",j);
            printf("%d ",start);
            start+=i;
        }
    return 0;
}
