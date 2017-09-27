#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("palindrom.in");
ofstream g("palindrom.out");

#define nmax 200010
//#define cout g
char s[nmax],rs[nmax];
int pref[nmax],pos;
int n,i;

void make_pref()
{
    pos=0;
    for(i=2;i<=n;++i)
    {
        while(rs[pos+1]!=rs[pos] && pos) pos=pref[pos];
        if(rs[pos+1]==rs[i]) ++pos;
        pref[i]=pos;
    }
}

int main()
{
    f>>(rs+1);
    strcpy(s+1,rs+1);
    n=strlen(s+1);
    reverse(rs+1,rs+n+1);
    make_pref();
    pos=0;
    for(i=1;i<=n;++i)
    {
        while(rs[pos+1]!=s[i] && pos) pos=pref[pos];
        if(rs[pos+1]==s[i]) ++pos;
    }
    s[n-pos+1]='\0';
    cout<<(s+1)<<(rs+1);
    return 0;
}
