#include <iostream>
#include <fstream>
using namespace std;

ifstream f("comori.in");
ofstream g("comori.out");

int n,px,py,d,p;
int depl[8][2]={ {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };

int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>d>>p;
        --d;
        px+=p*depl[d][0];
        py+=p*depl[d][1];
    }
    g<<px<<' '<<py;
    return 0;
}
