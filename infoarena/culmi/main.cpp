#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("culmi.in");
ofstream g("culmi.out");

#define cout g
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)


int n,k,p,i;
int v[110];
int res[300];
vector <int> descomp[110];



void scade(int x)
    {
    foor(it,descomp[x]) --v[*it];
    }

void comb(int n,int k)
    {
    int i;
    if(n-k<k) k=n-k;
    for(i=n-k+1; i<=n; ++i) foor(it,descomp[i]) ++v[*it];
    for(i=k; i>1; --i) scade(i);
    }

void mult(int v[],int x)
{
    int t=0,i;
    for(i=1;i<=v[0];++i)
    {
        v[i]=v[i]*x+t;
        t=v[i]/10;
        v[i]%=10;
    }
    while(t)
    {
        ++v[0];
        v[v[0]]=t%10;
        t/=10;
    }
}

int main()
    {
    f>>n>>k;
    for(i=1; i<=n; ++i) v[i]=i;

    for(i=2; i<=n; ++i)///descompunerea numerelor pana la n
        {
        if(v[i]>1)
            {
            for(p=i; p<=n; p+=i)  while(v[p]%i==0)
                    {
                    v[p]/=i;
                    descomp[p].push_back(i);
                    }
            }
        }

    for(i=1; i<=n; ++i) v[i]=0;
    comb(n,k);
    comb(n,k-1);
    scade(n);
    res[0]=res[1]=1;
    for(i=2; i<=100; ++i) while(v[i]--) mult(res,i);
    for(;res[0];--res[0]) cout<<res[res[0]];

    return 0;
    }
