#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream f("char.in");
ofstream g("char.out");

char s[10010],s1[10010];
int put[28];
#define put(a) put[a-'a']
#define cout g
int n,h,i,pmax,nr,nrp,li,ssf;
struct elele{int in,sf;} v[10010];

bool cmp(elele a,elele b)
{
    if(a.sf==b.sf) return a.in<b.in;
    return a.sf<b.sf;
}
int main()
{
    f>>n;
    f>>s;
    strcpy(s1,s);
    sort(s1,s1+n);
    f>>h;
    for(i=0;i<n;++i)
    {
        if(s1[i]!=s1[i+1]) f>>put(s1[i]),pmax=max(pmax,put(s1[i]));
    }
    for(i=0;i<n;++i)
    {
        v[i].in=max(0,i-put(s[i]));
        v[i].sf=min(n-1,i+put(s[i]));
        if(put(s[i])==pmax) ++nr;
    }
    sort(v,v+n,cmp);
    nrp=1;
    ssf=v[0].sf;
    for(i=0;i<n;++i)
    {
        if(v[i].in>ssf)
        {
                ++nrp;
                ssf=v[i].sf;
        }
    }
    cout<<nr<<"\n"<<nrp;
 //   cout<<s1;
    return 0;
}
