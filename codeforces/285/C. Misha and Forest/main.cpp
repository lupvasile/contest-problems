#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define nmax 70000
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
int i,n,nod,nrm;
int s[nmax],grad[nmax],v[nmax];
vector <int> G[nmax];
queue <int> q;


int main()
{
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>grad[i];
        cin>>s[i];
        if(grad[i]==1) q.push(i);
    }
    while (!q.empty())
    {
        nod=q.front();
        q.pop();
        if(grad[nod]==0) continue;
        foor(it,G[nod]) s[nod]^=*it;
        if(grad[s[nod]]==0) continue;
        G[nod].push_back(s[nod]);
        G[s[nod]].push_back(nod);
        --grad[nod];
        --grad[s[nod]];
        if(grad[s[nod]]==1) q.push(s[nod]);
        ++nrm;
    }
    //nrm=0;
    //for(i=0;i<n;++i) foor(it,G[i]) if(*it>i)++nrm;
    cout<<nrm<<'\n';
    for(i=0;i<n;++i) foor(it,G[i]) if(*it>i) cout<<i<<' '<<*it<<'\n';
    return 0;
}
