#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
 
using namespace std;
 
ifstream f("confuzie.in");
ofstream g("confuzie.out");
 
#define cout g
#define nmax 200001
 
int lev[nmax],sz[nmax],nr_paths,which[nmax],val[nmax],parent[nmax];
vector<int> G[nmax];
int m,tip,x,y,z,res,n,i;
 
struct elem_set{int nod;
bool operator<(elem_set a) const
{
    return lev[nod]<lev[a.nod];
}
};
 
set<elem_set> s[nmax];
set<elem_set> ::iterator its;
 
void dfs(int nod,int fat)
{
    int son_max=-1;
 
    sz[nod]=1;
    for(auto son:G[nod])
    {
        if(son==fat) continue;
        lev[son]=lev[nod]+1;
        dfs(son,nod);
        sz[nod]+=sz[son];
        if(son_max==-1 || sz[son_max]<sz[son]) son_max=son;
    }
 
    if(son_max==-1) which[nod]=++nr_paths;
    else which[nod]=which[son_max];
 
    for(auto son:G[nod])
    {
        if(son==son_max || son==fat) continue;
        parent[which[son]]=nod;
    }
}
int gi();
 
 
void read()
{
    n=gi();
    m=gi();
    for(i=1;i<n;++i)
    {
        x=gi();
        y=gi();
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
 
void change(int id,int nod)
{
    if(val[nod]==1) s[id].erase(elem_set ({nod}));
    if(val[nod]==0) s[id].insert(elem_set {nod});
    val[nod]^=1;
}
 
int ask(int id,int nod,int lim)
    {
        if(nod==0)
        {
            if(lev[s[id].begin()->nod]<=lim) return s[id].begin()->nod;
            else return 0;
        }
       its=s[id].lower_bound(elem_set {nod});
       if(its==s[id].end()) return 0;
       if(lev[its->nod]>lim) return 0;
       return its->nod;
    }
int main()
{
    read();
    dfs(1,0);
 
    for(;m;--m)
    {
        tip=gi();
        if(tip==0)
        {
            x=gi();
            change(which[x],x);
        }
        if(tip==1)
        {
            x=gi();
            y=gi();
            res=-1;
            while(1)
            {
                if(which[x]==which[y])
                {
                    z=ask(which[x],x,lev[y]);
                    if(z) if(res==-1 || lev[z]<lev[res]) res=z;
                    break;
                }
 
                z=ask(which[y],0,lev[y]);
                if (z) if(res==-1 || lev[z]<lev[res]) res=z;
                y=parent[which[y]];
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}
 
#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
{
    int n(0);
    while(!(buf[pos]>='0' && buf[pos]<='9')) if(++pos>=maxb) f.read(buf,maxb),pos=0;
    while(buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    return n;
}