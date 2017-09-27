#include <iostream>

using namespace std;

int s[60];
int n;
char c;
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>c;
        s[i]=c-'0';
        if(s[i]!=4 && s[i]!=7) {cout<<"NO";return 0;}
        if(i) s[i]+=s[i-1];
    }
    if(s[n/2-1]!=s[n-1]-s[n/2-1]) cout<<"NO";
    else cout<<"YES";
    return 0;
}
