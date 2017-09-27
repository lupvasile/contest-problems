#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

#define cout g
#define mmax 400010
#define nmax 100010

int X[mmax],Y[mmax],C[mmax],IND[mmax],T[nmax];
int n,m,i,cost_apm,x,y;
vector <int> apm;

bool cmp(int a,int b)
{
    return C[a]<C[b];
}

inline int find(int x)
{
    if(x!=T[x]) T[x]=find(T[x]);
    return T[x];
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>X[i]>>Y[i]>>C[i];
        IND[i]=i;
    }
    for(i=1;i<=n;++i) T[i]=i;

    sort(IND+1,IND+m+1,cmp);

    for(i=1;i<=m;++i)
    {
        if((x=find(X[ IND[i] ]))!=(y=find(Y[ IND[i] ])))
        {
          cost_apm+=C[ IND[i] ];
          T[x]=y;
          apm.push_back(IND[i]);
        }
    }
    cout<<cost_apm<<'\n';
    cout<<n-1<<'\n';
    for(i=0;i<n-1;++i) cout<<X[apm[i]]<<' '<<Y[apm[i]]<<'\n';
    return 0;
}
