#include <iostream>
#include <set>
#include <fstream>

using namespace std;
#define cout g
ifstream f("heapuri.in");
ofstream g("heapuri.out");
multiset <int> m;
int n,t,x,v[200003],l;
int main()
{
f>>n;
for(;n;--n)
{
    f>>t;
    if (t<3) f>>x;
    if(t==1) m.insert(x),v[++l]=x;
    else if (t==2) m.erase(v[x]);
    else cout<<*m.begin()<<'\n';
}
    return 0;
}
