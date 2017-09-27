#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream f("codul.in");
ofstream g("codul.out");
string a,b;
string lcs[201][201];
int i,j;
int main()
{
    f>>a>>b;
    for(i=1;i<=a.length();i++)
    for(j=1;j<=b.length();j++)
    {
        if (a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+a[i-1];
        else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        //cout<<i<<' '<<j<<'\n';
    }
    //lcs[0][0]=a;
    //lcs[0][1]=b;
    //cout<<max(lcs[0][0],lcs[0][1]);
    g<<lcs[a.length()][b.length()];
    return 0;
}
