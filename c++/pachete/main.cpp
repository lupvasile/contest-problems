#include <fstream>
using namespace std;
ifstream f("pachete.in");
ofstream g("pachete.out");
 int n,d,ins,td(0),tins(0),minn(0);
int main()
{
    std::ios_base::sync_with_stdio(false);
    f>>n;
    for(;n;n--)
    {
        f>>ins>>d;
        td+=d;
        if(td-tins>minn) minn=td-tins;
        tins+=ins;
    }
    g<<minn;
    return 0;
}
