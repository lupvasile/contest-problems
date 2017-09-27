#include<fstream>
#include<iostream>
using namespace std;
int n,a[9];
ifstream f("permutari.in");
ofstream g("permutari.out");
bool valid(int k)
{
    for (int i=1;i<k;i++) if (a[k]==a[i]) return false;
    return true;
}
void back(int k)
{   int i;
    for (i=1;i<=n;i++)
    {
        a[k]=i;
        if (valid(k)) if (k==n) {
            for (int j=1;j<=n;j++) g<<a[j]<<" ";
            g<<"\n";
            }
        else back(k+1);
    }

}

int main()
{
    f>>n;
    back(1);
    g.close();
    return 0;
}
