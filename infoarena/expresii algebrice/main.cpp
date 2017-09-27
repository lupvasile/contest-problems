#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define cout g
#define inf 2147483647
ifstream f("expresii.in");
ofstream g("expresii.out");

long long t;
char exp[55];
long long dp[52][52],minn,val[52],n,i,j,v[50][50];

void set_val()
    {
    long long t=0;
    for(long long i=0; i<=n; ++i)
        {
        if(exp[i]>='0' && exp[i]<='9')val[i]=inf;
        else if (exp[i]=='(')
            {
            val[i]=inf;
            t+=100;
            }
        else if(exp[i]==')')
            {
            val[i]=inf;
            t-=100;
            }
        else if(exp[i]=='+') val[i]=t+10;
        else val[i]=t+20;
        }
    }
bool valid(long long st,long long d)
    {
    long long ii,nrp=0;
    char s[52];
    strncpy(s,exp+st,d-st+1);
    if(s[0]==')' || s[0]=='+' || s[0]=='*') return false;
    long long n=d-st;
    if(s[0]==')') --nrp;
    if(s[0]=='(') ++nrp;
    if(s[n]=='(' || s[n]=='+' || s[n]=='*') return false;

    for(ii=1; ii<=n; ++ii)
        {
        if(s[ii]=='+' || s[ii]=='*') if(! ( (isdigit(s[ii-1]) || s[ii-1]==')') && (isdigit(s[ii+1]) || s[ii+1]=='('))) return false;
        if(isdigit(s[ii])) if(isdigit(s[ii-1]) || s[ii-1]==')') return false;
        if(s[ii]==')') --nrp;
        if(s[ii]=='(') ++nrp;
        if(nrp<0) return false;
        }
    if(nrp==0) return true;
    else return false;

    }
int main()
    {
    f>>t;
    for(; t; --t)
        {
        f>>exp;
        n=strlen(exp)-1;
        set_val();
        memset(dp,0,sizeof dp);
       for(i=n; i>=0; --i)
            for(j=i; j<=n; ++j)
                {
                if (valid(i,j))
                    {
                    if(exp[i]=='(' && exp[j]==')' && valid(i+1,j-1)) dp[i][j]=dp[i+1][j-1];
                    else
                        {
                        minn=inf;
                        for(long long t=i; t<=j; ++t) minn=min(minn,val[t]);
                        if(minn==inf) dp[i][j]=1;
                        else
                            for(long long t=i; t<=j; ++t) if (val[t]==minn) dp[i][j]+=dp[i][t-1]*dp[t+1][j];
                        }
                    }
                else dp[i][j]=0;
                v[i][j]=valid(i,j);
                }
        cout<<"Numarul de arbori = "<<dp[0][n]<<".\n";
        }
    //cout<<(valid(0,n));
   /* for(i=0;i<=n;++i)
    {
        for(j=0;j<=n;++j) cout<<v[i][j]<<' ';
        cout<<'\n';
    }*/
   // cout<<valid(0,n);
    return 0;
    }
