#include <iostream>

using namespace std;
int n,k,f,t,x,maxx,i;
int main()
{   maxx=-999999999;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>f>>t;
        if (t>k) x=f-(t-k);
        else x=f;
        if (x>maxx) maxx=x;
    }
    cout<<maxx;
    return 0;
}
