#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int n;

int main()
{
    cin>>n;
    for(; n; --n)
    {
        cin>>s;
        reverse(s.begin(),s.end());
        cout<<s<<'\n';
    }
    return 0;
}
