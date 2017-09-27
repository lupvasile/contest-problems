#include <iostream>
#include <fstream>

using namespace std;

ifstream f("bancomat.in");
ofstream g("bancomat.out");

#define cout g
int n,x;
long long s;

int main()
{
    f>>s>>n;
    for(;n;--n)
    {
        f>>x;
        if(x%10==2) s+=(x/10);
        else if(s>=(x/10))s-=(x/10);
    }
    cout<<s;
    return 0;
}
