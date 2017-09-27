#include <bits/stdc++.h>

using namespace std;

ifstream f("lant.in");
ofstream g("lant.out");

#define cout g
#define delim " ,:;.!?-"

int k,n,i,j;
char s[1010],cuv[152][31],*p;
int dp[152];

int similit(char *c1,char *c2)
{
    int n=strlen(c1),m=strlen(c2);
    int dp[n+2][m+2];
    int i,j;
    for(j=0;j<=m;++j) dp[n][j]=m-j;
    for(i=0;i<=n;++i) dp[i][m]=n-i;

    for(i=n-1;i>=0;--i)
        for(j=m-1;j>=0;--j)
    {
        dp[i][j]=min(1+dp[i][j+1],1+dp[i+1][j]);
        if(c1[i]==c2[j]) dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
    }

    return dp[0][0];
}

int main()
{
    f>>k;
    while(f>>s)
    {
        p=strtok(s,delim);
        while(p!=NULL)
        {
            for(i=1;i<=n;++i) if(strcmp(p,cuv[i])==0) goto asdf;
            ++n;
            strcpy(cuv[n],p);
            asdf:;
            p=strtok(NULL,delim);
        }
    }
    dp[n]=1;
    for(i=n-1;i>0;--i)
    {
        for(j=i+1;j<=n;++j) if(similit(cuv[i],cuv[j])<=k) dp[i]+=dp[j];
        if(dp[i]==0) ++dp[i];
    }
   cout<<dp[1];
    return 0;
}
