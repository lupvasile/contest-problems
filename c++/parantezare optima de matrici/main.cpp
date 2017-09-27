#include <iostream>
#include <fstream>
using namespace std;
#define foor(i,a,b) for(i=a;i<=b;++i)
#define cout g
#define inf 100000000000000000LL
ifstream f("podm.in");
ofstream g("podm.out");
long long i,n,j,k,d[502],w;
long long m[502][502];
int main()
{
    f>>n;
    foor(i,0,n) f>>d[i];
    foor(i,1,n-1) m[i][i+1]=d[i]*d[i-1]*d[i+1];
    foor(w,2,n-1) foor(i,1,n-w)
           {
               j=i+w;
            m[i][j]=inf;
            foor(k,i,j-1) m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+d[i-1]*d[k  ]*d[j]);
          //  cout<<i<<' '<<j<<' '<<m[i][j]<<'\n';
        }
    cout<<m[1][n];
    return 0;
}
