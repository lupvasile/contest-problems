#include <iostream>

using namespace std;

#define nmax 110
#define foor(i,a,b) for(i=a;i<=b;++i)


bool b[nmax][nmax],a[nmax][nmax],l[nmax],c[nmax];
int i,j,n,m,x;

int main()
{
    cin>>n>>m;
      foor(i,1,n)
    foor(j,1,m) a[i][j]=1;
    foor(i,1,n)
    foor(j,1,m)
    {
        cin>>b[i][j];
        if(!b[i][j])
        {
            foor(x,1,m) a[i][x]=0;
            foor(x,1,n) a[x][j]=0;
        }
    }

    foor(i,1,n)
    foor(j,1,m)
    {
        l[i]=l[i] || a[i][j];
        c[j]=c[j] || a[i][j];
    }
    foor(i,1,n)
    foor(j,1,m)
    if(b[i][j]!=(l[i]||c[j]))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    foor(i,1,n)
    {
        foor(j,1,m) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
