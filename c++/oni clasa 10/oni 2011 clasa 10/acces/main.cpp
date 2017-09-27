#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream f("acces.in");
ofstream g("acces.out");

#define cout g

int i,j,m,n,x,y,q;
int a[1010][1010],s[1010][1010];

int main()
{
    f>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j) f>>a[i][j];
    for(i=1; i<=n; ++i) if(a[i][1]==0) s[i][1]=1+s[i-1][1];
    for(j=1; j<=m; ++j) if(a[1][j]==0) s[1][j]=1+s[1][j-1];
    for(i=2; i<=n; ++i)
        for(j=2; j<=m; ++j)
            if(a[i][j]==1)
            {
              if(a[i][j-1]==1) s[i][j]=s[i][j-1];
              else if(a[i-1][j]==1) s[i][j]=s[i-1][j];
              else s[i][j]=s[i-1][j-1];
            }

            else
            {
                s[i][j]=1;
                if(a[i-1][j]==0) s[i][j]+=s[i-1][j];
                if(a[i][j-1]==0) s[i][j]+=s[i][j-1];
                if(a[i-1][j]==0 && a[i][j-1]==0) s[i][j]-=s[i-1][j-1];
            }
            f>>q;
            for(;q;--q)
            {
                f>>x>>y;
                cout<<s[x][y]<<'\n';
            }
            /*
            for(i=1; i<=n; ++i)
            {
                for(j=1; j<=m; ++j) cout<<setw(4)<<s[i][j];
                cout<<'\n';
            }
            */
    return 0;
}
