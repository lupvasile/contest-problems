#include <iostream>
#include <fstream>
using namespace std;
ifstream f("windows.in");
ofstream g("windows.out");

#define cout g

int n,r1,r2,s1,s2,clk,i,j,x,a[101][101],inchis[101];
struct {int x,y;}v[101];
void inchide(int k)
{  int i;
    if(!inchis[k])
        {
            for(i=1;i<=a[k][0];i++) inchide(a[k][i]);
            clk++;
            inchis[k]=1;
        }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>r1>>s1>>r2>>s2;
        for(j=1;j<i;j++)
            if (v[j].x<=r2 && v[j].x>=r1 && v[j].y<=s2 && v[j].y>=s1)
                    {
                        a[j][0]++;
                        a[j][a[j][0]]=i;
                    }
        v[i].x=r1;
        v[j].y=s2;
    }
    clk=0;
    inchide(1);
    cout<<clk;
    return 0;
}
