#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream f("numar2.in");
ofstream g("numar2.out");

#define cout g
#define nmax 110

int n,i,maxx,pos,st,dr,m,x;
int v[nmax];
vector<int> prod;
typedef  vector<int>::iterator itt;

void bback(int lev,int pos,int p)
{
    int i;
    for(i=pos+1;i<=n && 1LL*p*v[i]<=maxx;++i)
    {
        prod.push_back((lev&1) ? p*v[i]:-p*v[i]);
        bback(lev+1,i,p*v[i]);
    }
}

int calc(int x)
{
    int pos(0);
    for(itt it=prod.begin();it!=prod.end() && (*it)<=x;++it) pos+=(x/(*it));
    return pos;
}

inline bool multiplu(int x)
{
    for(int i=1;i<=n;++i) if(x%v[i]==0) return true;
    return false;
}

int main()
{
    f>>n>>pos;
    for(i=1;i<=n;++i) f>>v[i];
    maxx=pos*v[1];
    bback(1,0,1);
    sort(prod.begin(),prod.end());
    st=v[1];dr=maxx;
    while(st<=dr)
    {
        m=(st+dr)/2;
        if(calc(m)<=pos) st=m+1;
        else dr=m-1;
    }
    x=dr;
    while(!multiplu(x)) --x;
    cout<<x;
    return 0;
}
