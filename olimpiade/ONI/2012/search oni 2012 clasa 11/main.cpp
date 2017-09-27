#include <bits/stdc++.h>
using namespace std;

ifstream f("search.in");
ofstream g("search.out");

#define cout g
#define nmax 102
#define lmax 5002

char cuv[lmax],c;
int lit[nmax][26][lmax];
int n,m,i,j,nr,l;
vector<pair<int,int>> with[nmax];

inline int ccount()
    {
    int r=0;
    for(int i=1; i<=n; ++i) if(nr==with[i].back().second) ++r;
    return r;
    }

void rremove()
    {
    for(int i=1; i<=n; ++i) if(with[i].back().second==nr) with[i].pop_back();
    --nr;
    }

int add(int c)
    {
    int p,p1,val,step;
    ++nr;
    for(int i=1; i<=n; ++i) if(nr-1==with[i].back().second)
            {
            val=with[i].back().first;
            p=lit[i][c][val+1];
            if(p<0) continue;
            with[i].push_back({p,nr});
            }
    }

int main()
    {
    f>>n>>m;
    memset(lit,-1,sizeof lit);
    for(i=1; i<=n; ++i)
        {
        f>>cuv;
        for(j=0; cuv[j]; ++j) lit[i][cuv[j]-'a'][j]=j;
        with[i].push_back({-1,0});
        for(--j;j>=0;--j) for(l=0;l<26;++l)if(lit[i][l][j]==-1) lit[i][l][j]=lit[i][l][j+1];
        }
    for(; m; --m)
        {
        f>>c;
        if(c=='-') rremove();
        else add(c-'a');
        cout<<ccount()<<'\n';
        }
    return 0;
    }
