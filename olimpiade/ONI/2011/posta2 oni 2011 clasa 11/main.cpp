#include <bits/stdc++.h>

using namespace std;

ifstream f("posta2.in");
ofstream g("posta2.out");

#define cout g
#define nmax 100001

int n,m,x,y,z,i;
bool spec[nmax],viz[nmax];
struct eee
    {
    int nod,cost;
    };
vector<eee> G[nmax];
int tax[nmax],nr_dir[nmax],from;
long long drum_tot,tax_tot,sol;

void read();

bool dfs(int nod)//true daca merita pastrat subarborele
    {
    viz[nod]=true;
    for(auto son:G[nod])
        if(!viz[son.nod])
            {
            if(!dfs(son.nod)) continue;
            drum_tot+=2*son.cost;
            ++nr_dir[nod];
            }
    if(spec[nod] || nr_dir[nod]) return true;
    return false;
    }

int main()
    {
    read();
    if(m==0)
        {
        cout<<"0";
        return 0;
        }

    dfs(from);
    --nr_dir[from];
    for(i=1;i<=n;++i) tax_tot+=1ll*nr_dir[i]*tax[i];
    sol=(1ll<<62);
    for(i=1;i<=n;++i) sol=min(sol,tax_tot+drum_tot-1ll*tax[i]*nr_dir[i]);
    cout<<sol;
    return 0;
    }

void read()
    {
    f>>n>>m;
    for(i=1; i<n; ++i)
        {
        f>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
        }
    for(i=1; i<=n; ++i) f>>tax[i];
    for(i=0; i<m; ++i)
        {
        f>>x;
        from=x;
        spec[x]=true;
        }
    }
