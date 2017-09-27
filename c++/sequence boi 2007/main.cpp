#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("sequence.in");
ofstream g("sequence.out");

#define cout g
#define inf 1000000010

int n,a,l;
vector <int> v;//stiva
unsigned long long cost;

int main()
{
    f>>n;
    v.resize(n+2);
    v[0]=inf;
    for(;n;--n)
    {
        f>>a;
        while (a>v[l])
        {
            cost+=min(v[l-1],a);
            --l;
        }
        v[++l]=a;
    }
    a=inf;
    while (l>1)
        {
            cost+=v[l-1];
            --l;
        }
    cout<<cost;

    return 0;
}
