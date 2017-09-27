#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream f("gauss.in");
ofstream g("gauss.out");

#define cout g
#define foor(i,a,b) for(i=a;i<=b;++i)
#define eps 0.00000001
int gI();

int n,m,l,k,u;
double A[320][320],X[320];
int i,j;

int main()
{
    f>>n;//=gI();
    f>>m;//=gI();
    foor(i,1,n)
    foor(j,1,m+1)
    f>>A[i][j];//=gI();
    i=j=1;
    while (i<=n && j<=m)
    {

        for(k=i; k<=n; ++k) if(A[k][j]!=0)//if(A[k][j]>eps || A[k][j]<-eps)
                                                break;

        if(k==n+1)
        {
            ++j;
            continue;
        }
        if(k!=i) foor(l,1,m+1) swap(A[i][l],A[k][l]);

        foor(l,j+1,m+1) A[i][l]/=A[i][j];

        A[i][j]=1;

        foor(u,i+1,n)
        {
            foor(l,j+1,m+1) A[u][l]-=A[u][j]*A[i][l];
            A[u][j]=0;
        }
        ++i,++j;
    }

    for(i=n; i; --i)
        for(j=1; j<=m+1; ++j)
            //if(A[i][j]!=0)
            if(A[i][j]>eps || A[i][j]<-eps)
            {
                if(j==m+1)
                {
                    cout<<"Imposibil";
                    return 0;
                }

                X[j]=A[i][m+1];
                foor(k,j+1,m) X[j]-=X[k]*A[i][k];
                break;
            }
    cout<<fixed<<setprecision(8);
    foor(i,1,m) cout<<X[i]<<' ';
    return 0;
}



//<parsare>
#define maxb 8192
char buf[maxb];
int ptr(maxb);
int gI()
{
    int nr=0,semn=1;
    while ((buf[ptr]<'0' || buf[ptr]>'9') && buf[ptr]!='-')
        if(++ptr>=maxb)
        {
            f.read(buf,maxb);
            ptr=0;
        }
    if(buf[ptr]=='-')
    {
        semn=-1;
        if(++ptr>=maxb)
        {
            f.read(buf,maxb);
            ptr=0;
        }
    }
    while (buf[ptr]>='0' && buf[ptr]<='9')
    {
        nr=nr*10+buf[ptr]-'0';
        if(++ptr>=maxb)
        {
            f.read(buf,maxb);
            ptr=0;
        }
    }
    return nr*semn;
}
// </parsare>
