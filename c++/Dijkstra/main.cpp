#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

#define cout g
#define nmax 50010
#define inf 0x3f3f3f3f

vector <pair<int,int> > vecini[nmax];
int n,m,a,b,c,i;
int distanta[nmax];
set <pair<int,int> > heap;
int nod,cost;
#define maxb 16384
char buf[maxb];
int p(maxb);
int gI()
{
    int nr=0;
    while (buf[p]<'0' || buf[p]>'9')if(++p>=maxb) f.read(buf,maxb),p=0;
    while (buf[p]>='0' && buf[p]<='9')
    {
        nr=nr*10+buf[p]-'0';
        if(++p>=maxb) f.read(buf,maxb),p=0;
    }
    return nr;
}
int main()
{
n=gI();m=gI();
memset(distanta,inf,(n+1)*sizeof(int));
for(;m;--m)
{
    a=gI();b=gI();c=gI();
    vecini[a].push_back(make_pair(b,c));
}
distanta[1]=0;
heap.insert(make_pair(0,1));
while (!heap.empty())
{
    cost=heap.begin()->first;
    nod=heap.begin()->second;
    heap.erase(heap.begin());
    for(i=0;i<vecini[nod].size();++i)
    if(distanta[vecini[nod][i].first]>distanta[nod]+vecini[nod][i].second)
    {
        distanta[vecini[nod][i].first]=distanta[nod]+vecini[nod][i].second;
        heap.insert(make_pair(distanta[vecini[nod][i].first],vecini[nod][i].first));
    }
}
 for(i=2;i<=n;++i) cout<<(distanta[i]==inf ? 0:distanta[i])<<' ';
    return 0;
}
