#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
ifstream f("culori3.in");
ofstream g("culori3.out");
int n,a[3000],m,i,j,aux;
int main()
    {
    f>>n;
    //n=5000;
    if (n==1) g<<5;
    else if (n==2) g<<8;
    else
        {
        if (n % 2==0) a[1]=8,a[0]=1;
        else a[1]=4,a[2]=1,a[0]=2;
        for (i=1; i<=n/2-1; i++)
            {
            m=0;
            for (j=1; j<=a[0]; j++)
                {
                aux=a[j];
                a[j]=(a[j]*3+m)%10;
                m=(aux*3+m)/10;
                }
            if (m>0) a[++a[0]]=m;
            }
        for(; a[0]; a[0]--)g<<a[a[0]];
        g.close();
        }
    return 0;
    }
