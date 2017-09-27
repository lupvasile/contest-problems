#include <iostream>

using namespace std;

#define nmax 510
#define x first
#define y second
#define mp make_pair

int n,m,k,i,j,s;
int depl[4][2]= { {-1,0},{0,1},{1,0},{0,-1} };
char c;
bool a[nmax][nmax];//0 pt zid 1 pt liber
int b[nmax][nmax];//2 pt celula transformata

void dfs(int x,int y)
    {
    int nx,ny;
    a[x][y]=0;
    --k;
    if(k<0) b[x][y]=2;
    for(int i=0; i<=3; ++i)
        {
        nx=x+depl[i][0];
        ny=y+depl[i][1];
        if(a[nx][ny]) dfs(nx,ny);
        }
    }

int main()
    {
    cin>>n>>m>>k;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            cin>>c;
            if(c=='.') b[i][j]=a[i][j]=1,++s;
            }
    k=s-k;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j) if(a[i][j])
                {
                dfs(i,j);
                }
    for(i=1; i<=n; ++i)
        {
        for(j=1; j<=m; ++j) if(b[i][j]==0) cout<<'#';
            else if (b[i][j]==1) cout<<'.';
            else cout<<'X';
        cout<<'\n';
        }

    return 0;
    }
