#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int t,a,b;
void cmmmc(int a,int b)
{
    int d=a,i=b,r=0;
    do
    {
        r=d % i;
        d=i;
        i=r;
        }
        while (r);
   if (d==1) g<<0;
   else g<<d;

}
int main()
{
    f>>a>>b;
    cmmmc(a,b);
    g.close();
    return 0;
}
