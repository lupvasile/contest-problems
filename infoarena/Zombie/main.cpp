#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zombie.in");
ofstream fout("zombie.out");

#define nmax 1000010

int dp[nmax],timp[nmax];

int main()
{
    int d,n,k,i,j(1);

    fin>>d>>n>>k;

    for(i=1;i<=n;++i)
    {
        fin>>timp[i];
        for(;timp[j]+d-1<timp[i];++j);
        dp[i]=min(dp[j-1]+k,dp[i-1]+1);
    }
    fout<<dp[n];

    return 0;
}
