#include <iostream>
#include <fstream>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("v2d.in");
ofstream fout("v2d.out");
/// ////////////////////////////////

void read();

#define nmax 502
#define inf 0x3f3f3f3f

int p[nmax][nmax],pmax[nmax][nmax],much_wow[nmax][nmax];
int n,day,mod;

void new_doge()
{
    int i,j;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            pmax[i][j]=-inf;
}

void next_doge(int x)
{
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            p[i][j]=x+1 + (p[i][j] + x*pmax[i][j]) % mod;
}
int main()
{
    read();

    int i,j,d,pi,pj,add_i,add_j,start_i,start_j,finish_i,finish_j;
    for(d=1; d<=day; ++d)
    {
        new_doge();

        for(pi=0; pi<2; ++pi)
            for(pj=0; pj<2; ++pj)
            {
                add_i=2*(1-pi)-1;
                add_j=2*(1-pj)-1;

                start_i=pi*(n+1) + add_i;
                start_j=pj*(n+1) + add_j;

                finish_i=(1-pi)*(n+1);
                finish_j=(1-pj)*(n+1);

                for(i=start_i; i!=finish_i; i+=add_i)
                    for(j=start_j; j!=finish_j; j+=add_j)
                    {
                        much_wow[i][j]=max(much_wow[i-add_i][j],much_wow[i][j-add_j]);
                        pmax[i][j]=max(pmax[i][j],much_wow[i][j] - add_i*i - add_j*j);
                        much_wow[i][j]=max(much_wow[i][j],p[i][j] + add_i*i + add_j*j);
                    }
            }

        next_doge(d);

    }

    int res=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            res=(res + p[i][j])%mod;

    cout<<res;
    return 0;
}

void read()
{
    int i,j;
    fin>>n>>day>>mod;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            fin>>p[i][j];

    for(i=0; i<=n+1; ++i) much_wow[0][i]=much_wow[n+1][i]=much_wow[i][0]=much_wow[i][n+1]=-inf;
}
