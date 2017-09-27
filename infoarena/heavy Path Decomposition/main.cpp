#include <bits/stdc++.h>

using namespace std;

ifstream f("heavypath.in");
ofstream g("heavypath.out");

#define nmax 100001
#define cout g
int n,m,i,nr_paths,x,y,tip;
int sz[nmax],val[nmax],pos[nmax],path_nr[nmax];
vector<int> G[nmax];

class c_path
    {
    private:

        vector<int> nodes;
        vector<int> aint;
        void build(int nod,int st,int dr)
            {
            if(st==dr)
                {
                aint[nod]=val[nodes[st]];
                return;
                }

            int mid=(st+dr)>>1;
            int left=nod<<1,right=nod<<1|1;

            build(left,st,mid);
            build(right,mid+1,dr);

            aint[nod]=max(aint[left],aint[right]);
            }

        void update(int nod,int st,int dr,int pos,int val)
            {
            if(st==dr)
                {
                aint[nod]=val;
                return;
                }

            int mid=(st+dr)>>1;
            int left=nod<<1,right=nod<<1|1;

            if(pos<=mid) update(left,st,mid,pos,val);
            else update(right,mid+1,dr,pos,val);

            aint[nod]=max(aint[left],aint[right]);
            }
        int query(int nod,int st,int dr,int x,int y)
            {
            if(x<=st && dr<=y) return aint[nod];

            int mid=(st+dr)>>1;
            int left=nod<<1,right=nod<<1|1;

            if(y<=mid) return query(left,st,mid,x,y);
            else if(x>mid) return query(right,mid+1,dr,x,y);
            else return max(query(left,st,mid,x,y),query(right,mid+1,dr,x,y));
            }

    public:
        int level,parent;
        c_path()
            {
            nodes.clear();
            aint.clear();
            }


        void add(int nod)
            {
            nodes.push_back(nod);
            pos[nod]=nodes.size()-1;
            }

        void make_aint()
            {
            aint.resize(nodes.size()*4+2,0);
            build(1,0,nodes.size()-1);
            }

        void change(int nod,int val)
            {
            update(1,0,nodes.size()-1,pos[nod],val);
            }
        int ask(int x,int y)
            {
            return query(1,0,nodes.size()-1,x,y);
            }
    };

c_path path[nmax];

void read();
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

int make_path(int nod,int fat,int path_no)
    {
    int son_max=-1;
    for(auto son:G[nod])
        {
        if(son==fat) continue;
        if(sz[son]>sz[son_max] || son_max==-1) son_max=son;
        }
    path[path_no].add(nod);
    path_nr[nod]=path_no;

    if(son_max!=-1) make_path(son_max,nod,path_no);

    for(auto son:G[nod])
        {
        if(son==fat || son==son_max) continue;
        ++nr_paths;
        path[nr_paths].parent=nod;
        path[nr_paths].level=path[path_no].level+1;
        make_path(son,nod,nr_paths);
        }
    }

int main()
    {
    read();
    dfs(1,0);
    make_path(1,0,nr_paths);

    for(i=0; i<=nr_paths; ++i) path[i].make_aint();

    for(; m; --m)
        {
        f>>tip>>x>>y;
        if(tip==0)
            {
            path[path_nr[x]].change(x,y);
            }
        if(tip==1)
            {
            int res=0;
            while(1)
                {
                if(path_nr[x]==path_nr[y])
                    {
                    if(pos[x]>pos[y]) swap(x,y);
                    res=max(res,path[path_nr[x]].ask(pos[x],pos[y]));
                    break;
                    }

                if(path[path_nr[x]].level<path[path_nr[y]].level)  swap(x,y);

                res=max(res,path[path_nr[x]].ask(0,pos[x]));

                x=path[path_nr[x]].parent;

                }
            cout<<res<<'\n';
            }
        }
    return 0;
    }
void read()
    {
    int i;
    f>>n>>m;
    for(i=1; i<=n; ++i) f>>val[i];
    for(i=1; i<n; ++i)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    }
