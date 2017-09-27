#include <fstream>

using namespace std;
ifstream f("adunare.in");
ofstream g("adunare.out");
int main()
{
    int a,b;
    f>>a>>b;
    g<<a+b;
    return 0;
}
