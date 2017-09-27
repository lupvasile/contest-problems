#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define nmax 100010

bool finala[2][nmax];
vector <pair <int,int> > s0,s1,s;
int n,i,k,x;

int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        s0.push_back(make_pair(x,i));
        s.push_back(make_pair(x,i));
        cin>>x;
        s1.push_back(make_pair(x,i));
        s.push_back(make_pair(x,i+nmax));
    }
    sort(s0.begin(),s0.end());
    sort(s1.begin(),s1.end());
    sort(s.begin(),s.end());
    for(i=0;i<(n>>1);++i) finala[0][s0[i].second]=finala[1][s1[i].second]=true;
    for(i=0;i<n;++i) if(s[i].second>nmax) finala[1][s[i].second-nmax]=true;
    else finala[0][s[i].second]=nmax;

    for(i=1;i<=n;++i) cout<<finala[0][i];
    cout<<'\n';
    for(i=1;i<=n;++i) cout<<finala[1][i];
    return 0;
}
