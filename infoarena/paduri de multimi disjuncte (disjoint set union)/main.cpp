#include <iostream>
#include <fstream>
using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

#define cout g
#define nmax 100010

int n,m,i,x,y,tip;
int T[nmax],R[nmax];
inline int rad(int x)
{
    if (x!=T[x]) x=rad(T[x]);
    return x;
}

void uneste(int a,int b)
{
    if(R[a]>=R[b]) T[b]=a;
    else T[a]=b;
    if(R[a]==R[b]) ++R[a];
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) T[i]=i;
    for(;m;--m)
    {
        f>>tip>>x>>y;
        if(tip==1) uneste(rad(x),rad(y));
        else if(rad(x)==rad(y)) cout<<"DA\n";
                                else cout<<"NU\n";
    }

    return 0;
}
