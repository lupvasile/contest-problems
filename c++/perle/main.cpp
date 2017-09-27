#include <iostream>
#include <fstream>
using namespace std;

#define cout g
#define foor(i,a,b) for(i=a;i<=b;i++)

ifstream f("perle.in");
ofstream g("perle.out");

int n,l,v[10000];

void citeste_sir()
{
    int i;
    foor(i,0,l-1) f>>v[i];
}
int perlaB(int x);
int perlaC(int x);
int main()
{
    f>>n;
    for(; n; n--)
    {
        f>>l;
        if(l==1) citeste_sir(),cout<<"1\n";
        else
        {
            citeste_sir();
            if (perlaB(0)==l || perlaC(0)==l) cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}

int perlaB(int x)
{
    if(x<l)
        if(v[x]==2) return perlaB(x+1);
        else if (v[x]==1 && v[x+2]==3) return perlaC(x+4);
    return 0;
}

int perlaC(int x)
{
    if(x<l)
        if (v[x]==2) return x+1;
        else if (v[x]==1 && v[x+1]==2) return x+3;
        else if(v[x]==3) return perlaC(perlaB(x+1));
    return 0;
}
