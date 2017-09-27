#include<iostream>
#include<fstream>
using namespace std;
ifstream f("calcule.in");
ofstream g("calcule.out");
int s[100001],n,k,i,c(0),j,v[100001],l;
int binsrc(int ss,int d, int x)
{
int m;
    while (ss<=d)
        {
        m=(ss+d) /2;
        if (s[m]==x)
            {
            d=0;
            ss=m;
            while(s[ss]==x) ss++;
            }
        else
        if (x<s[m]) ss=m+1;
        else d=m-1;
        }
if (l<ss) l=ss;
return ss;
}
int main()
{
f>>n>>k;
for(i=1;i<=n;i++,v[i]=-1)
for(i=1;i<=n;i++)
    {
    f>>s[i];
    v[binsrc(1,,s[i])]=s[i];
    }
for (l=1;v[l]!=-1;l++);
cout<<l<<"\n"<<c%20011;

g.close();

    return 0;
}
