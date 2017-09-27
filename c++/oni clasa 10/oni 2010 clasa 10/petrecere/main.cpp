#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("petrecere.in");
ofstream g("petrecere.out");

#define cout g

int n;
int fi_2[3002],fi_1[3002],fi[3002];//f[i-2],f[i-1],f[i]
int t_adunare,t_inmultire,c,j;
int main()
{
    f>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<2;
        return 0;
    }

    fi_2[0]=1;
    fi_2[1]=1;
    fi_1[0]=1;
    fi_1[1]=2;
    for(int i=3;i<=n;++i)
    {
        t_inmultire=0;
        t_adunare=0;
        fi[0]=0;
        for(j=1;j<=fi_2[0] || t_inmultire;++j)
        {
            c=fi_2[j]*(i-1)+t_inmultire;
            t_inmultire=c/10;
            c%=10;
            fi[++fi[0]]=fi_1[j]+c+t_adunare;
            t_adunare=fi[fi[0]]/10;
            fi[fi[0]]%=10;
        }
        for(;j<=fi_1[0];++j)
        {
            fi[++fi[0]]=fi_1[j]+t_adunare;
            t_adunare=fi[fi[0]]/10;
            fi[fi[0]]%=10;
        }
        while (t_adunare) fi[++fi[0]]=t_adunare%10,t_adunare/=10;
        memcpy(fi_2,fi_1,sizeof(fi_1));
        memcpy(fi_1,fi,sizeof(fi));
    }
    for(int i=fi[0];i;--i)cout<<(int)fi[i];
    return 0;
}

/*int nr_sol,b[200];
bool valid(int k)
{
    for(int i=1; i<k; ++i)
    {
        if(b[i]==k) return b[k]==i;
        if(b[k]==i) return b[i]==k;
    }
    for(int i=1; i<k; ++i) if(b[k]==b[i]) return false;
    return true;
}
void back(int k)
{
    int i;
    if(k==n+1)
    {
        ++nr_sol;
        for(i=1; i<=n; ++i) cout<<b[i]<<' ';
        cout<<"\n";
    }
    else
        for(i=1; i<=n; ++i)
        {
            b[k]=i;
            if(valid(k)) back(k+1);
        }
}
*/
