#include <iostream>
#include <fstream>

using namespace std;

ifstream f("playlist.in");
ofstream g("playlist.out");

#define cout g


int n,m,a,b,i;
bool over[15][15],ok,on[15];
int sol[15];

void bback(int level)
{
    int i;
    if(ok) return;
    if(level==n+1)
    {
        for(i=1;i<=n;++i) cout<<sol[i]<<' ';
    ok=true;
    return;
    }
    for(i=1;i<=n;++i) if(!on[i] && !over[i][sol[level-1]])
    {
        on[i]=1;
        sol[level]=i;
        bback(level+1);
        on[i]=0;
    }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>a>>b;
        over[a][b]=over[b][a]=true;
    }
    bback(1);
    return 0;
}
