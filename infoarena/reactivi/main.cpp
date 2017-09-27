#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("reactivi.in");
ofstream g("reactivi.out");

#define cout g
#define minn first
#define maxx second

int n,i,ld(-200),nr;
pair <int, int> v[8100];


int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>v[i].minn>>v[i].maxx;
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
    {
        if(v[i].minn>ld)
        {
            ++nr;
            ld=v[i].maxx;
        }
        else ld=min(ld,v[i].maxx);
    }
    cout<<nr-1;
    return 0;
}
