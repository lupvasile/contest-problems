#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define nmax 2001

int n,T;
struct
{
    int x,y;
} p[nmax];
long long res;

void read_data()
{
    res=0;
    fin>>n;
    for(int i=1; i<=n; ++i) fin>>p[i].x>>p[i].y;
}

unsigned long long dist(int a,int b)
{
    return 1ull*(p[a].x-p[b].x)*(p[a].x-p[b].x)+1ull*(p[a].y-p[b].y)*(p[a].y-p[b].y);
}

void solve()
{
    int i,j,k;
    for(k=1; k<=n; ++k)
        for(i=1; i<=n; ++i)
        {
            if(i==k) continue;
            for(j=i+1; j<=n; ++j)
            {
                if(j==k) continue;
                if(dist(i,k)==dist(k,j)) ++res;
            }
        }
}

int main()
{
    int t;
    fin>>T;

    for(t=1; t<=T; ++t)
    {
        read_data();
        solve();
        fout<<"Case #"<<t<<": "<<res<<'\n';
    }

    return 0;
}
