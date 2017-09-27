#include <iostream>
#include <fstream>

using namespace std;

ifstream f("permutari.in");
ofstream g("permutari.out");

int n,i,p[20],poz_start(1),nr,q,x,j;
bool folosit[20];
long long fact[20],s;
#define cout g
int main()
{
    f>>n;
    for(i=1; i<=n; ++i) f>>p[i];
    fact[0]=1;
    for(i=1; i<=n; ++i) fact[i]=fact[i-1]*i;
    for(i=1; i<n; ++i)
    {
        nr=0;
        for(j=1; j<p[i]; ++j) if(!folosit[j]) ++nr;
        poz_start+=nr*fact[n-i];
        folosit[p[i]]=true;
        //for(j=i+1; j<=n; ++j) if (p[i]<p[j]) --p[j];
    }
    f>>q;
    for(;q;--q)
    {
        f>>x;
        x+=poz_start;
        s=1;
        for(i=1;i<=n;++i) folosit[i]=false;
        for(i=1;i<=n;++i)
        {
            nr=0;
            while (s<=x) s+=fact[n-i],++nr;
            s-=fact[n-i],--nr;
            for(j=1;nr;++j) if(!folosit[j]) --nr;
            while (folosit[j]) ++j;
            folosit[j]=true;
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
