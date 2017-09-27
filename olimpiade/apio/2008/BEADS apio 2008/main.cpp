#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("beads.in");
ofstream g("");

//#define cout g
#define nmax 300010

typedef vector<int>::iterator itt;

vector <int > AIB[nmax];
int n,m,i,a,b;

void update(int pos,int a)
{
    for(;pos<=n;pos+=(pos & -pos))
        AIB[pos].push_back(a);
}
int query(int s,int stop)
{
    int step;
    for(step=1;step<=stop;step<<=1);
    step>>=1;
    for(i=0;step;step>>=1)
    {
        if(i+step<=stop)
        {
            i+=step;
            for(itt it=AIB[i].begin();it!=AIB[i].end();++it)
            {
               if(*it==s) s+=1;
               else if (*it+1==s) s-=1;
            }
        }
    }
    return s;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>a;
        update(i,a);
    }
    int q;
    f>>q;
    for(;q;--q)
    {
        f>>a>>b;
        cout<<query(a,b)<<'\n';
    }

    return 0;
}
