#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");
//#define cout g
char text[2000011],pattern[2000011];
int n,m,p[2000011],nr,sol[1010];
void make_prefix()
{
    p[0]=-1;
    int i,v;
    for(int i=2;i<=n;++i)
    {
        v=i-1;
        while (pattern[i]!=pattern[p[v]+1] && v) v=p[v];
        p[i]=p[v]+1;
    }
}
void kmp()
{
    int i,j=0;
    for(i=1;i<=m;++i)
    {
        while (text[i]!=pattern[j+1] && j) j=p[j];
        if(text[i]==pattern[j+1])++j;

        if(j==n)
        {
            j=p[n];
            ++nr;
            if(nr<=1000)sol[nr]=i-n;
        }

    }
}
int main()
{
    f>>pattern+1;
    f>>text+1;
    n=strlen(pattern+1);
    m=strlen(text+1);
make_prefix();
//for(int i=1;i<=n;++i) cout<<p[i]<<'0' ;
kmp();
cout<<nr<<'\n';
nr=min(nr,1000);
for(int i=1;i<=nr;++i) cout<<sol[i]<<' ';
}
