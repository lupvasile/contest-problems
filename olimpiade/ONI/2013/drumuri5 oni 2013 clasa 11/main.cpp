#include <bits/stdc++.h>
#include <stack>

using namespace std;

ifstream f("drumuri5.in");
ofstream g("drumuri5.out");

#define nmax 150001
#define cout g

vector <int> G[nmax],G_t[nmax],G_n[nmax],G_n_t[nmax];
vector<bool> viz;
int ctc[nmax];
stack <int> stiva;
int sst[nmax],st,minn,vmin;
int dp[2][nmax],pos[nmax];
int m,n,x,y,nr_ctc,i;

void comp_t_c();
void make_new_graph();
void top_sort();

int main()
{
    f>>n>>m;
    viz.resize(n+1);
    for(;m;--m)
    {
        f>>x>>y;
        G[x].push_back(y);
        G_t[y].push_back(x);
    }

    comp_t_c();
    make_new_graph();
    top_sort();
    for(i=st;i>=1;--i)
    {
        ++dp[0][sst[i]];
        minn=st+2;
        vmin=0;
        for(auto it:G_n[sst[i]])
                if(minn>-pos[it]+pos[sst[i]])
        {
            minn=-pos[it]+pos[sst[i]];
            vmin=it;
        }
        if(vmin) dp[0][vmin]+=dp[0][sst[i]];
    }
    for(i=1;i<=st;++i)
    {
        ++dp[1][sst[i]];
        minn=st+2;
        vmin=0;
        for(auto it:G_n_t[sst[i]])
                if(minn>pos[it]-pos[sst[i]])
        {
            minn=pos[it]-pos[sst[i]];
            vmin=it;
        }
        if(vmin) dp[1][vmin]+=dp[1][sst[i]];
    }
    int nr(0);
    for(i=1;i<=n;++i) if(dp[0][ctc[i]]+dp[1][ctc[i]]==nr_ctc+1) ++nr;
    cout<<nr<<'\n';
    for(i=1;i<=n;++i)if(dp[0][ctc[i]]+dp[1][ctc[i]]==nr_ctc+1)  cout<<i<<' ';
    return 0;
}

void dfs(int nod)
{
    viz[nod]=true;
    for(auto it:G_n[nod]) if(!viz[it]) dfs(it);
    sst[++st]=nod;
    pos[nod]=st;
}

void top_sort()
{
    int i;
    viz.assign(nr_ctc+1,0);
    for(i=1;i<=nr_ctc;++i) if(!viz[i]) dfs(i);
}
void dfs_n(int nod)
{
    viz[nod]=true;
    for(auto it:G[nod])
    {
        if(ctc[nod]!=ctc[it]) G_n[ctc[nod]].push_back(ctc[it]),G_n_t[ctc[it]].push_back(ctc[nod]);
        if(!viz[it]) dfs_n(it);
    }
}

void make_new_graph()
{
    int i;
    viz.assign(n+1,0);
    for(i=1;i<=n;++i) if(!viz[i]) dfs_n(i);
}

void dfs_ctc(int nod)
{
    viz[nod]=true;
    for(auto it : G[nod])
            if(!viz[it]) dfs_ctc(it);
    stiva.push(nod);
}
void dfs_t_ctc(int nod)
{
    viz[nod]=true;
    ctc[nod]=nr_ctc;
    for(auto it:G_t[nod]) if(!viz[it]) dfs_t_ctc(it);
}
void comp_t_c()
{
    int i;
    for(i=1;i<=n;++i) if(!viz[i]) dfs_ctc(i);
    viz.assign(n+1,0);
    for(;!stiva.empty();stiva.pop())
        if(!viz[stiva.top()])
    {
        ++nr_ctc;
        dfs_t_ctc(stiva.top());
    }
}
