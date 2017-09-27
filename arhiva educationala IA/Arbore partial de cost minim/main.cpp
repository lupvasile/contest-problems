#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("apm.in");
ofstream fout("apm.out");
/// ////////////////////////////////

void read();

#define nmax 200010

struct mc
{
    int x,y,c;
    void read()
    {
        fin>>x>>y>>c;
    }
    bool operator < (const mc &o) const
    {
        return c<o.c;
    }
    void show()
    {
        cout<<x<<' '<<y<<'\n';
    }

} muc[nmax<<1];

int n,m,ctot;
vector<int> G[nmax];
int dad[nmax];
bool on[nmax<<1];

int get_dad(int x)
{
    if(x!=dad[x]) dad[x]=get_dad(dad[x]);
    return dad[x];
}

void unite(int x,int y)
{
    x=get_dad(x);y=get_dad(y);
    dad[x]=y;
}

int main()
{
    int i;
    read();
    sort(muc+1,muc+m+1);
    for(i=1;i<=n;++i) dad[i]=i;

    for(i=1;i<=m;++i)
        if(get_dad(muc[i].x)!=get_dad(muc[i].y))
        {
            unite(muc[i].x,muc[i].y);
            ctot+=muc[i].c;
            on[i]=1;
        }

    cout<<ctot<<'\n';
    cout<<n-1<<'\n';
    for(i=1;i<=m;++i) if(on[i]) muc[i].show();

    return 0;
}

void read()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        muc[i].read();
        G[muc[i].x].push_back(i);
        G[muc[i].y].push_back(i);
    }
}
