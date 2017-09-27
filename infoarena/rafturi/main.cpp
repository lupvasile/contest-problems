#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("rafturi.in");
ofstream g("rafturi.out");

#define cout g
#define dmax 10010

int d,n,i,x,y;
int v[dmax],efort[dmax];//efort[i] ii efortu minim pentru a rezolva toate dulapurile pana la i inclusiv
#define v (v+3)

int main()
{
    f>>d>>n;
    for(;n;--n)
    {
        f>>x>>y;
        v[x]=max(v[x],y);
    }
    for(i=1;i<=d;++i)
    {
        efort[i]=v[i]+efort[i-1];
        efort[i]=min(efort[i],max(v[i-1],v[i])+efort[i-2]);
        efort[i]=min(efort[i],max(v[i-1],max(v[i-2],v[i]))+efort[i-3]);
    }
    cout<<efort[d];
    return 0;
}
