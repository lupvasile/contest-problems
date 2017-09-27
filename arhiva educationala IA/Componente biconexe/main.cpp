#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("biconex.in");
ofstream fout("biconex.out");
/// ////////////////////////////////

void read();

#define nmax 100010

vector<int> G[nmax],st;
vector<vector<int>> cmp;
int n,lev[nmax],up[nmax];
bool viz[nmax];

void dfs(int nod,int level)
{
    viz[nod]=1;
    lev[nod]=up[nod]=level;

    st.push_back(nod);

    for(auto son:G[nod])
        if(!viz[son])
        {
            dfs(son,level+1);

            if(up[son]>=level)
            {
                cmp.push_back(vector<int>());
                while(st.back()!=son)
                {
                    cmp.back().push_back(st.back());
                    st.pop_back();
                }

                cmp.back().push_back(son);
                st.pop_back();
                cmp.back().push_back(nod);

            }

            up[nod]=min(up[nod],up[son]);
        }
        else up[nod]=min(up[nod],lev[son]);


}

int main()
{
    int i;
    read();

    for(i=1;i<=n;++i)
        if(!viz[i]) dfs(i,1);

    cout<<cmp.size()<<'\n';
    for(auto it:cmp)
    {
        for(auto itt:it)
            cout<<itt<<' ';
        cout<<'\n';
    }

    return 0;
}
void read()
{
    int m,x,y;
    fin>>n>>m;
    for(;m;--m)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
