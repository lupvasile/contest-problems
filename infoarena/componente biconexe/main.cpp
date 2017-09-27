#include <bits/stdc++.h>

using namespace std;

ifstream f("biconex.in");
ofstream g("biconex.out");

#define cout g
#define nmax 100010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

vector <int> G[nmax];
vector <set<int> > C;
int n,m,x,y,i;
int lev[nmax],up[nmax];
stack <pair<int,int> > st;

void add_component(int x,int y)
    {
    int tx,ty;
    set<int> c;
    do
        {
        tx=st.top().first;
        ty=st.top().second;
        st.pop();
        c.insert(tx);
        c.insert(ty);
        }
    while(tx!=x && ty!=y);
    C.push_back(c);
    }

void dfs(int nod,int fat,int level)
    {
    up[nod]=level;
    lev[nod]=level;
    foor(it,G[nod])
        {
        if(!lev[*it])
            {
            st.push({nod,*it});
            dfs(*it,nod,level+1);
            up[nod]=min(up[nod],up[*it]);
            if(up[*it]>=lev[nod]) add_component(nod,*it);
            }
        else up[nod]=min(up[nod],lev[*it]);
        }
    }

int main()
    {
    f>>n>>m;
    for(; m; --m)
        {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    dfs(1,0,1);
    cout<<(C.size())<<'\n';
    for(i=0;i<C.size();++i)
    {
        foor(it,C[i]) cout<<*it<<' ';
        cout<<'\n';
    }
    return 0;
    }
