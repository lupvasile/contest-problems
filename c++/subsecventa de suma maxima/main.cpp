#include <iostream>
#include <fstream>
using namespace std;

ifstream f("ssm.in");
ofstream g("ssm.out");
int sum(-2147483647),n,i,s,in,sf,sumamax,pozcurent;
int main()
    {
        sumamax=sum;
    f>>n;
    for(i=1; i<=n; i++)
        {
            f>>s;
            if (sum<0) sum=s,pozcurent=i;
            else sum+=s;
            if (sum>sumamax) sumamax=sum,in=pozcurent,sf=i;
        }
    g<<sumamax<<" "<<in<<" "<<sf<<"\n";
    return 0;
    }
