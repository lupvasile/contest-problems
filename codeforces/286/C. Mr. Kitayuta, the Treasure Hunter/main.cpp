#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

#define nmax 30100
#define lim 300


#ifndef ONLINE_JUDGE
ifstream f("date.in");
#define cin f
#endif // ONLINE_JUDGE


int d,n,i,x,rez,nn,l;
int dp[nmax];
struct eee{int a,d,nr;};
queue <eee> q;

int main()
{
    cin>>n>>d;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        ++dp[x];
    }
    for(i=1;i<=lim;++i) dp[i]+=dp[i-1];
    q.push({d,d,0});
    while(!q.empty())
    {
        x=q.front().a;
        l=q.front().d;
        nn=q.front().nr;
        q.pop();
        nn+=(dp[x]-dp[x-1]);
        cout<<x<<'\n';
        if(nn>rez) rez=nn;
        if(l==1)
        {
            rez=max(rez,nn+dp[lim]-dp[x]);
            continue;
        }
        if(l>1) if(x+l-1<=lim) q.push({x+l-1,l-1,nn});
        if(x+l<=lim) q.push({x+l,l,nn});
        if(x+l+1<=lim) q.push({x+l+1,l+1,nn});
    }
    cout<<rez;
    return 0;
}
