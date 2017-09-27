#include<iostream>
#include<fstream>
using namespace std;
// binsrc inseamna cautare binara
ifstream f("calcule.in");
ofstream g("calcule.out");
int s[100001],n,k,i,c(0),j,v[100001],l,r[50001];
int binsrc(int ss,int d, int x)
{
int m;
    while (ss<=d)
        {
        m=(ss+d) /2;
        if (v[m]==x)
            {
            d=0;
            ss=m;
            while(v[ss]==x) ss++;
            }
        else
        if (x<v[m]) ss=m+1;
        else d=m-1;
        }
if (l<ss) l=ss;
return ss;
}
int main()
{
f>>n>>k;
for(i=0;i<=n;i++)v[i]=-1;
for(i=1;i<=n;i++)
    {
    f>>s[i];
    v[binsrc(1,l,s[i])]=s[i];
    s[i]=(s[i]%k +s[i-1])% k ;
    r[s[i]]++;
    }
c=r[0];
for(i=0;i<=k;i++) c=c+r[i]*(r[i]-1)/2;

g<<l<<"\n"<<c%20011;

g.close();

    return 0;
}
