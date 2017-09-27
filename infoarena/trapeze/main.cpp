#include <iostream>
#include <fstream>

using namespace std;

ifstream f("trapeze.in");
ofstream g("trapeze.out");

#define cout g
#define nrcif 200
int k,descomp[30];
int n[nrcif];
int prim[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool comp(int a[nrcif],int b[nrcif])//true daca a<b
    {
    if(a[0]<b[0]) return true;
    if(a[0]>b[0]) return false;
    for(int i=a[0]; i; --i) if(a[i]>b[i]) return false;
    return true;
    }
void inmult(int a[nrcif],int x)
    {
    int i,t(0);
    for(i=1; i<=a[0]; ++i)
        {
        a[i]=a[i]*x+t;
        t=a[i]/10;
        a[i]%=10;
        }
    while (t)
        {
        ++a[0];
        a[a[0]]=t%10;
        t/=10;
        }
    }
void compara(int l)//compara solutia minima cu ce am acuma
    {
    int x[nrcif],i,s(1),d;
    for(i=0; i<nrcif; ++i) x[i]=0;
    x[0]=x[1]=1;
    for(int i=1; i<=l; ++i,++s) for(d=descomp[i]; d>1; --d)
            {
            inmult(x,prim[s]);
            }
    if(comp(x,n))
        {
        n[0]=x[0];
        for(; x[0]; --x[0]) n[x[0]]=x[x[0]];
        }
    }

void back(int l,int k)
    {
    int v,i;
    if(k==1)
        {
        compara(l-1);
        return;
        }
    for(i=2; i<=k; ++i) if(k%i==0)
            {
            descomp[l]=i;
            back(l+1,k/i);
            }
    }
void inf()
    {
    n[0]=nrcif-1;
    for(int i=1; i<nrcif; ++i) n[i]=9;
    }

int main()
    {
    f>>k;
    inf();
    back(1,k);
    for(; n[0]; --n[0]) cout<<n[n[0]];
    return 0;
    }
