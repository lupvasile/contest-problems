#include <iostream>
#include <fstream>
using namespace std;
ifstream f("piata.in");
ofstream g("piata.out");
#define foor(i,a,b) for(i=a;i<=b;i++)
int i,j,ti,tj,mi,mj,h,n,k;
long long int sum(0);
int suma_cifre(int k)
    {
    h=0;
    while (k)
        {
        h+=k%10;
        k/=10;
        }
    return h;
    }

int main()
    {
    f>>n;
    f>>ti>>tj>>mi>>mj;
    k=mj-tj+1;
    j=tj;
    foor(i,ti+1,mi)
        if (i>j)sum+=suma_cifre(n-(i-j)+1)*min(mi-i+1,k);
        else sum+=suma_cifre(-i+j+1)*min(mi-i+1,k);
    k=mi-ti+1;
    i=ti;
    foor(j,tj,mj)
        if (i>j)
        sum+=suma_cifre(n-(i-j)+1)*min(mj-j+1,k);
        else sum+=suma_cifre(-i+j+1)*min(mj-j+1,k);

    g<<sum;
    return 0;
    }s