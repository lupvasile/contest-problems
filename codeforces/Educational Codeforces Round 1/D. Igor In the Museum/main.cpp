#include <iostream>
#include <vector>

using namespace std;

#define nmax 1010

char s[nmax][nmax];
int nr,n,m,a[nmax][nmax];
vector<int> res;
struct eee{int x,y;};
int depl[4][2]={ {-1,0},{0,1},{1,0},{0,-1} };
#define on_map(x,y) x>0 && x<=n && y>0 && y<=m

void ffill(int x,int y)
{
    if(s[x][y]=='*')
    {
        ++res[nr];
        return;
    }

    a[x][y]=nr;
    for(int i=0;i<4;++i)
        if(on_map(x+depl[i][0],y+depl[i][1]) && a[x+depl[i][0]][y+depl[i][1]]==0)
            ffill(x+depl[i][0],y+depl[i][1]);
}

int main()
{
    int i,j,q;
    cin>>n>>m>>q;
    for(i=1;i<=n;++i)
        cin>>s[i]+1;

    res.push_back(0);

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        if(s[i][j]=='.' && a[i][j]==0)
    {
        ++nr;
        res.push_back(0);
        ffill(i,j);
    }

    for(;q;--q)
    {
        cin>>i>>j;
        cout<<res[a[i][j]]<<'\n';
    }

    return 0;
}
