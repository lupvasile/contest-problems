#include <iostream>
#include <cstdio>
using namespace std;

int n,k;
double p;

double dist(int n)
{
    if(n<=2) return n*k/p;
    return (k/(p*(2*n-3)))+dist(n-1);
}

int main()
{
    freopen("desert.in","r",stdin);
    freopen("desert.out","w",stdout);

    scanf("%d %d %lf",&n,&k,&p);
    p/=100;
    printf("%f",dist(n));
    return 0;
}
