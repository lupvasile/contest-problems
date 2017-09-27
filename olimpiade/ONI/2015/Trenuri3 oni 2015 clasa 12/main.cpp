#include <bits/stdc++.h>
using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("trenuri3.in");
ofstream fout("trenuri3.out");

#define nmax 100010

int statie[nmax],capacitate[nmax],which[nmax];
struct
{
    int a,b;
} pass[nmax];

struct eee
{
    int tip,loc,ind;

    bool operator <(const eee &x) const
    {
        if(loc==x.loc) return tip<x.tip;
        return loc>x.loc;
    }

} ev[3*nmax];

class heap_cmp
{
public:
    bool operator() (const int &a,const int &b) const
    {
        return pass[a].a<=pass[b].a;
    }
};

set<int> trains;
set <int,heap_cmp> heap;

int n,m,lev,res;

void citire();

int main()
{
    int i,tren,asta,altu;
    citire();

    for(i=1;i<=lev;++i)
        if(ev[i].tip==0) trains.insert(ev[i].ind);
    else if(ev[i].tip==2)
    {
        if (trains.size())
        {
            asta=ev[i].ind;
            tren=*trains.begin();
            which[asta]=tren;
            heap.insert(asta);
            --capacitate[tren];
            if(!capacitate[tren]) trains.erase(trains.begin());
        }

        else
        {
            if(!heap.size()) continue;
            asta=ev[i].ind;
            altu=*heap.begin();
            if(which[altu]==0) cout<<"ASDF";
            if(pass[asta].a>pass[altu].a)
            {
                heap.erase((heap.begin()));
                which[asta]=which[altu];
                which[altu]=0;
                heap.insert(asta);
            }
        }
    }
    else
    {
        if(which[ev[i].ind])
        {
            asta=ev[i].ind;
            heap.erase(asta);
            capacitate[which[asta]]++;
            if(capacitate[which[asta]]==1) trains.insert(which[asta]);

        }
    }

    for(i=1;i<=m;++i) if(which[i]) ++res;
    cout<<res<<'\n';
    #ifdef INFOARENA
     for(i=1;i<=m;++i) cout<<which[i]<<'\n';
    #endif // INFOARENA
    return 0;
}

void citire()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>statie[i]>>capacitate[i];
        ev[++lev]={0,statie[i],i};
    }
    for(i=1; i<=m; ++i)
    {
        fin>>pass[i].a>>pass[i].b;
        ev[++lev]={2,pass[i].b,i};
        ev[++lev]={1,pass[i].a,i};
    }
    sort(ev+1,ev+lev+1);
}

