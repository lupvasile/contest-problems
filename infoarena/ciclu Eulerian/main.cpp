#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");

#define cout g
#define nmax 100010
#define foor(it,d) for(__typeof(d.begin()) it=d.begin();it!=d.end();++it)
int n,m,i,x,y,v,w;
list <int> G[nmax];
int grad[nmax];
stack <int> st;
vector<int> V;

void read();

bool eulerian()
{
    for(int i=1; i<=n; ++i) if(grad[i]%2) return false;
    return true;
}
void eerase(int a,int b)
{
    --grad[a];
    --grad[b];
    G[a].pop_front();
    foor(it,G[b])
    {
        if (*it==a)
        {
            G[b].erase(it);
            return;
        }
    }
}
void rez_iterativ()
{
    st.push(1);
        while (!st.empty())
        {
            v=st.top();

            while (grad[v])
            {
                w=G[v].front();
                eerase(v,w);
                st.push(w);
                v=w;
            }
            st.pop();
            V.push_back(v);
        }
}
void euler(int nod)
{
    int w;
    while(grad[nod])
        {
          w=G[nod].front();
          eerase(nod,w);
        euler(w);
        }
    V.push_back(nod);
}
void rez_recursiv()
{
    euler(1);
}

int main()
{
    read();
    if(!eulerian())
    {
        cout<<"-1";
    }
    else
    {
    //rez_recursiv();
    rez_iterativ();
    foor(it,V) cout<<*it<<' ';
    //cout<<"ASDF"<<grad[3];
    }
    return 0;
}
void read()
{
    f>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++grad[x];
        ++grad[y];
    }
}
