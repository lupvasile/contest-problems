#include <iostream>
#include <fstream>
#define cout g
using namespace std;

ifstream f("case1.in");
ofstream g("case1.out");

int n,gr[4],femei,copii,barbati,x;

int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>x;
        copii+=(x%10);
        x/=10;
        femei+=(x%10);
        x/=10;
        barbati+=(x%10);
        x/=10;
        ++gr[x];
    }
    cout<<gr[1]<<'\n'<<gr[2]<<'\n'<<gr[3]<<'\n'<<barbati<<'\n'<<femei<<'\n'<<copii;
    return 0;
}
