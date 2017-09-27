#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("sortaret.in");
ofstream fout("sortaret.out");
/// ////////////////////////////////

#define nmax 50010

vector<int> G[nmax];
int in[nmax],st[nmax];
bool viz[nmax];

void dfs(int nod)
{
    viz[nod]=true;
    for(auto son:G[nod]) if(!viz[son]) dfs(son);
    st[++st[0]]=nod;
}
int main()
{
    int n,m,i,x,y;
    fin>>n>>m;
    for(;m;--m)
    {
        fin>>x>>y;
        G[x].push_back(y);
        ++in[y];
    }

    for(i=1;i<=n;++i)
        if(in[i]==0) dfs(i);

    for(;st[0];--st[0]) cout<<st[st[0]]<<' ';

    return 0;
}
