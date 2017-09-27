#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("cuplaj.in");
ofstream g("cuplaj.out");

#define cout g
#define nmax 10010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,m,e,x,y,i,cuplaj;
int L[nmax],R[nmax];
vector<int> G[nmax];
bool ok=true,viz[nmax];

bool pairup(int nod)
{
    //if(viz[nod]) return 0;
    viz[nod]=true;

    foor(it,G[nod]) if(L[*it]==0)//il cuplez cu un vecin liber
    {
        R[nod]=*it;
        L[*it]=nod;
        return 1;
    }

    foor(it,G[nod]) if(L[*it]!=nod)if(pairup(L[*it]))//il cuplez cu un vecin, vechiul cuplaj il rup
    {
        R[nod]=*it;
        L[*it]=nod;
        return 1;
    }
    return 0;
}

int main()
{

    f>>n>>m>>e;
    for(;e;--e)
    {
        f>>x>>y;
        G[x].push_back(y);
    }

    while(ok)
    {
        ok=false;
        for(i=1;i<=n;++i) viz[i]=false;
        for(i=1;i<=n;++i) if(R[i]==0)//nodul nu e in cuplaj
                    if(pairup(i)) ok=true;
    }
    for(i=1;i<=n;++i) if(R[i]) ++cuplaj;

    cout<<cuplaj<<'\n';
    for(i=1;i<=n;++i) if(R[i]) cout<<i<<' '<<R[i]<<'\n';
    return 0;
}
