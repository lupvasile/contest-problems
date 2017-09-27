#include <iostream>

using namespace std;

#define nmax 103

int n,m,x;
int a[nmax][nmax];

int main()
{
    int i,j,ik,jk;
    cin>>n>>m>>x;
    for(i=0; i<n; ++i)
        for(j=0; j<m; ++j)
            cin>>a[i][j];

    n*=x;
    m*=x;

    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j) cout<<a[i/x][j/x]<<' ';
        cout<<'\n';
    }
    return 0;
}
