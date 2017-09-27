#include <iostream>
#include <fstream>
using namespace std;

ifstream f("xyz.in");
ofstream g("xyz.out");
int x,y,z;
#define cout g
int main()
{
    f>>x>>y>>z;
    cout<<y;
    for(--x;x;--x) cout<<z;
    return 0;
}
