#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#ifdef INFOARENA
#define cout g
#endif // INFOARENA

ifstream f("revolutie.in");
ofstream g("revolutie.out");

#define nmax 130
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
int n,i,j,x;
vector <int> G[nmax];
bool viz[nmax];
int R[nmax],L[nmax];
vector <pair<int,int> > sol;

bool pairup(int nod)
{
    if(viz[nod]) return false;
    viz[nod]=true;
    foor(it,G[nod]) if(L[*it]==0)
    {
        L[*it]=nod;
        R[nod]=*it;
        return 1;
    }
    foor(it,G[nod]) if(pairup(L[*it]))
    {
        L[*it]=nod;
        R[nod]=*it;
        return 1;
    }
    return 0;
}

int main()
{
    f>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
    {
        f>>x;
        if(x) G[i].push_back(j);
    }

    bool ok=true;
    while(ok)
    {
        ok=false;
        for(i=1;i<=n;++i) viz[i]=0;
        for(i=1;i<=n;++i) if(R[i]==0) if(pairup(i)) ok=true;
    }

    for(i=1;i<=n;++i) if(R[i]==0)
    {
        cout<<-1;
        return 0;
    }

    for(i=1;i<=n;++i)
        if(L[i]!=i)
    {
        sol.push_back(make_pair(i,L[i]));
        L[R[i]]=L[i];
        R[L[i]]=R[i];
    }

    cout<<sol.size()<<'\n';
    foor(it,sol) cout<<"L "<<it->first<<' '<<it->second<<'\n';

    return 0;
}
