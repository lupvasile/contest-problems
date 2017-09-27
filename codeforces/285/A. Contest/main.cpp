#include <iostream>

using namespace std;

int a,b,c,d,m,v;

int main()
{
    cin>>a>>b>>c>>d;
    m=max(3*a/10,a-a*c/250);
    v=max(3*b/10,b-b*d/250);
    if(m>v) cout<<"Misha";
    if(m==v) cout<<"Tie";
    if(m<v) cout<<"Vasya";
    return 0;
}
