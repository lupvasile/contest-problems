#include <bits/stdc++.h>
#include <thread>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("dragoni.in");
ofstream fout("dragoni.out");
/// ////////////////////////////////

void read();

#define nmax 810
#define inf 0x3f3f3f3f

struct eee
{
    int id,c;
};
vector<eee> G[nmax];
int n,d[nmax],tip,dist[nmax][nmax];
bool viz[nmax];
thread::thread th;
struct eqq
{
    int nod,dr,c;
    bool operator < (const eqq &o) const
    {
        return c>o.c;
    }
};
priority_queue<eqq> q;

int dfs(int nod)
{
    int maxx=d[nod];
    viz[nod]=1;
    for(auto son:G[nod])
        if(!viz[son.id] && son.c<=d[1])
            maxx=max(maxx,dfs(son.id));
    return maxx;
}

int dijkstra()
{
    memset(dist,inf,sizeof dist);
    dist[1][1]=0;
    q.push({1,1,0});
    eqq tp;

    while(!q.empty())
    {
        tp=q.top();
        q.pop();
        if(tp.nod==n) return tp.c;
        for(auto son:G[tp.nod])
            if(tp.c+son.c<dist[son.id][tp.dr] && son.c<=d[tp.dr])
            {
                dist[son.id][tp.dr]=tp.c+son.c;
                q.push({son.id,tp.dr,dist[son.id][tp.dr]});
                if(dist[son.id][tp.dr]<dist[son.id][son.id])
                {
                   dist[son.id][son.id]=dist[son.id][tp.dr];
                   q.push({son.id,son.id,dist[son.id][son.id]});
                }
            }
    }

}


int main()
{
    read();
    if(tip==1)
        cout<<dfs(1);
        else cout<<dijkstra();
    return 0;
}

void read()
{
    int i,m,x,y,c;
    fin>>tip>>n>>m;
    for(i=1; i<=n; ++i) fin>>d[i];
    for(; m; --m)
    {
        fin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
}
