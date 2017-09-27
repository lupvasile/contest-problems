#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

vector <int> v[100002];
bool viz[100002];

int n,m,x,y,nr;
void dfs(int nod)
{vector <int>::iterator it;
    viz[nod]=1;
    if(v[nod].size())
    for(it=v[nod].begin();it!=v[nod].end();++it) if (!viz[*it]) dfs(*it);
}
int main()
{
f>>n>>m;
for(;m;--m)
{
    f>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
for(;n;--n)
{
    if (!viz[n]) ++nr,dfs(n);
}
g<<nr;

    return 0;
}
