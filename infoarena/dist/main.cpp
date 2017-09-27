#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
using namespace std;

ifstream f("dist.in");
ofstream g("dist.out");

#define cout g
#define nmax 510
#define cuvmax 105
#define lmax 20
#define inf 0x3f3f3f3f

stringstream ss;
char buf[nmax];
string p1[cuvmax];
int lp1,lp2,ls,i,lg2[cuvmax],slg2[cuvmax],x,lg1[cuvmax];
int dp[2][nmax],minn,nrop,op[2][nmax];
int j,k,d,add;
string s;

void read();

int det_lb(int i,int a,int b)
{
    int t=1,r;
    ++a;++b;
    for(;slg2[t]<b;++t);
    if(t>lp1) return t-lp1;
    return 0;

}

int dist(const char *s1,const char *s2,int k)
    {
    int d(0),i;
    for(i=0; i<k && s1[i];++i) d+=abs(s1[i]-s2[i]);
    if(i<k)
        for(; i<k; ++i) d+=abs(s2[i]-'@');
    else for(; s1[i]; ++i)d+=abs(s1[i]-'@');
    return d;
    }
int nr_operatii(int i,int a,int b)
{
    int nr(0),t(1),j;
    ++a;++b;
    for(j=a;j<=b;++j)
    {
        for(;slg2[t]<j ;++t);
        nr+=abs(t-i);
    }
    return nr;
}
int main()
    {
    read();
    for(j=ls-1; j>=0; --j) dp[x][j]=dp[x][j+1]+abs('@'-s[j]); //pt cuvintele vide in prop 1
    x=1;
    for(i=lp1; i; --i,x=x^1)
        {
        dp[x][ls]=dp[x^1][ls];
        for(j=lg1[i]-1; j>=0; --j) dp[x][ls]+=abs(p1[i][j]-'@'); //distanta pana la uvintele vide

        for(j=ls-1; j>=0; --j)
            {
            minn=nrop=inf;
            for(k=1; k<=20 && j+k-1<ls; ++k)
                {
                d=dist(p1[i].c_str(),s.c_str()+j,k)+dp[x^1][j+k];
                add=det_lb(i,j,j+k-1)*(ls-j-k);
                if(d<minn)
                    {
                    minn=d;
                    nrop=nr_operatii(i,j,j+k-1)+op[x^1][j+k]+add;
                    }
                else if(d==minn) nrop=min(nrop,nr_operatii(i,j,j+k-1)+op[x^1][j+k]+add);
                }
            dp[x][j]=minn;
            op[x][j]=nrop;
            }
        }
   cout<<dp[x^1][0]<<' '<<op[x^1][0];
    return 0;
    }

void read()
    {
    f.getline(buf,nmax);
    ss.str(buf);
    while (ss>>buf)
        {
        ++lp1;
        p1[lp1]=buf;
        lg1[lp1]=strlen(buf);
        }
    f.getline(buf,nmax);
    ss.clear();
    ss.str(buf);
    while(ss>>buf)
        {
        ++lp2;
        s=s+buf;
        lg2[lp2]=strlen(buf);
        slg2[lp2]=lg2[lp2]+slg2[lp2-1];
        }
    ls=s.length();
    }
