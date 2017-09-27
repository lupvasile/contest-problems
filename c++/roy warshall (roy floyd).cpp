#include<iostream>
#include<fstream>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int k,n,a[101][101],i,j;
int main()
{
f>>n;
for(i=1;i<=n;i++)
    for (j=1;j<=n;j++) f>>a[i][j];
for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (a[i][k] && a[k][j] && i!=j) if (a[i][j] > a[i][k]+a[k][j] || a[i][j]==0) a[i][j] = a[i][k]+a[k][j];
for(i=1;i<=n;i++){
    for (j=1;j<=n;j++) g<<a[i][j]<<" ";
    g<<"\n";
}
g.close();

    return 0;
}
