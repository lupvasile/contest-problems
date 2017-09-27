#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("boom.in");
ofstream g("boom.out");

#define cout g

int n,m,p,q,x,i,nod,cost,vecin;
int sarja[55],csarja[55];
int P[1<<20],C[1<<20],SP[1<<20];
vector <int> sol;
struct elem
{
    int nod,cost;
    bool operator<(const elem &a) const
    {
        return cost>a.cost;
    }
};
priority_queue <elem> Q;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>csarja[i]>>q;
        for(;q;--q)
        {
            f>>x;
            --x;
            sarja[i]|=(1<<x);
        }
        sarja[i]=~sarja[i];
    }

    nod=(1<<n)-1;
    Q.push({nod,1});
    C[nod]=1;
    while(!Q.empty())
    {
        nod=Q.top().nod;
        cost=Q.top().cost;
        if(nod==0) goto gata;
        Q.pop();
        for(i=1;i<=m;++i)
        {
            x=nod&sarja[i];
            vecin=0;
            for(int h=1;h<=x;h<<=1) if(x&h)
            {
                if(h!=(1<<(n-1)))  vecin|=(h<<1);
                vecin|=(h>>1);
            }
            if(C[vecin]==0 || C[nod]+csarja[i]<C[vecin])
            {
                P[vecin]=nod;
                SP[vecin]=i;
                C[vecin]=C[nod]+csarja[i];
                Q.push({vecin,C[vecin]});
            }
        }

    }
    gata:;
    cout<<C[0]-1<<'\n';
    for(x=0;P[x]!=0;x=P[x]) sol.push_back(SP[x]);
    cout<<sol.size()<<'\n';
    for(i=0;i<sol.size();++i) cout<<sol[i]<<'\n';
    return 0;
}
