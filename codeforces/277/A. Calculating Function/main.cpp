#include <iostream>

using namespace std;

long long n;

int main()
{
    cin>>n;
    if(n&1)
    {
        cout<<(n>>1)-n;
    }
    else cout<<(n>>1);
    return 0;
}
