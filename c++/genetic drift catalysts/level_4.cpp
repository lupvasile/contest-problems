#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
#define foor(i,a,b) for(i=a;i<=b;i++)
//#define cout g
int v[1000],n,i,j,h,x,px,y,py,aux;
struct rrr
    {
    int el1,el2,*p1,*p2;
    } a[1000];
inline bool cmp(rrr a,rrr b)
    {
    return a.el1<b.el1;
    }
bool exista_perechi()
    {
    a[0].el1=0;
    foor(i,0,n-1)
    foor(j,i+1,n-1)
        {
        if (v[i]*v[j]<0 || (v[i]*v[j]==0 && v[i]+v[j]<0)) if (abs(abs(v[i])-abs(v[j]))==1)
                {
                a[0].el1++;
                a[a[0].el1].el1=v[i];
                a[a[0].el1].p1=&v[i];
                a[a[0].el1].el2=v[j];
                a[a[0].el1].p2=&v[j];
                }
        }
    if a[0].el1>0 return true;
    else return false;
    }
void inverseaza(int x,int y,int *px,int *py)
    {
    if (x+y==1)
        {
        reverse(px,py);
        foor(i,0,py-px-1) *(px+i)=-*(px+i);
        }
    else
        {
        reverse(px+1,py+1]);
        foor(i,1,py-px) *(px+i)=-*(px+i);
        }
    }
void gaseste_scor_maxim()
    {
    int i,h,maxx(-1),aux[1000];
    foor(h,1,a[0].el1)
        {
        k=0;
        foor(i,0,n-1) aux[i]=v[i];
        `inverseaza(a[h].el1,a[h].el2,a[h].p1,a[h].p2)
        foor(i,0,n-1)
        foor(j,i+1,n-1)
        if (v[i]*v[j]<0 || (v[i]*v[j]==0 && v[i]+v[j]<0)) if (abs(abs(v[i])-abs(v[j]))==1) k++;
        if(k>maxx)
            {
            maxx=k;
            q=h;
            }
        }
    }
int main()
    {
    foor(h,1,1)
        {
        f>>n;
        foor(i,0,n-1)
            {
            f>>v[i];
            }
        while (exista_perechi())
            {
            gaseste_scor_maxim();
            inverseaza(a[q].el1,a[q].el2,a[q].p1,a[q].p2);
            }
        cout<<'\n';
        }
    return 0;
    }
