#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");
#define cout g
string a,b;
int c(-1),l,v[1001],i,nr,n;
int main()
{
f>>a>>b;
n=string::npos;
while ((c=b.find(a,c+1))!=n)
{
    if(nr<1000) v[++l]=c;
    ++nr;
}
cout<<nr<<'\n';
for(i=1;i<=l;++i)cout<<v[i]<<' ';
    return 0;
}
