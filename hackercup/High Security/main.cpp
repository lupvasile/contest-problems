#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define nmax 2000

int n,T;
int res;
char v[2][nmax];

void read_data()
{
    int i;
    res=0;
    fin>>n;
    fin>>v[0]+1;
    fin>>v[1]+1;
    v[0][0]=v[1][0]=v[0][n+1]=v[1][n+1]='X';
}

void filll(int i,int k)
{
    int j;
    for(j=k;v[i][j]=='.';--j) v[i][j]='X';
    for(j=k+1;v[i][j]=='.';++j) v[i][j]='X';
}

void solve()
{
    int i,j;
    for(i=0; i<=1; ++i)
        for(j=1; j<=n; ++j)
            if(v[i][j]=='.')
                if(v[i][j-1]=='X' && v[i][j+1]=='X')
                {
                    if(v[i^1][j]=='.') filll(i^1,j);
                    ++res;
                    v[i][j]='X';
                }

    for(i=0;i<=1;++i)
        for(j=1;j<=n+1;++j)
        if(v[i][j-1]=='.' && v[i][j]=='X') ++res;
}

int main()
{
    int t;
    fin>>T;

    for(t=1; t<=T; ++t)
    {
        read_data();
        solve();
        fout<<"Case #"<<t<<": "<<res<<'\n';
    }

    return 0;
}
