#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main()
{
    freopen("pegals.in","r",stdin);
    freopen("pegals.out","w",stdout);

    scanf("%d",&n);
    cout<<"3\n";
    cout<<"1 "<<(n-1)/2<<' '<<n-n%2;
    return 0;
}
