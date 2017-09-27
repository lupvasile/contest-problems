#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("crescator2.in");
ofstream fout("crescator2.out");
/// ////////////////////////////////

#define mod 700001
#define smax 50002

int dp1[2][smax],dp2[2][smax];

int main()
{
    int i,s,rad,x1,x2,k,res=0,rem;

    fin>>s;
    for(rad=1;rad*rad<=s;++rad);
    --rad;

    dp1[0][0]=1;
    x1=0;

    for(k=1;k<=rad;++k){
        x1^=1;
        for(i=0;i<=s;++i)
            {
                dp1[x1][i]=dp1[x1^1][i] + (i>=k ? dp1[x1][i-k]:0);
                if(dp1[x1][i]>=mod) dp1[x1][i]-=mod;
            }
    }

    for(i=1;i<=s;++i)
    {
        dp1[x1][i]+=dp1[x1][i-1];
        if(dp1[x1][i]>=mod) dp1[x1][i]-=mod;
    }

    x2=0;
    dp2[0][0]=1;

    res=dp1[x1][s]-1;

    for(k=1;k<=rad;++k)
    {
        x2^=1;
        dp2[x2][0]=0;
        for(i=1;i<=s;++i)
        {
            dp2[x2][i] =(i ? dp2[x2^1][i-1]:0) + (i>=k ? dp2[x2][i-k]:0);
            if(dp2[x2][i]>=mod) dp2[x2][i]-=mod;

            rem = s - i - k*rad;
            if(rem>=0)
                res = (res + 1ll*dp1[x1][rem] * dp2[x2][i]) % mod;
        }
    }

   cout<<res;

    return 0;
}
