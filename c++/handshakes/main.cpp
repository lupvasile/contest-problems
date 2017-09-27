#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream f("handshakes.in");
ofstream g("handshakes.out");

string a;
int nr_R,swaps,time,wait;
int main()
{
    cin>>a;
    int i(0);
    while (a[i]=='L') ++i;
    for(;i<=a.length(); ++i)
    {
        if(a[i]=='L')
        {
            swaps+=nr_R;
            time=nr_R+wait;
            wait++;
        }
        else {
            ++nr_R;
            if(wait) --wait;
        }
    }
    cout<<time<<' '<<swaps;
    return 0;
}
