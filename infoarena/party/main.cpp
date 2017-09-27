#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("party.in");
ofstream g("party.out");

#define cout g

int n,m,i,x,y,z,st,nr;
vector<int> G[210];
int stack[210];
bool X[210],viz[210];

#define X (X+100)
#define viz (viz+100)
#define G (G+100)

void dfs(int nod)
{
    viz[nod]=true;
    for(vector<int>:: iterator it=G[nod].begin();it!=G[nod].end();++it)
        if(! viz[*it]) dfs(*it);

    stack[++st]=nod;
}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>x>>y>>z;
        switch(z)
        {
            case 0:
            {
                 // x || y
                G[-x].push_back(y);
                G[-y].push_back(x);
                break;
            }
            case 1:
            {
                //x || !y
                G[-x].push_back(-y);
                G[y].push_back(x);
                break;
            }
            case 2:
            {
                // !x || y
                G[x].push_back(y);
                G[-y].push_back(-x);
                break;
            }
            case 3:
            {
                // !x || !y
                G[x].push_back(-y);
                G[y].push_back(-x);
                break;
            }
        }
    }

    for(i=-n;i<=n;++i)
        if(!viz[i]) dfs(i);

    for(;st;--st)
    {
        if(!X[stack[st]] && !X[-stack[st]]) X[-stack[st]]=true;
    }

    for(i=1;i<=n;++i)
    {
        if (X[i]) ++nr;
    }
    cout<<nr<<'\n';
    for(i=1;i<=n;++i)
    {
        if (X[i]) cout<<i<<'\n';
    }
    return 0;
}
