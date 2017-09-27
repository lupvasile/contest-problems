#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
/// ///////////////////////////

#define nmax 110
int a[nmax][nmax];

int main()
{
    int i,n,j,k;
    fin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            fin>>a[i][j];

    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                if(a[i][k] && a[k][j] && i!=j)
                    a[i][j]=a[i][j]>0 ? min(a[i][j],a[i][k]+a[k][j]):(a[i][k]+a[k][j]);

    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            cout<<a[i][j]<<" \n"[j==n];

    return 0;
}
