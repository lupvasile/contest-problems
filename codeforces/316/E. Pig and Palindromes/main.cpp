#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define cin fin
ifstream fin("date.in");
#endif // ONLINE_JUDGE

#define MOD 1000000007
#define nmax 200

int n,m,dp[nmax][nmax][nmax],rez;
char a[nmax][nmax];
bitset<nmax> viz[nmax][nmax];
int depl[4][4]= { {0,1,0,-1},{0,1,-1,0},{1,0,0,-1},{1,0,-1,0} };
struct eee
{
    short int x1,y1,x2;
};

queue<eee> Q;

int main()
{
    int i,j,x1,x2,y1,y2,nx1,nx2,ny1,ny2,k;

    cin>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>(a[i]+1);

    if(a[1][1]!=a[n][m])
    {
        cout<<0;
        return 0;
    }

    dp[1][1][n]=1;

    Q.push({1,1,n});

    while(!Q.empty())
    {
        x1=Q.front().x1;
        y1=Q.front().y1;
        x2=Q.front().x2;
        Q.pop();
        y2=n+m-x1-y1-x2+2;

        if(viz[x1][y1][x2]) continue;

        viz[x1][y1][x2]=true;

        if(x1==x2 && y1==y2 || x1==x2 && y1+1==y2 || y1==y2 && x1+1==x2)
        {
            rez=rez+dp[x1][y1][x2];
        }
        else

            for(k=0; k<4; ++k)
            {
                nx1=x1+depl[k][0];
                ny1=y1+depl[k][1];
                nx2=x2+depl[k][2];
                ny2=y2+depl[k][3];

                if(nx1>nx2 || ny1>ny2) continue;
                if(a[nx1][ny1]!=a[nx2][ny2]) continue;

                dp[nx1][ny1][nx2]+=dp[x1][y1][x2];

                Q.push({nx1,ny1,nx2});
            }


    }

    cout<<rez;
    return 0;
}
