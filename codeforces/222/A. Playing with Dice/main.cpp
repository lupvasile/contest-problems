#include <iostream>
#include <cmath>
using namespace std;

int p1,p2,d,a,b;

int main()
{
    cin>>a>>b;
    for(int i=1;i<=6;++i) if(abs(i-a)<abs(i-b)) ++p1;
    else if (abs(i-a)>abs(i-b)) ++p2;
    else ++d;
    cout<<p1<<' '<<d<<' '<<p2;
     return 0;
}
