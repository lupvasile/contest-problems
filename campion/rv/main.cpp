#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("rv.in");
ofstream fout("rv.out");

#define cout fout
#define nmax 101

string s,dp[nmax][nmax];
int n;

int main()
{
    int i,sz;
    fin>>s;
    n=s.length();

    for(i=0;i<n;++i) dp[i][i]=s[i];

    for(sz=2;sz<=n;++sz)
        for(i=0;i<n;++i)
            if((n-sz)&1)
                {
                    ///mai mic lexicografic
                    if(i+sz>n) break;
                    dp[i][i+sz-1]=min(s[i]+dp[i+1][i+sz-1],s[i+sz-1]+dp[i][i+sz-2]);
                }
            else
            {
                ///mai mare lexicografic
                if(i+sz>n) break;
                dp[i][i+sz-1]=max(s[i]+dp[i+1][i+sz-1],s[i+sz-1]+dp[i][i+sz-2]);
            }

    cout<<dp[0][n-1];

    return 0;
}
