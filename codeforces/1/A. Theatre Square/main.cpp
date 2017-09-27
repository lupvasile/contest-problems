#include <iostream>

using namespace std;

int n,m,a;

int main()
{
    cin>>n>>m>>a;
    cout<<1ll*((n-1)/a+1)*((m-1)/a+1);
    return 0;
}
