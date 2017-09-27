#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define nmax 100010

int n,m,i,x,y,j;
unsigned long long minn,q,s_init;
int a,b;
vector <int> s[nmax];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
    #endif
    cin>>n>>m>>a;

    for(i=2;i<=m;++i)
    {
        cin>>b;
        minn+=abs(b-a);
        if(b!=a) s[b].push_back(a),s[a].push_back(b);
        a=b;
    }
    s_init=minn;
    for(i=1;i<=n;++i)
        if(s[i].size())
    {
        q=s_init;
        x=s[i].size()-1;
        nth_element(s[i].begin(),s[i].begin()+(x>>1),s[i].end());
        x=s[i][x>>1];
        for(j=0;j<s[i].size();++j) q=q-abs(i-s[i][j])+abs(x-s[i][j]);
        minn=min(minn,q);
    }
    cout<<minn;
    return 0;
}

