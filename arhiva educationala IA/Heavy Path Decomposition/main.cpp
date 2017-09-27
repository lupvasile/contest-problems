#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("heavypath.in");
ofstream fout("heavypath.out");
/// ////////////////////////////////

void read();

#define nmax 100001

int n,m,nr_paths;
int sz[nmax],which[nmax],pos[nmax],val[nmax];
vector<int> G[nmax];

class C_PATH
{
private:
    vector<int> aib;
    vector<int> nodes;

    void build(int nod,int st,int dr)
    {
        if(st==dr)
        {
            aib[nod]=val[nodes[st]];
            return;
        }

        int mid=(st+dr)>>1,left=nod<<1,right=nod<<1|1;

        build(left,st,mid);
        build(right,mid+1,dr);

        aib[nod]=max(aib[left],aib[right]);
    }

    void update(int nod,int st,int dr,int pos,int val)
    {
        if(st==dr)
        {
            aib[nod]=val;
            return;
        }

        int mid=(st+dr)>>1,left=nod<<1,right=nod<<1|1;

        if(pos<=mid) update(left,st,mid,pos,val);
        else update(right,mid+1,dr,pos,val);

        aib[nod]=max(aib[left],aib[right]);
    }

    int query(int nod,int st,int dr,int x,int y)
    {
        if(x<=st && dr<=y) return aib[nod];

        int mid=(st+dr)>>1,left=nod<<1,right=nod<<1|1;

        if(y<=mid) return query(left,st,mid,x,y);
        else if(x>=mid+1) return query(right,mid+1,dr,x,y);
        else return max(query(left,st,mid,x,y),query(right,mid+1,dr,x,y));
    }

public:
    int father,lev;

    void build_path()
    {
        aib.resize(nodes.size() * 4 + 2);
        build(1,0,nodes.size()-1);
    }

    void add(int nod)
    {
        nodes.push_back(nod);
        pos[nod]=nodes.size()-1;
    }

    void update(int nod,int val)
    {
        ::val[nod]=val;
        update(1,0,nodes.size()-1,pos[nod],val);
    }

    int ask(int x,int y)
    {
        return query(1,0,nodes.size()-1,x,y);
    }

}path[nmax];

void dfs(int nod,int fat)
{
    sz[nod]=1;

    for(auto son:G[nod])
    {
        if(son==fat) continue;
        dfs(son,nod);
        sz[nod]+=sz[son];
    }
}

void make_paths(int nod,int fat,int path_nr)
{
    ///vezi daca poti scapa de path_nr ca argument
    path[path_nr].add(nod);
    which[nod]=path_nr;

    int sonSpecial = 0;

    for(auto son:G[nod])
    {
        if(son==fat) continue;
        if(sz[sonSpecial]<sz[son]) sonSpecial = son;
    }

    if(sonSpecial==0) return;

    make_paths(sonSpecial,nod,path_nr);

    for(auto son:G[nod])
    {
        if(son==fat || son==sonSpecial) continue;

        ++nr_paths;
        path[nr_paths].lev = path[path_nr].lev + 1;
        path[nr_paths].father = nod;
        make_paths(son,nod,nr_paths);
    }
}

int main()
{
    read();
    dfs(1,0);
    make_paths(1,0,0);
    for(int i=0;i<=nr_paths;++i) path[i].build_path();

    int maxx,tip,x,y;

    for(; m; --m)
    {
        fin>>tip>>x>>y;

        if(tip==0) path[which[x]].update(x,y);
        else
        {
            maxx=0;
            while(x!=y)
            {
                if(which[x]==which[y])
                {
                    if(pos[x]>pos[y]) swap(x,y);
                    maxx=max(maxx,path[which[x]].ask(pos[x],pos[y]));
                    break;
                }

                if(path[which[x]].lev<path[which[y]].lev) swap(x,y);

                maxx=max(maxx,path[which[x]].ask(0,pos[x]));
                x=path[which[x]].father;
            }
            maxx=max(maxx,val[x]);

            cout<<maxx<<'\n';
        }
    }


    return 0;
}

void read()
{
    int x,y,i;

    fin>>n>>m;
    for(i=1;i<=n;++i) fin>>val[i];

    for(i=1;i<n;++i)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
