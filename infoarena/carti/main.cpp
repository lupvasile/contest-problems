#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream f("carti.in");
ofstream g("carti.out");
#define cout g
int c,i,n,k,init;
char s[3];
int dp[1<<13];

int rdp(int stare)
{
    int i,mask,j;
    if(dp[stare]>-1) return dp[stare];
    mask=0;
    dp[stare]=0;
    for(i=0;(1<<i)<=stare;++i)
    {
    mask=stare;
        for(j=i;(j-i+1<=k) && (mask&(1<<j));++j)
        {
            mask=mask-(1<<j);
            dp[stare]|=(rdp(mask)==0);
        }
    }
    return dp[stare];
}

int main()
{
    f>>c;
    for(;c;--c)
    {
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        init=0;
        f>>n>>k;
        for(i=1;i<=n;++i)
        {
            f>>s;
            switch (s[0])
                {
                    case 'A':init|=1;
                                break;
                    case 'J':init|=(1<<10);break;
                    case 'Q':init|=(1<<11);break;
                    case 'K':init|=(1<<12);break;
                    default:init|=(1<<(atoi(s)-1));
                }
        }
        if(rdp(init)) cout<<"Alice\n";
        else cout<<"Bob\n";

    }
    return 0;
}
