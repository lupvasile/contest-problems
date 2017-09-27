#include <iostream>

using namespace std;

string s;

int main()
{
    getline(cin,s);
    for(auto it:s)
    {
        if(it=='-' || it=='.') continue;
        if(it==',') cout<<' ';
        cout<<it;
    }
    return 0;
}
