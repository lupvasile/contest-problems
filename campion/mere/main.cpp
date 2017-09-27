#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define nmax 210

int n,i,j,nr_mere;
struct mmm{int x,y,z,r;} mar[nmax];
vector <int> G[nmax];
bool viz[nmax];
void dp(int nod)
{
    viz[nod]=true;
    ++nr_mere;
    for(int i=0;i<G[nod].size();++i) if(!viz[G[nod][i]]) dp(G[nod][i]);
}

bool intersectie(mmm a,mmm b)
{
    int x,y;
    x=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    y=(a.r+b.r)*(a.r+b.r);
    return x<=y;
}

int main()
{
    freopen("mere.in","r",stdin);
    freopen("mere.out","w",stdout);

    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d%d%d",&mar[i].x,&mar[i].y,&mar[i].z,&mar[i].r);
        mar[i].z-=mar[i].r;
    }
    for(i=1;i<n;++i)
        for(j=i+1;j<=n;++j)
            if(intersectie(mar[i],mar[j]))
            {
             if(mar[i].z>mar[j].z) G[i].push_back(j);
             else G[j].push_back(i);
            }

    dp(1);
    printf("%d",nr_mere);
    return 0;

}
