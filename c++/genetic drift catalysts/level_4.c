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
    int el1,el2;
} a[1000];
inline bool cmp(rrr a,rrr b)
{
    return a.el1<b.el1;
}
bool level1()
{
    a[0].el1=0;
    foor(i,0,n-1)
    foor(j,i+1,n-1)
    {
        if (v[i]*v[j]<0 || (v[i]*v[j]==0 && v[i]+v[j]<0)) if (abs(abs(v[i])-abs(v[j]))==1)
            {
                a[0].el1++;
                a[a[0].el1].el1=v[i];
                a[a[0].el1].el2=v[j];
            }
    }
    if a[0].el1>0 return true;
    else return false;
}
void level2()
{
    if (x+y==1)
    {
        reverse(&v[px],&v[py]);
        foor(i,px,py-1) v[i]=-v[i];
    }
    else
    {
        reverse(&v[px+1],&v[py+1]);
        foor(i,px+1,py) v[i]=-v[i];
    }
}
void level3()
{
    level2();
    level1();
    cout<<a[0].el1;
}
bool exista_perechi(int v[1000])
{
    foor(i,0,n-1)
    foor(j,i+1,n-1)
        if (v[i]*v[j]<0 || (v[i]*v[j]==0 && v[i]+v[j]<0)) if (abs(abs(v[i])-abs(v[j]))==1)
            return true;
        else return false;
}
void gaseste_aia_mai_mare()
{
    int i,h,maxx(-1),aux[1000];
    foor(h,1,a[0].el1){
    foor(i,0,n-1) aux[i]=v[i];
    if (a[h].el1+a[h].el2==1)
    {
        reverse(&aux[],&v[py]);
        foor(i,px,py-1) v[i]=-v[i];
    }
    else
    {
        reverse(&v[px+1],&v[py+1]);
        foor(i,px+1,py) v[i]=-v[i];
    }

}
void level4()
{
    while (level1())
    {
        gaseste_aia_mai_mare();
        level2();
    }
}

int main()
{
    foor(h,1,3)
    {
        f>>n;
        foor(i,0,n-1)
        {
            f>>v[i];
        }
        //level1();
        //sort(a+1,a+a[0].el1+1,cmp);
        /*cout<<a[0].el1;
        foor(i,1,a[0].el1)
        {
            cout<<' '<<a[i].el1<<' '<<a[i].el2;
        }*/
        //******************************************/

        //level 2
        f>>x>>px>>y>>py;
        //level2();
        //foor(i,0,n-1)cout<<v[i]<<' ';
        //level3()

        cout<<'\n';
    }
    return 0;
}
