#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");

#define cout g
#define nmax 100010
#define mmax 500010

int n,m,i;
vector <int> G[nmax];
struct
    {
    int a,b;
    } muc[mmax];
bool on[mmax];
vector <int> sol;
stack <int> st;
void read();

bool eulerian()
    {
    //if(!conex()) return false;
    for(i=1; i<=n; ++i) if(G[i].size()&1) return false;
    return true;
    }

void solve()
    {
    int v,w;
    st.push(1);
    while(!st.empty())
        {
        v=st.top();
        while(G[v].size())//v mai are vecini
        {
            if(!on[G[v].back()])
            {
                G[v].pop_back();
                continue;
            }
            w=(muc[G[v].back()].a!=v ? muc[G[v].back()].a:muc[G[v].back()].b);
            on[G[v].back()]=false;
            G[v].pop_back();
            st.push(w);
            v=w;
        }
        sol.push_back(v);
        st.pop();
        }

    for(i=0;i<sol.size();++i) cout<<sol[i]<<' ';
    }

int main()
    {
    read();
    if(eulerian()) solve();
    else cout<<"-1";
    return 0;
    }

void read()
    {
    f>>n>>m;
    for(i=1; i<=m; ++i)
        {
        f>>muc[i].a>>muc[i].b;
        G[muc[i].a].push_back(i);
        G[muc[i].b].push_back(i);
        on[i]=true;
        }
    }
