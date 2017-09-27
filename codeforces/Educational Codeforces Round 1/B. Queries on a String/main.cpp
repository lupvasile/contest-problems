#include <iostream>

using namespace std;

char s[10010],aux[10010];
int l,r,k;

void movve()
{
    int len=r-l+1;
    int swif=k%len,i;

    for(i=l;i<=r;++i)
        aux[l+(i-l+swif)%len]=s[i];

    for(i=l;i<=r;++i)
        s[i]=aux[i];
}
int main()
{
    int q;
    cin>>s+1;
    cin>>q;
    for(;q;--q)
    {
        cin>>l>>r>>k;
        movve();
    }
    cout<<s+1;
    return 0;
}
