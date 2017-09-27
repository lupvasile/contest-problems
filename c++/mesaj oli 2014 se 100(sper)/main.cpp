#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("mesaj.in");
ofstream g("mesaj.out");

int i,l,j,vasi,lup;
//char s[202],*a[202][202];
string q,t,v[202];
string rasp,s;
int nr;

int main()
{
    getline(f,s);
    l=s.length();

    for(nr=l/2; nr; --nr)
    {
        for (i=0; i<=l-nr; ++i)
        {
            q=s.substr(i,nr);
            sort(q.begin(),q.end());
            v[i]=q;
        }
        for(i=0; i<=l-2*nr; ++i)
            for(j=i+nr; j<=l-nr; ++j)
                if (v[i]==v[j]) rasp=max(rasp,s.substr(i,nr)),rasp=max(rasp,s.substr(j,nr));
        if (rasp.length()) break;
    }
    g<<rasp;
//cout<<(sizeof(a)+sizeof(s))/1024/1024;
//for(i=1;i<=200;++i) g<<'b';
    return 0;
}
