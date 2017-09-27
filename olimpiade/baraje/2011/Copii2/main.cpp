#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("copii2.in");
ofstream fout("copii2.out");
/// ////////////////////////////////

#define nmax 100010

int v[nmax][20];
vector<int> teams[nmax];

inline void convert(int n,int k,int res[])
{
    do
    {
        res[++res[0]]=n%k;
        n/=k;
    }
    while(n!=0);
}

int main()
{
    int n,i,k,r,nr,j;
    fin>>n>>k;

    for(i=0;i<n;++i)
        convert(i,k,v[i]);

    r=v[n-1][0];

    cout<<r<<'\n';

    for(i=1;i<=r;++i)
    {
        nr=0;
        for(j=0;j<k;++j) teams[j].clear();

        for(j=0;j<n;++j)
        {
            if(teams[v[j+1][i]].size()==0) ++nr;
            teams[v[j+1][i]].push_back(j+1);
        }

        cout<<nr<<'\n';

        for(j=0;j<k;++j)
        {
            if(teams[j].size()==0) continue;
            cout<<teams[j].size()<<' ';
            for(auto it:teams[j]) cout<<it<<' ';
            cout<<'\n';
        }
    }

    return 0;
}
