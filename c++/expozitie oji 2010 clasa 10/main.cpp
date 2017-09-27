#include <iostream>
#include <fstream>
using namespace std;
#define FOR(i,a,b) for (i=a;i<=b;i++)
#define foor(i,a,b) for(i=a;i<=b;i++)
#define poz llb[k][0]
#define cout g
ifstream f("expozitie.in");
ofstream g("expozitie.out");
int n,d,k,i,la[500][200],lb[500][200],nr,kkk,r,nn;
void afisare(int a[][200],int k)
    {
    int k2;
    for(k2=a[k][0]; k2; k2--) cout<<a[k][k2];
    }
void bigsum(int k,int lla[][200], int llb[][200])
    {
    int h,minte(0),maxx(max(lla[k][0],lla[k-1][0]));
    poz=1;
    while (llb[k][0]<=maxx)
        {
        llb[k][poz]=lla[k-1][poz]+lla[k][poz]+minte;
        minte=llb[k][poz] / 10;
        llb[k][poz] %=10;
        poz++;
        }
    poz--;
    if (minte)
        {
        poz++;
        llb[k][poz]=minte;
        }

    }
void back(int k,int last)
    {
    int i;
    if (k<=n)
        {
        FOR(i,last,d) if (k==n) nr++;
        else back(k+1,i);
        }

    }
int main()
    {
    f>>n>>d>>kkk;
    n-=d*kkk;
    if (n<0) cout<<0;
    else if (n==0) cout<<1;
    else
        {
        /*back(1,1);
        cout<<nr;
        asta ii pentru 50 puncte
        */
        r=n+1;
        nr=r+d-1;
        la[1][0]=1;
        la[1][1]=1;
        //cout<<r<<"\n";
        foor(i,2,nr-1)
            {
            foor(k,1,i) bigsum(k,la,lb);
            i++;
            foor(k,1,i) bigsum(k,lb,la);
            }
        if (nr % 2==0)
            {
            foor(k,r,r) bigsum(k,la,lb);
            afisare(lb,r);
            }
        else
            {
            k=r;
            afisare(la,r);
            }
        }
    return 0;
    }
