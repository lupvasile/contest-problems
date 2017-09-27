#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

#define nmax 10001
int ctot,x,y,n,k;
short int  nod,i;
short cost[nmax];//costul pe muchia ce ma duce la nodul i
short grad[nmax];
vector <short int> G[nmax];
vector <short int> ::iterator it;
queue <short int> q;
priority_queue <short int> heap;

int main()
{
    freopen("cezar.in","r",stdin);
    freopen("cezar.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        G[x].swap(G[x]);
        G[y].swap(G[y]);
        ++grad[x];++grad[y];
    }
    for(i=1;i<=n;++i) if(grad[i]==1) q.push(i);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        --grad[nod];
        ++cost[nod];
        for(it=G[nod].begin();it!=G[nod].end();++it) if(grad[*it]>0)
        {
            --grad[*it];
            if(grad[*it]==1) q.push(*it);
            cost[*it]+=cost[nod];
        }
        ctot+=cost[nod];
    }
    sort(cost+1,cost+n+1);
    for(i=0;n && (i<=k);++i,--n) ctot-=cost[n];
    printf("%d",ctot);
    return 0;
}
