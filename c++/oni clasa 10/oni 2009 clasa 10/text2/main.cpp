#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("text2.in");
ofstream g("text2.out");

#define cout g
#define mod  1000003
#define inf 0x3f3f3f3f

int n,lg,pos(-1),p[221],i,h,k,stp;
char s[221];
int d[300][300];//d[i][j] in cate moduri fac 1..i in j cuvinte
int armonie[300][300],ant[300][300];
bool vocala(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}
void afis(int i,int k)
{
    if (k>1) afis(ant[i][k]-1,k-1);
    for(int j=ant[i][k]; j<=i; ++j) cout<<s[j];
    cout<<' ';
}
int main()
{
    f>>s+1;
    lg=strlen(s+1);
    for(i=1; i<=lg; ++i)
    {
        if (vocala(s[i])) pos=i;
        p[i]=pos;
    }
    f>>n;
    /*//cout<<lg;
    for(i=0;i<=lg;++i)  cout<<i<<' ';
    cout<<'\n';
    for(i=0;i<=lg;++i)  cout<<p[i]<<' ';*/
    memset(d,-1,sizeof d);
    memset(armonie,inf,sizeof armonie);
    d[0][0]=1;
    armonie[0][0]=0;
    for(i=1; i<=lg; ++i)
    {
        for(k=1; k<=i; ++k)
            for(h=p[i]; i-h<20 && h>=1; --h) if (d[h-1][k-1]>-1)
                {
                    d[i][k]=(max(d[i][k],0)+d[h-1][k-1])%mod;
                    if(armonie[i][k]>=armonie[h-1][k-1]+(i-h+1)*(i-h+1))
                    {
                        armonie[i][k]=armonie[h-1][k-1]+(i-h+1)*(i-h+1);
                        ant[i][k]=h;
                    }
                }
        //for(int t=1;t<=n;++t) cout<<d[i][t]<<' ';
        //cout<<'\n';
    }
    cout<<d[lg][n]<<'\n'<<armonie[lg][n]<<'\n';
    afis(lg,n);
    return 0;
}
