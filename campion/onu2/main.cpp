#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream f("onu2.in");
ofstream g("onu2.out");

#define nmax 110
#define foor(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define cout g

int n,k,i,j,h,sol[nmax][nmax],nrg;
string cod[nmax];
int p[nmax],best[nmax];
bool del[nmax];
vector <int> G[nmax];

bool compatible(string a,string b)
    {
    return a.substr(a.size()-k)==b.substr(0,k);
    }

int dfs(int nod)
{
    int nr(0);
    foor(it,G[nod]) nr=max(nr,dfs(*it));
    return nr+1;
}

bool dfs_2(int nod,int level)
{
    if(level==h)
    {
        del[nod]=1;
        sol[nrg][++sol[nrg][0]]=nod;
        return 1;
    }
    foor(it,G[nod]) if(!del[*it])if(dfs_2(*it,level+1))
    {
        del[nod]=1;
        sol[nrg][++sol[nrg][0]]=nod;
        return 1;
    }
    return 0;
}

int main()
    {

//   freopen("onu2.in","r",stdin);
    //freopen("onu2.out","w",stdout);

    f>>n>>k;
    for(i=1; i<=n; ++i)
    {
        f>>cod[i];
        for(j=1;j<i;++j)
            if(compatible(cod[j],cod[i])) G[j].push_back(i);
    }

    for(i=1;i<=n;++i) if(best[i]==0) h=max(h,dfs(i));
    for(i=1;i<=n;++i) if(!del[i])
    {   sol[nrg][0]=0;
        if(dfs_2(i,1))
        {
            ++nrg;
        }
    }
    cout<<nrg<<'\n';
    for(i=0;i<nrg;++i)
    {
       for(;sol[i][0];--sol[i][0]) cout<<sol[i][sol[i][0]]<<' ';
       cout<<'\n';
    }
    return 0;
    }
