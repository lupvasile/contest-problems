#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("nebuni.in");
ofstream fout("nebuni.out");

#define cout fout
#define nmax 1000010

bool off_dp[nmax*2],off_ds[nmax*2];
int mars[2][nmax*2];//0 pentru par,1 pentru impar
pair<int,int> b[16502];//nebunii
long long res,n,m,q,w;

#define off_dp (off_dp+nmax)
#define x first
#define y second
#define mars(x,y) mars[x][y+nmax]

int main()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
        fin>>b[i].x>>b[i].y;

    for(i=1; i<=m; ++i)
    {
        if(!off_ds[b[i].x+b[i].y])
        {
            q=b[i].x;w=b[i].y;
            res+=n-abs(n+1-b[i].x-b[i].y);

            if(q+w>n+1)
            {
                w=n+1-b[i].x;
                q=b[i].x-b[i].y+w;
            }

            mars((b[i].x+b[i].y)&1,1-(q+w-1))+=1;
            mars((b[i].x+b[i].y)&1,q+w-1-1+1)-=1;
            off_ds[b[i].x+b[i].y]=true;

           // cerr<<b[i].x<<' '<<b[i].y<<' '<<1-(q+w-1)<<' '<<q+w-1-1+1<<'\n';
        }
    }

    for(i=-n;i<=n;++i)
    {
        mars(0,i)+=mars(0,i-1);
        mars(1,i)+=mars(1,i-1);
    }

    for(i=1;i<=m;++i)
    {
        if(!off_dp[b[i].x-b[i].y])
        {
            res+=n-abs(b[i].x-b[i].y)-mars((b[i].x+b[i].y)&1,b[i].x-b[i].y);
            off_dp[b[i].x-b[i].y]=true;
            //cerr<<b[i].x<<' '<<b[i].y<<' '<<res<<' '<<mars((b[i].x+b[i].y)&1,b[i].x-b[i].y);
            //cerr<<'\n';
        }
    }

    cout<<n*n-res;
    return 0;
}
