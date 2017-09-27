#include <iostream>

using namespace std;
int k,d,i;
int main()
    {
    cin>>k>>d;
    if(d>0)
        {
        cout<<d;
        for(i=1; i<=k-1; i++)cout<<0;
        }
    else if (k==1)cout<<0;
    else cout<<"No solution";

    return 0;
    }
