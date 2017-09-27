#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("bfs.in");
ofstream g("bfs.out");
#define cout g
int n,m,s,dist[100001],nod,i,x,y;
queue <int> q;
vector <int> v[100001];
vector <int>::iterator it;
int main()
{
    f>>n>>m>>s;
    for(;m;--m)
    {
        f>>x>>y;
        v[x].push_back(y);
    }
    q.push(s);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(it=v[nod].begin();it!=v[nod].end();++it)
            if(dist[*it]==0 && *it!=s)
        {
            q.push(*it);
            dist[*it]=dist[nod]+1;
        }
    }
    for(i=1;i<=n;++i) if(dist[i]==0 && i!=s) cout<<"-1 ";
    else cout<<dist[i]<<" ";
    return 0;
}
