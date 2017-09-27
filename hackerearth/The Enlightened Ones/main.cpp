#include <iostream>
#include <algorithm>

using namespace std;

#define nmax 100010

int v[nmax],n,k;

bool posibil(int r)
{
    int lim(0),nr(0);
    for(int i=1;i<=n;++i)
    {
        if(v[i]<=lim) continue;
        ++nr;
        lim=v[i]+2*r;

        if(nr>k) return 0;
    }
    return 1;
}

int main()
{
    int st(0),dr(nmax*100),mid;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>v[i];

    sort(v+1,v+n+1);

    while(st<=dr)
    {
        mid=(st+dr)>>1;
        if(posibil(mid)) dr=mid-1;
        else st=mid+1;
    }

    cout<<st;

    return 0;
}
