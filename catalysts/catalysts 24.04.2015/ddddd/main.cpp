#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int i = 0; i <= 360; i++)
    {
        int x = 180 * sin((double)i * 3.14 / 180) - 300;
        int y = 180 * cos((double)i * 3.14 / 180) - 300;

        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}
