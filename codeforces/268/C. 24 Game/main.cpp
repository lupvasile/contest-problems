#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    if(n<4) cout<<"NO";
    else
    {
        cout<<"YES\n";
        if(n&1)
        {
            cout<<"5 - 1 = 4\n";
            cout<<"4 - 2 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            for(int i=6; i<=n; i+=2)
            {
                cout<<i+1<<" - "<<i<<" = 1\n";
                cout<<"24 * 1 = 24\n";
            }
        }
        else
        {
            cout<<"1 * 2 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            for(int i=5; i<=n; i+=2)
            {
                cout<<i+1<<" - "<<i<<" = 1\n";
                cout<<"24 * 1 = 24\n";
            }
        }
    }
    return 0;
}
