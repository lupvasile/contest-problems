#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
vector <int> v[100];
int n,m,a,b,i,p,it,j;
int color[100],spouse[100];
int parinti[100],viz[100];
vector <int> A,B;
int main()
{
    f>>n>>m>>p;
    for(i=1;i<=p;i++)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n+m;i++)
        color[i]=spouse[i]=0;
    while(1)
    {
        //search for an a-path
        for(i=1;i<=n+m;i++) parinti[i]=viz[i]=0;
        for(i=1;i<=n;i++)
            if(color[i]==0)
            {
                A.push_back(i);
                viz[i]=1;
            }
        for(it=0;i<A.size();i++)
        {
            for(j=0;j<v[A[i]].size();j++)
            {
                if(viz[v[A[i]][j]]==0)
                {
                    viz[v[A[i]][j]]=1;
                    B.push_back(v[A[i]][j]);
                }
            }
        }

    }

    return 0;
}
