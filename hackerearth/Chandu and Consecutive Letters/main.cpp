#include <iostream>

using namespace std;

int n;
string s;

int main()
{
    int i;
    cin>>n;
    for(;n;--n)
    {
        cin>>s;
        for(i=0;i<s.length();++i)
            if(i==0 || i && s[i]!=s[i-1]) cout<<s[i];
        cout<<'\n';
    }
    return 0;
}
