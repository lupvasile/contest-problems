#include <cstdio>
#include <iostream>
using namespace std;
int n,t,p,i,val,st,dr,mid,v[30002];
int main()
{
    freopen("br.in","r",stdin);
    freopen("br.out","w",stdout);
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i) scanf("%d",&v[i]),v[i+n]=v[i];
    for(i=1;i<=2*n;++i) v[i]+=v[i-1];
    for(;t;--t)
    {
        scanf("%d%d",&p,&val);
        if(val<v[p]-v[p-1])
        {
            cout<<"0\n";
            continue;
        }
        st=p;dr=p+n-1;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(val-v[mid]+v[p-1]>=0) st=mid+1;
            else dr=mid-1;
        }
        cout<<st-p<<'\n';
    }
    return 0;
}
