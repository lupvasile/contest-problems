#include <iostream>
#include <fstream>

using namespace std;

ifstream f("numere.in");
ofstream g("numere.out");
//#define cout g
int t,x,y;
bool win(int a,int b)
{
     if (a>b) swap(a,b);
     if (b%a==0) return 1;
     if (b<2*a) return 1-win(a,b-a);
     return 1;

    }

int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>x>>y;
        if (win(x,y)) cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}
