#include <iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;
#define nmax 2010
unordered_map <string,int> m;
int n,i,p,changes,x;
string old,nnew;
int dad[nmax],son[nmax];
string ss[nmax];

int main()
    {
    cin>>n;
    for(i=1; i<=n; ++i)
        {
        cin>>old>>nnew;
        if(m[old]==0)
            {
            ++changes;
            m[old]=++p;
            ss[p]=old;
            }
        m[nnew]=++p;
        ss[p]=nnew;
        dad[p]=m[old];
        son[m[old]]=p;
        }
    cout<<changes<<'\n';
    for(i=1;i<=p;++i) if(dad[i]==0)
    {
        cout<<ss[i]<<' ';
        for(x=son[i];son[x];x=son[x]);
        cout<<ss[x]<<'\n';
    }
return 0;
    }
