/*problema lgput de pe infoarena
problema cere sa calc n la puterea p modulo 1999999973

daca as face cele p inmultiri, alg ar avea complexitatea O(p)

exista o solutie in O(log p) care se bazeaza pe descompunerea in baza 2 a lui p.
mai precis p poate fi scris ca o suma de genul x0*2^0+x1*2^1+...+xh*2^h, unde h reprezinta nr de cifre din desc in baza 2
valorile x0, ...xh pot fi din multimea 0 sau 1.
in loc sa descompunem p in baza 2, vedem daca bitul i este 1 si in acest caz inmultim cu puterea respectiva a lui n.
Chiar daca este setat sau nu trebuie calculata urmatoarea putere a lui 2, adica de la n^(2^i) trebuie trecut la n^(2^(i+1))
*/

#include<fstream>
#define max 1999999973

using namespace std;

int main()
{
    ifstream fin("lgput.in");
    ofstream fout("lgput.out");
    unsigned long long n, rez=1,p;
    int i;
    fin>>n>>p;
    for(i=0;(1<<i)<=p;i++)//i va merge numai pana la ce amai mare putere a lui 2 din desc in baza 2
    {
        //verificam daca bitul i din desc lui p are valoarea 1
        //in caz afirmativ la rez inmultim n din acel moment
        //facem direct modulo max
        if(((1<<i)&p)!=0)
            rez=(rez*n)%max;
        //eu trebuie sa am calculate n^2 la pasul 0, n^4 la pasul 1, n^8 la pasul 2 ....n^2^i la pasul i-1
        n=(n*n)%max;
    }
    fout<<rez;
    return 0;
}



/*

#include <iostream>
#include <fstream>
#include <ext/numeric>
#include <cmath>
using namespace std;
using namespace __gnu_cxx;
long long n,p;
#define mod 1999999973
long long powy(long long x,long long k)
{   if (k==0) return 1;
    if (k&1) return (x*powy(x*x%mod,(k-1)/2))%mod;
    else return (powy(x*x%mod,k/2))%mod;
}
int main()
{
ifstream f("lgput.in");
ofstream g("lgput.out");
f>>n>>p;
g<<power(n%mod,p)%mod;
    return 0;
}

*/
