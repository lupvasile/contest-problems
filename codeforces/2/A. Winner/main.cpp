#include <iostream>
#include <map>

using namespace std;

map <string,int> m,mm;
map<string,bool> cand;
string winner,s;
pair<string,int> comm[1010];
int x,n,points;

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>s>>x;
        m[s]+=x;
        comm[i]={s,x};
    }
    for(auto it:m)
        if(m[winner]<it.second) winner=it.first;

    points=m[winner];

    for(auto it:m)
        if(it.second==m[winner])
                cand[it.first]=1;

    for(i=1;i<=n;++i)
    {
        mm[comm[i].first]+=comm[i].second;
        if(mm[comm[i].first]>=points && cand[comm[i].first])
        {
            cout<<comm[i].first;
            return 0;
        }
    }
    return 0;
}
