#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("cerere.in");
ofstream g("cerere.out");

#define cout g

const int inf=200000;
int n;
int k[100001],nr[100001];
int i,a,b,radacina,sf,in,stiva[100001];
vector <int> v[100001],y;

void dfs(int nod)
{int i;
    stiva[++sf]=nod;
    nr[nod]=nr[stiva[sf-k[nod]]]+1;
    for(i=0;i<v[nod].size();i++) dfs(v[nod][i]);
    --sf;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++) f>>k[i];
    //for(i=1;i<=n;i++) if(k[i]) nr[i]=inf;
    for(i=1;i<n;i++)
    {
        f>>a>>b;
        v[a].push_back(b);
        nr[b]=1;
    }
    for(i=1;i<=n;i++)
    {
        if (nr[i]==0)radacina=i;
        nr[i]=0;
    }
    //cout<<radacina;
    dfs(radacina);
    for(i=1;i<=n;i++) cout<<nr[i]-1<<' ';

    return 0;
}
