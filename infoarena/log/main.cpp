#include <iostream>
#include <fstream>

using namespace std;

ifstream f("log.in");
ofstream g("log.out");

#define cout g
#define nmax 10010

int n,c_prod,c_red,c_calc,i,j;
int baza[nmax],arg[nmax],dp[nmax];

int main()
{
    f>>n>>c_prod>>c_red>>c_calc;
    for(i=1;i<=n;++i)
    {
        f>>baza[i]>>arg[i];
        dp[i]=c_calc*(baza[i]-arg[i])*(baza[i]-arg[i])+dp[i-1];
        if(i>1) dp[i]+=c_prod;
        for(j=i-1;arg[j]==baza[j+1] && j>0;--j)
        {
            if(j>1) dp[i]=min(dp[i],c_red*(i-j)+c_calc*(baza[j]-arg[i])*(baza[j]-arg[i])+c_prod+dp[j-1]);
            else   dp[i]=min(dp[i],c_red*(i-j)+c_calc*(baza[j]-arg[i])*(baza[j]-arg[i]));
        }
    }
    cout<<dp[n];
    return 0;
}
