#include <iostream>

using namespace std;

int n;
unsigned long long a,b,x,i;

int main()
{
    cin>>n;
    for(;n;--n)
    {
        cin>>a>>b;
        x=a;
        for(i=1;(x|i)<=b;i<<=1) x|=i;
        cout<<x<<'\n';
    }
    return 0;
}
