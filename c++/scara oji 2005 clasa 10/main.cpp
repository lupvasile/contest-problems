#include <iostream>
#include <fstream>
#include <iomanip>
#define cout g
using namespace std;
ifstream f("scara2.in");
ofstream g("scara2.out");
int n,h,p,m,sol[10],suma,sol_final[10],i;
double energie[10],minn(9900);
bool used[16];
void rezolva()
    {
    int i,l,suma,j;
    double ma,x;
        for(i=1; i<=n; i++)
        {
        x=energie[i-1]+sol[i];
        j=i-1;
        suma=sol[i]+sol[j];
        while(suma<=m && j)
            {
            ma=0;
            for(l=j; l<=i; l++) ma+=sol[l];
            ma=ma/(i-j+1);
            if (energie[j-1]+ma+p<x)x=energie[j-1]+ma+p;
            j--;
            suma+=sol[j];
            }
        energie[i]=x;
        }
    if(minn>energie[n])
        {
        minn=energie[n];
        for(i=1; i<=n; i++)sol_final[i]=sol[i];
        }
    }
void back(int k)
    {
    int i;
    //if (suma>h) return;
    for(i=1; i<=m; i++)
        if(!used[i])
            {
            sol[k]=i;
            used[i]=true;
            suma+=i;
            if (k==n-1 && suma<h) if(!used[h-suma])
                    {
                    //sol[n]=h-suma;
                    //rezolva();
                    }
            if(k<n-1 && suma<h) back(k+1);
            used[i]=false;
            suma-=i;
            }
    }
int main()
    {
    f>>h>>n>>m>>p;
    used[0]=true;
    m--;
    back(1);
    cout<<setprecision(2)<<fixed<<minn<<'\n';
    for(i=1; i<=n; i++) cout<<sol_final[i]<<' ';
    return 0;
    }



