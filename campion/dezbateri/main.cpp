#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

ifstream f("dezbateri.in");
ofstream g("dezbateri.out");

#define cout g
#define nmax 1010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,r,i,a,b,c,mod,nr[nmax],p,v[nmax];
string s;
vector <int> G[nmax];

int main()
{
    f>>n>>r;
    for(;r;--r)
    {
        f>>s;
        a=b=c=0;
        for(i=0;isdigit(s[i]);++i) a=a*10+s[i]-'0';
        if(s[i++]=='>') mod=1;
        else mod=2;
        for(;isdigit(s[i]);++i) b=b*10+s[i]-'0';
        ++i;
        for(;isdigit(s[i]);++i) c=c*10+s[i]-'0';
        if(mod==1)
        {
            foor(it,G[b]) if(*it==a) goto h1;
            G[b].push_back(a);
            ++nr[a];
            h1:;
            foor(it,G[c]) if(*it==a) goto h2;
            G[c].push_back(a);
            ++nr[a];
            h2:;
        }
        else
        {
            foor(it,G[c]) if(*it==a) goto h3;
            G[c].push_back(a);
            ++nr[a];
            h3:;
            foor(it,G[c]) if(*it==b) goto h4;
            G[c].push_back(b);
            ++nr[b];
            h4:;
        }

    }
    while(1)
    {
        for(p=1;nr[p]!=0 && p<=n;++p);
        if(p>n) break;
        v[++v[0]]=p;
        --nr[p];
        foor(it,G[p]) --nr[*it];
    }
    if(v[0]<n) cout<<0;
    else for(i=1;i<=v[0];++i) cout<<v[i]<<' ';
    return 0;
}
