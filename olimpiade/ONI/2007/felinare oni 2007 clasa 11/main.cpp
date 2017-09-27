#include <bits/stdc++.h>

using namespace std;

ifstream f("felinare.in");
ofstream g("felinare.out");

#define nmax 9000
#define cout g
int n,m,x,y,i,nr_s;
bool ok,viz[nmax],in_s[2*nmax];
vector <int> G[nmax];
int r[nmax],l[nmax];

bool pairup(int nod)
{
    if(viz[nod]) return false;
    viz[nod]=true;
    for(auto vec:G[nod]) if(l[vec]==0)
    {
        l[vec]=nod;
        r[nod]=vec;
        return 1;
    }

    for(auto vec:G[nod]) if(pairup(l[vec]))
    {
        l[vec]=nod;
        r[nod]=vec;
        return 1;
    }
    return 0;
}

void suport(int nod)
{
    for(auto vec:G[nod]) if(!in_s[vec+n])
    {
        in_s[vec+n]=true;
        in_s[l[vec]]=false;
        suport(l[vec]);
    }
}

int main()
{
    f>>n>>m;
    for(;m;--m)
    {
        f>>x>>y;
        G[x].push_back(y);
    }

    ok=true;
    while(ok)
    {
        ok=false;
        memset(viz,0,sizeof viz);
        for(i=1;i<=n;++i)
            if(!r[i])
                if(pairup(i))
                    ok=true;
    }

    for(i=1;i<=n;++i) if(r[i]) ++nr_s,in_s[i]=true;
    for(i=1;i<=n;++i) if(!in_s[i]) suport(i);

    cout<<2*n-nr_s<<'\n';

    for(i=1;i<=n;++i)
        cout<<1-in_s[i]+2*(1-in_s[i+n])<<'\n';

    return 0;
}
