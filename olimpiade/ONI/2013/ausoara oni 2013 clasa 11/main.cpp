#include <bits/stdc++.h>

using namespace std;

ifstream f("ausoara.in");
ofstream g("ausoara.out");

#define cout g
#define nmax 101
#define mmax 1001

int i,j,v[nmax][mmax],pos[nmax],val,minn,n,ip;
vector<int> sol;

int main()
{
    f>>n;

    for(i=1;i<=n;++i)
    {
        f>>v[i][0];
        for(j=1;j<=v[i][0];++j) f>>v[i][j];
        pos[i]=1;
    }

    while(pos[1]<=v[1][0])
    {
        val=v[1][pos[1]];
        minn=mmax;
        for(i=1;i<=n;++i)
        {
            while(v[i][pos[i]]<val && pos[i]<=v[i][0]) ++pos[i];
            ip=pos[i];
            while(v[i][pos[i]]==val) ++pos[i];
            minn=min(minn,pos[i]-ip);
        }
        for(i=1;i<=minn;++i) sol.push_back(val);
    }
    cout<<sol.size()<<' ';
    for(auto el:sol) cout<<el<<' ';
    return 0;
}
