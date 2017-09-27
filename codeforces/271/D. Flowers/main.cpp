#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
//#define cin f

#define nmax 100010
#define mod 1000000007

int dp[nmax];
int t,k,i,a,b;


int main()
{
   cin>>t>>k;
   dp[k]=1;
   for(i=1;i<nmax-2;++i)
   {
       if(i>k) dp[i]=(dp[i-1]+dp[i-k])%mod;
       else ++dp[i];
   }
   for(i=1;i<nmax;++i) dp[i]=(dp[i]+dp[i-1])%mod;
   for(;t;--t)
   {
      cin>>a>>b;
      b=dp[b];
      a=dp[a-1];
       if(b-a<0) cout<<b-a+mod<<'\n';
       else cout<<b-a<<'\n';
   }
    return 0;
}
