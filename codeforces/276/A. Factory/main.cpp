#include <iostream>
#include <fstream>

using namespace std;

int d[100010],r,a,m;

int main()
{
    cin>>a>>m;
    while(d[r=a%m]==0)
    {
        if(r==0) {
            cout<<"Yes";
            return 0;
        }
        d[r]=1;
        a+=r;
    }
    cout<<"No";
    return 0;
}
