#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("loto.in");
ofstream g("loto.out");

#define cout g

int n,s;
int a[101];
struct elem{int val,x1,x2,x3;} v[1000020];
int q,nr,p,i,l,j,k,h;
inline bool cmp(elem a,elem b)
{
    return a.val<b.val;
}
inline bool cmp2(elem a,int b)
{
    return a.val<b;
}
int main()
{
    f>>n>>s;
    for(i=0;i<n;++i) f>>a[i];
    sort(a,a+n);
    for(i=0;i<n;++i)
        for(j=i;j<n;++j)
            for(k=j;k<n;++k){
                v[++l].val=a[i]+a[j]+a[k];
                v[l].x1=a[i];
                v[l].x2=a[j];
                v[l].x3=a[k];
            }
    sort(v+1,v+1+l,cmp);
    //q=(l+1)/2;
    for(i=1;i<=l;++i)
    {
        h=lower_bound(v+1,v+l+1,s-v[i].val,cmp2)-v;
        if (v[h].val==s-v[i].val)
        {
            cout<<v[i].x1<<' '<<v[i].x2<<' '<<v[i].x3<<' '<<v[h].x1<<' '<<v[h].x2<<' '<<v[h].x3;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
