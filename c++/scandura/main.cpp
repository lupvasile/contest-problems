#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream f("scandura.in");
ofstream g("scandura.out");

#define cout g

int n,m,x,i,lq1,lq2;
long long l,e,p,s;
long long q1[1000001],q2[1000001];
int main()
{
    f>>n>>m;
    p=m;
    while(p<n) p=p*m;
   for(i=0;i<=p-n;i++);
    for(;n;n--)
    {
        f>>q1[++i];
    }
    l1=i;
    l2=0;
    while (l1)
    {
        s=0;
        for(i=1;i<=m;i++)
        {

        }
        e+=s;
        q.push(-s);
    }*/
    cout<<e;
    return 0;
}
