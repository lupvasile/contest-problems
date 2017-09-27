#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;
void cmmmc(int a,int b)
{
    int d=a,i=b,r=0;
    do
    {
        r=d % i;
        d=i;
        i=r;}
        while (r);
    g<<d<<'\n';

}
int main()
{
    f>>t;
    for (;t;t--) f>>a>>b,cmmmc(a,b);
    g.close();
    return 0;
}
