#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("sortaret.in");
ofstream gf("sortaret.out");

#define cout gf
int n,m,x,y,stiva[50001],l,grad[50001],lista[50001],ll,i,nod;
vector <int> g[50001];
vector <int>::iterator it;
int main()
{
   f>>n>>m;
   for(;m;m--)
   {
       f>>x>>y;
       g[x].push_back(y);
       grad[y]++;
   }
   for(i=1;i<=n;++i) if(grad[i]==0) stiva[++l]=i;
   while(l)
   {
       nod=stiva[l];
       --l;
       for(it=g[nod].begin();it!=g[nod].end();++it)
       {
           --grad[*it];
           if(grad[*it]==0) stiva[++l]=*it;
       }
        lista[++ll]=nod;
   }
   for(i=1;i<=ll;++i) cout<<lista[i]<<' ';
    return 0;
}
