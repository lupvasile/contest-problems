#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int n,m,bb,a[1001],s[1001],q,p;
bool e[1000001];
int main ()
    {
        f>>n>>m;
        int i,j;
        for(i=1;i<=n;i++) f>>a[i];
        for (i=1;i<=m;i++)
            {
                f>>s[i];
                s[i]+=s[i-1];
                for (j=0;j<i;j++)
                    {
                        p=s[i]-s[j];
                        if (p<=1000000) if (!e[p]) e[p]=true;
                    }
            }
        for (i=1;i<=n;i++)if (e[a[i]]) bb++;
        g<<bb;
        g.close();
        return 0;
    }
