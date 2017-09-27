#include <bits/stdc++.h>

using namespace std;

ifstream f("minerale.in");
ofstream g("minerale.out");
//#define cout g

int dp[101][101],st1[30],st2[30];
char c1,c2,c3;
vector<char> from[26],fromB[700];
int r,i,k,m,n;
string s;
bool ok;
int sol(int i,int k,int j);
void init()
    {
    int i,j;
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j) dp[i][j]=0;
    }

void build_dp()
    {
    int i,j,k,x,y;

    for(i=0; i<n; ++i)
        for(auto it:from[s[i]-'a'])
            dp[i][i]|=(1<<it);

    for(k=2; k<=n; ++k)
        for(i=0; i+k<=n; ++i)
            for(j=i; j<i+k-1; ++j)
                dp[i][i+k-1]|=sol(i,j,i+k-1);
    }

int sol(int i,int k,int j)
{
    int x,y,res(0);
    st1[0]=0;st2[0]=0;
    for(x=0; (1<<x)<=dp[i][k]; ++x) if((1<<x)&dp[i][k]) st1[++st1[0]]=x;
    for(y=0; (1<<y)<=dp[k+1][j]; ++y) if((1<<y)&dp[k+1][j]) st2[++st2[0]]=y;
    for(x=1;x<=st1[0];++x)
        for(y=1;y<=st2[0];++y)
            for(auto it:fromB[st1[x]*26+st2[y]])
                res|=(1<<it);
    return res;
}

int main()
    {
    f>>r>>m;
    for(; r; --r)
        {
        f>>c1>>c2;
        if(islower(c2)) from[c2-'a'].push_back(c1-'A');
        else
            {
            f>>c3;
            fromB[(c2-'A')*26+c3-'A'].push_back(c1-'A');
            }
        }

    for(; m; --m)
        {
        f>>s;
        n=s.length();
        init();
        build_dp();
        if(dp[0][n-1]&(1<<('S'-'A'))) cout<<"1\n";
        else
            {
            if(dp[0][n-1]) cout<<"2\n";
            else cout<<"0\n";
            }
        }
    return 0;
    }
