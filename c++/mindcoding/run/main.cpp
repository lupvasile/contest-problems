#include <iostream>

using namespace std;
int i,j,n,m,a[102][102],nr;
char c;
int main()
{
  cin>>n>>m;
for(i=1; i<=n; ++i)
    for (j=1; j<=m; ++j)
      {
        cin>>c;
        if(c=='.')
          {
            if(a[i-1][j]) a[i][j]=a[i-1][j];
            if(a[i][j-1]) if (a[i][j-1]>a[i][j]) a[i][j]=a[i][j-1];
            if(a[i][j] || ((i==1) && (j==1)))++a[i][j],nr=max(a[i][j],nr);
          }
      }
  cout<<nr;
  return 0;
}
