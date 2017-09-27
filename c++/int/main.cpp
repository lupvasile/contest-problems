#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("int.in");
ofstream g("int.out");

#define cout g

struct element{int inc,sf;} v[50010];
int n,i,nr(1),li;

inline bool cmp(element a,element b)
{
    if (a.sf!=b.sf) return a.sf<b.sf;
    return a.inc<b.inc;
}

int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>v[i].inc>>v[i].sf;
    sort(v+1,v+n+1,cmp);
    //for(i=1;i<=n;++i) cout<<v[i].inc<<' '<<v[i].sf<<'\n';
    li=1;
    for(i=2;i<=n;++i)
    {
        while (v[i].inc<v[li].sf) ++i;
        if(i<=n)++nr,li=i;
    }

    cout<<nr;
    return 0;
}
