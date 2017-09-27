#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fi("punti.in");
ofstream fo("ounti.out");
int n, m;
int i,x,y;
vector <int> AD[100];
vector <int> :: iterator it;
int VIZ[100];
void df(int v, int x, int y)
{
    vector <int> :: iterator it;
    int nod;
    VIZ[v]=1;
    for( it=AD[v].begin(); it!=AD[i].end(); it++)
    {
        nod=*it;
        if(!((v==x && nod==y)||(v==y && nod==x)) && VIZ[nod]==0)
            df(nod,x,y);
    }
}
int conex(int x, int y)
//verifica daca gragul este conexx
{
    for(i=1; i<=n; i++)
        VIZ[i]=0;
    df(1,x,y);
    for(i=1; i<=n; i++)
        if(VIZ[i]==0)
            return 0;
    return 1;
}
int main()
{
    fi>>n>>m;
    for(i=1; i<=m; i++)
    {
        fi>>x>>y;
        AD[x].push_back(y);
        AD[y].push_back(x);
    }
    for(i=1; i<=n; i++)
    {
        for(it=AD[i].begin();it!=AD[i].end();it++)
        if(!conex(i,*it))
        if(i<*it)
        cout<<i<<" "<<*it<<"\n";
    }
    fi.close();
    fo.close();
    return 0;
}
