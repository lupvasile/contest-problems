#include <iostream>
#include <cstdio>
using namespace std;

FILE *f=fopen("desert.in","r");
FILE *g=fopen("desert.out","w");

int n,k;
double p;
double dist(int n)
{
    if(n<=2) return n*k/p;
    else return k/((2*n-3)*p)+dist(n-1);
}
int main()
{double d;
    fscanf(f,"%d %d %Lf",&n,&k,&p);
    fclose(f);
    p=p/100;
    d=dist(n);
    fprintf(g,"%.3f",d);
    return 0;
}
