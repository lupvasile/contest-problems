#include <iostream>
#include <tr1/unordered_map>
#include <cstdio>

using namespace std;
using namespace tr1;

#define nmax 1000010

unordered_map <int,int> m;
int n,i,x,j;
int l[nmax],r[nmax],v[nmax];
int aib[nmax];
long long res;
void add(int pos)
{
    for(;pos<=n;pos+=(pos&-pos)) ++aib[pos];
}

void pop(int pos)
{
    for(;pos<=n;pos+=(pos&-pos)) --aib[pos];
}

int query(int pos)
{
    int res=0;
    for(;pos;pos-=(pos&-pos)) res+=aib[pos];
    return res;
}
int main()
{
    //freopen("date.in","r",stdin);
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++m[v[i]];
        l[i]=m[v[i]];
    }
    for(i=1;i<=n;++i)
    {
        r[i]=m[v[i]];
        add(r[i]);
        --m[v[i]];
    }
    for(i=1;i<=n;++i)
    {
        pop(r[i]);
        res+=query(l[i]-1);
    }
    cout<<res;
    return 0;
}
