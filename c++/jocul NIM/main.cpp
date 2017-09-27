#include <iostream>
#include <fstream>
using namespace std;
#define cout g
ifstream f("nim.in");
ofstream g("nim.out");
int n,s,t,x;
int main()
{
    f>>t;
    for(; t; --t)
    {
        f>>n;
        s=0;
        for(; n; --n)
        {
            f>>x;
            s^=x;
        }
        if(s) cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
