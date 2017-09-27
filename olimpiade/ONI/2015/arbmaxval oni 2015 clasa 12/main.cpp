#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("arbvalmax.in");
ofstream fout("arbvalmax.out");

#define nmax 300010

typedef vector<int>::iterator iter;
typedef vector<int>::reverse_iterator riter;

vector<int> G[nmax];

int n,m,maxx;
int val[nmax],dad[nmax],max_path[nmax],max_no_path[nmax];

void citire();

void dfs(int nod)
{
    max_path[nod]=max(max_path[dad[nod]],val[dad[nod]]);

    for(iter it=G[nod].begin();it!=G[nod].end();++it) dfs(*it);

    max_no_path[nod]=max(max_no_path[nod],maxx);
    maxx=max(maxx,val[nod]);
}

void dfs_2(int nod)
{
    for(riter it=G[nod].rbegin();it!=G[nod].rend();++it) dfs_2(*it);

    max_no_path[nod]=max(max_no_path[nod],maxx);
    maxx=max(maxx,val[nod]);
}

int main()
{
    int x,y;
    citire();
    dfs(1);
    maxx=0;
    dfs_2(1);

    for(;m;--m)
    {
        fin>>x>>y;
        cout<<max(max_path[x],max_no_path[y])<<'\n';
    }

    return 0;
}
void citire()
{
    int x,i;
    fin>>n>>m;
    for(i=2;i<=n;++i)
    {
        fin>>x;
        dad[i]=x;
        G[x].push_back(i);
    }
    for(i=1;i<=n;++i) fin>>val[i];
}
