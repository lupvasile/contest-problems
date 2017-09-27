#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cutie.in");
ofstream g("cutie.out");

#define cout g
#define nmax 500000
int t,n,m,k,x;
int i,deteriorat[nmax];
int pos,nr_bile_duble,nr_bile_impare;
//nr_bile_duble ii numaru de bile cu o distanta para si una impara
//pana la cea mai apropiata cutie rea(in stanga si in dreapta)
//nr_bile_impare "----" amandoua distantele impare "-----"
//ca iti trebe paritatea umarului total de mutari
int main()
{
    f>>t;
    deteriorat[0]=1;
    for(; t; --t)
    {
        nr_bile_duble=nr_bile_impare=0;
        f>>n>>k>>m;
        pos=0;
        for(i=1; i<=k; ++i) f>>deteriorat[i];
        deteriorat[k+1]=n;
        for(; m; --m)
        {
            f>>x;
            while (x>deteriorat[pos+1]) ++pos;
            if((deteriorat[pos+1]-deteriorat[pos])%2==1) ++nr_bile_duble;
            else if((x-deteriorat[pos])%2==1) ++nr_bile_impare;
        }

            if(nr_bile_duble%2==0 && nr_bile_impare%2==0)cout<<0;
            else cout<<1;


        //cout<<nr_bile_impare<<' '<<nr_bile_duble<<'\n';

    }
    return 0;
}
