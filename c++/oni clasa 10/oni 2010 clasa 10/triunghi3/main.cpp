#include <iostream>
#include <fstream>

using namespace std;

ifstream f("triunghi3.in");
ofstream g("triunghi3.out");

#define cout g
#define nmax 1010

long long s,a[nmax][nmax],i,j,n,b[nmax][nmax];
long long suma_linie[nmax],suma_coloana[nmax],last[nmax],c;

int main()
{
    f>>n;
    for(s=2; s<=n+1; ++s)
        for(i=s-1; i; --i)
        {
            f>>a[i][s-i];
            b[i][s-i]=a[i][s-i];
            if(s==n+1) last[s-i]=a[i][s-i];
        }
    /*for(i=1;i<=n;++i)
    {
        for(j=1;j<=n-i+1;++j) cout<<a[i][j]<<' ';
        cout<<'\n';
    }*/
    for(s=n+1; s>=2; --s)
    {

        for(i=1; i<s; ++i)
        {
            j=s-i;
            c=(suma_coloana[j]+suma_coloana[j+1]+a[i][j]-b[n+1-j][j])*(n+1-s)
               +a[i][j+1]+a[i][j]+suma_coloana[j]*2-b[n+1-j][j];
            c=min(c,
                  (suma_linie[i]+suma_linie[i+1]+a[i][j]-b[i][n+1-i])*(n+1-s)
                  +a[i+1][j]+a[i][j]+suma_linie[i]*2-b[i][n+1-i]);
            //if(s==n+1)a[i][j]=0;
            //else
            a[i][j]=c;
        }
        for(i=1; i<s; ++i)
        {
           suma_linie[i]+=b[i][s-i];
           suma_coloana[s-i]+=b[i][s-i];

        }
      /* if(s==2) for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n-i+1; ++j) cout<<a[i][j]<<' ';
            cout<<"\n";
        }
        */
        //cout<<"asdfasdfasdfasdf\n";
    }

    cout<<a[1][1];
    return 0;
}
