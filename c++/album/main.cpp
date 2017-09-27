#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define For(i,a,b) for(i=a;i<=b;i++)
#define cout g
ifstream f("album.in");
ofstream g("album.out");
int h,hmax,maxx,n,k,i,j,a[50002],nr,scurt[1001],en[1001];
bool ok;
inline bool cmp(int a,int b)
    {
    return a<b;
    }
void rez(int i)
    {
    int j,h;
    bool ok;
    For(j,1,n)
        {
        en[i]=nr;
        ok=true;
        For(h,1,k) if (a[(i-1)*k+h]<=a[(j-1)*k+h]) ok=false;
        if (ok)
            {
            if(!en[j]) rez(j);
            else
                {
                en[i]=en[j];
                }
            if (scurt[i]<scurt[j]+1)
                {
                scurt[i]=scurt[j]+1;
                }
            }
        }
    }
int main()
    {
    f>>n>>k;
    For(i,1,n) For(j,1,k) f>>a[(i-1)*k+j];
    For(i,1,n) sort(a+(i-1)*k+1,a+1+i*k,cmp);
    For(i,1,n) if (!en[i])
        {
        nr++;
        rez(i);
        }
    maxx=0;
    cout<<nr-1;
//For(i,1,n) cout<<scurt[i]<<" ";
    return 0;
    }

