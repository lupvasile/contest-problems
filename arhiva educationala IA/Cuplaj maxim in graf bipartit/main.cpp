#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");
/// ////////////////////////////////

void read();

#define nmax 10010

int R[nmax],L[nmax],n,m;
bool on[nmax];
vector<int> G[nmax];

bool cupleaza(int nod)
{
    on[nod]=true;
    for(auto vec:G[nod])
        if(!L[vec])
    {
        R[nod]=vec;
        L[vec]=nod;
        on[nod]=false;
        return 1;
    }

    for(auto vec:G[nod])
        if(!on[L[vec]] && cupleaza(L[vec]))
        {
            R[nod]=vec;
            L[vec]=nod;
            on[nod]=false;
            return 1;
        }

    return 0;
}

int main()
{
    int i,nr(0);
    read();
    for(i=1;i<=n;++i)
        if(!R[i]) cupleaza(i);

    for(i=1;i<=n;++i) nr+=(R[i]>0);
    cout<<nr<<'\n';
    for(i=1;i<=n;++i)
        if(R[i]) cout<<i<<' '<<R[i]<<'\n';
    return 0;
}

void read()
{
    int k,x,y;
    fin>>n>>m>>k;
    for(;k;--k)
    {
        fin>>x>>y;
        G[x].push_back(y);
    }
}
