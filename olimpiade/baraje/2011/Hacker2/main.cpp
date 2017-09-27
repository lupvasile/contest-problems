#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("hacker2.in");
ofstream fout("hacker2.out");
/// ////////////////////////////////

void read();
void calc_dad();
void solve_query();

#define nmax 100010
#define logmax 18
struct eee
{
    int nod,cost;
};

vector<eee> G[nmax];
int n,m;
int dad[logmax][nmax],d[nmax],lev[nmax];
eee max_down[nmax],max_up[nmax];

void dfs_1(int nod,int tata)
{
    dad[0][nod]=tata;
    lev[nod]=1+lev[tata];
    max_down[nod]= {nod,0};

    for(auto son:G[nod])
    {
        if(son.nod==tata) continue;

        d[son.nod]=d[nod]+son.cost;
        dfs_1(son.nod,nod);

        if(son.cost+max_down[son.nod].cost>max_down[nod].cost)
            max_down[nod]= {max_down[son.nod].nod, son.cost + max_down[son.nod].cost};
    }
}

void dfs_2(int nod,int tata)
{
    eee best_1={0,0},best_2={0,0};

    for(auto son:G[nod])
    {
        if(son.nod==tata) continue;

        if(son.cost+max_down[son.nod].cost > best_1.cost)
        {
            best_2=best_1;
            best_1= {max_down[son.nod].nod, son.cost+max_down[son.nod].cost};
        }
        else if(son.cost+max_down[son.nod].cost > best_2.cost)
            best_2= {max_down[son.nod].nod, son.cost+max_down[son.nod].cost};

        max_up[son.nod]= {max_up[nod].nod, max_up[nod].cost + son.cost};
    }

    for(auto son:G[nod])
    {
        if(son.nod==tata) continue;

        if(max_down[son.nod].nod==best_1.nod)
        {
            if(max_up[son.nod].cost < best_2.cost + son.cost)
                max_up[son.nod]= {best_2.nod, best_2.cost + son.cost};
        }
        else
        {
            if(max_up[son.nod].cost < best_1.cost + son.cost)
                max_up[son.nod]= {best_1.nod, best_1.cost + son.cost};
        }

        dfs_2(son.nod,nod);
    }


}

void cauta(int nod,int dist)
{
    int step;
    for(step=1; (1<<step)<=lev[nod]; ++step);
    for(; step>=0; --step)
        if(dad[step][nod]>1)
            if(d[nod]-d[dad[step][nod]]<=dist)
            {
                dist-=d[nod]-d[dad[step][nod]];
                nod=dad[step][nod];
            }

    cout<<nod<<' '<<dad[0][nod]<<' '<<dist<<'\n';
}

int lca(int x,int y)
{
    if(lev[x]<lev[y]) swap(x,y);

    int diff=lev[x]-lev[y];
    for(int k=0;(1<<k)<=diff;++k)
        if(diff&(1<<k)) x=dad[k][x];

    if(x==y) return x;

    int step;
    for(step=0;dad[step][x];++step);
    for(;step>=0;--step)
        if(dad[step][x]!=dad[step][y])
            x=dad[step][x],y=dad[step][y];

    return dad[0][x];
}

int main()
{
    read();
    dfs_1(1,0);
    calc_dad();
    max_up[1]= {1,0};
    dfs_2(1,0);
    solve_query();
    return 0;
}

void read()
{
    int i=0,x,y,c;
    fin>>n>>m;
    for(i=1; i<n; ++i)
    {
        fin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
}

void solve_query()
{
    int x,dist,y,lc;
    for(; m; --m)
    {
        fin>>x>>dist;

        y = max_up[x].cost>max_down[x].cost ? max_up[x].nod:max_down[x].nod;
        lc = lca(x,y);

        if(d[x]-d[lc]>=dist) cauta(x,dist);
        else cauta(y,d[x]-d[lc] + d[y]-d[lc] - dist);

    }
}

void calc_dad()
{
    int kmax,k,i;
    for(kmax=0;(1<<kmax)<n;++kmax);

    for(k=1;k<=kmax;++k)
        for(i=1;i<=n;++i)
            dad[k][i]=dad[k-1][dad[k-1][i]];
}
