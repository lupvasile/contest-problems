#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("ctc.in");
ofstream fout("ctc.out");
/// ////////////////////////////////

void read();

#define nmax 100010
#define VI vector<int>

VI G[nmax],G_t[nmax],st;
vector<VI> ctc;
bool viz[nmax];
int n;

void dfs(int nod)
{
    viz[nod]=1;
    for(auto son:G[nod])
        if(!viz[son]) dfs(son);

    st.push_back(nod);
}

void dfs_t(int nod)
{
    viz[nod]=true;
    ctc.back().push_back(nod);
    for(auto son:G_t[nod])
        if(!viz[son]) dfs_t(son);
}

int main()
{
    int i;
    read();

    for(i=1; i<=n; ++i)
        if(!viz[i]) dfs(i);

    memset(viz,0,sizeof viz);

    for(i=st.size()-1; i>=0; --i)
        if(!viz[st[i]])
        {
            ctc.push_back(VI());
            dfs_t(st[i]);
        }

    cout<<ctc.size()<<'\n';
    for(auto it:ctc)
    {
        for(auto itt:it)
            cout<<itt<<' ';
        cout<<'\n';
    }
    return 0;
}

void read()
{
    int m,x,y;
    fin>>n>>m;
    for(; m; --m)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G_t[y].push_back(x);
    }
}
