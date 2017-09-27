#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

ifstream f("mxl.in");
ofstream g("mxl.out");

#define cout g

int n,k,x,y,i,j;
long long a[42][42];
string v[42][42];

long long rezolva(int i,int j)
{
    if(a[i][j]) return a[i][j];
    if(v[i][j]=="") return 0;
    int nr1,nr2;
    long long res=0;
    string s=v[i][j];
    for(int t=1; t<s.length(); ++t)
    {
        nr1=nr2=0;
        while (isdigit(s[t])) nr1=nr1*10+s[t]-'0',++t;
            if (s[t]=='+' || t>=s.length()) res+=nr1;
            else
            {
                ++t;
                while (isdigit(s[t])) nr2=nr2*10+s[t]-'0',++t;
                res+=rezolva(nr1,nr2);
            }
    }
    a[i][j]=res;
    return res;
}
int main()
{
    f>>n>>k;
    for(; k; --k)
    {
        f>>x>>y;
        f>>v[x][y];
        if(v[x][y][0]!='=')
            a[x][y]=atoi(v[x][y].c_str());
    }
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            a[i][j]=rezolva(i,j);
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
