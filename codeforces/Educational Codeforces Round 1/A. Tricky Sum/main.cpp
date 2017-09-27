#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(; t; --t)
    {
        long long n,scad;
        cin>>n;
        for(scad=1; scad<=n; scad<<=1);
        cout<<n*(n+1)/2-2*(scad-1)<<'\n';
    }
    return 0;
}
