#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("undo.in");
ofstream fout("undo.out");
/// ////////////////////////////////

#define nmax 522
#define mmax 500010
#define chf(x) (x&(-x))

int a[nmax][nmax],n,lop;

struct eee
{
    int x,y,z,prev;
    vector<int> q;
};
struct qeee{int x,y,res;};
eee op[mmax];
vector<qeee> qop;
vector<int> G[mmax];

int query(int x,int y)
{
    int res=0,yy;

    for(; x; x-=chf(x))
        for(yy=y; yy; yy-=chf(yy))
            res+=a[x][yy];

    return res;
}

void update(int x,int y,int val)
{
    int yy;
    if(x==0) return;
    for(; x<=n; x+=chf(x))
        for(yy=y; yy<=n; yy+=chf(yy))
            a[x][yy]+=val;
}

void dfs(int nod)
{
     update(op[nod].x,op[nod].y,op[nod].z);

     for(auto it:op[nod].q)
            qop[it].res=query(qop[it].x,qop[it].y);

    for(auto son:G[nod]) dfs(son);

    update(op[nod].x,op[nod].y,-op[nod].z);
}

int main()
{
    int q,x,y,z,tip,i;
    fin>>n>>q;

    for(;q;--q)
    {
        fin>>tip;
        if(tip==2)
        {
            fin>>x>>y;
            qop.push_back({x,y});
            op[op[lop].prev].q.push_back(qop.size()-1);
        }

        if(tip==1)
        {
            fin>>x>>y>>z;
            ++lop;
            op[lop]= {x,y,z,lop};
            G[op[lop-1].prev].push_back(lop);
        }
        if(tip==3)
        {
            fin>>x;
            for(x=lop-x; x!=op[x].prev; x=op[x].prev);
            op[++lop]={0,0,0,x};
        }

    }

    dfs(0);

    for(auto &it: qop) cout<<it.res<<'\n';

    return 0;
}
