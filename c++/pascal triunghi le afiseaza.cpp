#include <iostream>
#include <fstream>
using namespace std;
#define foor(i,a,b) for(i=a;i<=b;i++)
#define poz llb[k][0]
//ifstream f("pascal.in");
//ofstream g("pascal.out");
int i,la[1000][1000],lb[1000][1000],nr,k,elem;
void afisare(int a[1000][1000])
    {
    int k,k2;
    foor(k,1,i)
        {
        for(k2=a[k][0]; k2; k2--) cout<<a[k][k2];
        cout<<" ";
        }
    cout<<"\n";
    }
void afisare_element(int a[1000][1000],int k)
    {
    int k2;
    for(k2=a[k][0]; k2; k2--) cout<<a[k][k2];
    cout<<" ";

    cout<<"\n";
    }
void bigsum(int k,int lla[][1000], int llb[][1000])
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
        lb[k][poz]=minte;
        }
    }
int main()
    {
    cin>>nr>>elem;
    la[1][0]=1;
    la[1][1]=1;
    i=1;
    //afisare(la);
    foor(i,2,nr-1)
        {
        foor(k,1,i) bigsum(k,la,lb);
        //afisare(lb);
        i++;
        foor(k,1,i) bigsum(k,lb,la);
        //afisare(la);
        //  cout<<"\n111111111\n";
        }
    if (nr % 2==0)
        {
        foor(k,1,i) bigsum(k,la,lb);
        afisare_element(lb,elem);
        //afisare(lb);
        }
    else afisare_element(la,elem);

    return 0;
    }
