#include <iostream>
#include <fstream>

using namespace std;
ifstream f("capete.in");
ofstream g("capete.out");

int main()
{
    int n;
    f>>n;
    g<<n*5;
    return 0;
}
