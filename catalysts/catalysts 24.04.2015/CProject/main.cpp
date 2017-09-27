#include <iostream>

using namespace std;

int i,nr;

int main()
{
    cout << "GET_NUMBER" << endl;
    cin >> nr;

    cout << "MOVE ";
    for(i=1;i<=nr;i+=2) cout<<i<<' '<<"0 ";
    cout.flush();
    cout << "EXIT" << endl;

    return 0;
}
