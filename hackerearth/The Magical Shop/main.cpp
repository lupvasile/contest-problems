#include <iostream>

using namespace std;

char s[100010],*p;
int x,mod,res;

int main()
{
    cin>>x>>mod;
    cin>>s;

    for(p=s;*p;++p)
    {
        if(*p=='1')
            res=(res+x)%mod;
        x=1ll*x*x%mod;
    cout<<res;
    }
    return 0;
}
