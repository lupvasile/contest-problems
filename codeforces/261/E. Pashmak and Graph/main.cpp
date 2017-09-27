#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define foor(x,y,z) for(__typeof(y) x=y; x!=z; ++x)

vector<pair<int,int> > v[100410];
pair<int,int> dp[300400];
//in dp primu ii lungimea si al doilea ii ultimul arc
int a,b,c,m,n,c_max,maxx;

int main()
{
        //freopen("date.in","r",stdin);
    cin>>n>>m;
    foor(i,0,m)
    {
        cin>>a>>b>>c;
       // if(n==4921 && m==219203) cout<<a<<" "<<b<<' '<<c<<'\n';
        c_max=max(c,c_max);
        v[c].push_back(make_pair(a,b));
    }
   //  if(n==4921 && m==219203) return 0;
    foor(i,0,c_max+1)
    {
        if(v[i].size()>0)
        foor(it,v[i].begin(),v[i].end())
        {
            a=it->first;
            b=it->second;
            if(i>dp[a].second && dp[b].first<dp[a].first+1)
            {
               dp[b].first= dp[a].first+1;
               dp[b].second=i;
            }

        }
    }
    foor(i,1,n+1) maxx=max(maxx,dp[i].first);
    cout<<maxx;
    return 0;
}
