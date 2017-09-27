#include <iostream>
#include <fstream>

using namespace std;

ifstream f("alo.in");
ofstream g("alo.out");

#define cout g

int n,e,nr,d;

int main()
{
    f>>e>>n;
    for(;n;--n)
    {
        f>>nr>>d;
        if(nr%10==5)
        {
            if(nr/10000==1) e-=2*d;
            else e+=d;
        }
    }
    cout<<e;
    return 0;
}
