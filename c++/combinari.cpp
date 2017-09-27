#include <iostream>
#include<fstream>
using namespace std;
int n,p,a[19];
ifstream f("combinari.in");
ofstream g("combinari.out");
void back(int k)
{  int i;
    for(i=a[k-1]+1;i<=n;i++)
        {
        a[k]=i;
        if (k==p)
                        {   int j;
                            for (j=1;j<=p;j++) g<<a[j]<<" ";
                            g<<"\n";
                        }
                        else back(k+1);
            }
}
int main()
{

    a[0]=0;
    f>>n>>p;
    back(1);
    g.close();
    return 0;
}
