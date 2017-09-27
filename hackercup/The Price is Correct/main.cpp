#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define nmax 100010

int n,T;
unsigned long long res,P;
unsigned long long v[nmax];

void read_data()
{
    int i;
    res=0;
    fin>>n>>P;
    for(i=1;i<=n;++i)
    {
        fin>>v[i];
        v[i]+=v[i-1];
    }
}

int caut(int st,int dr)
{
    int mid,r=dr;

    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(v[r]-v[mid-1]<=P) dr=mid-1;
        else st=mid+1;
    }
    return dr;
}

void solve()
{
    int i,poz;
    for(i=1;i<=n;++i)
    {
        if(v[i]-v[i-1]>P) continue;
        poz=caut(1,i);
        res=res+i-poz;
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
