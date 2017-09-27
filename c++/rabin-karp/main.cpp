#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

#define baza 73
#define mod1 100007
#define mod2 100021
#define cout g
vector <int> sol;
char text[2000001],pattern[2000001];
int n,m;
int i,p1,p2,nr;
int hash_1_pattern,hash_2_pattern,hash_1,hash_2;
int main()
{
    f>>pattern+1;
    f>>text+1;
    n=strlen(pattern+1);
    m=strlen(text+1);
p1=p2=1;
    for(i=1; i<=n; ++i)
    {
        hash_1_pattern=(hash_1_pattern*baza+pattern[i])%mod1;
        hash_2_pattern=(hash_2_pattern*baza+pattern[i])%mod2;
        if(i>1)
        {
            p1=p1*baza%mod1;
            p2=p2*baza%mod2;
        }
    }
    if(n>m)
    {
        cout<<"0";
        return 0;
    }
    for(i=1; i<=n; ++i)
    {
        hash_1=(hash_1*baza+text[i])%mod1;
        hash_2=(hash_2*baza+text[i])%mod2;
    }
    if(hash_1==hash_1_pattern && hash_2==hash_2_pattern)
    {
        ++nr;
        sol.push_back(0);
    }
    for(i=n+1; i<=m; ++i)
    {
        hash_1=((hash_1 - p1*text[i-n] % mod1 + mod1)*baza+text[i])%mod1;
        hash_2=((hash_2 - p2*text[i-n] % mod2 + mod2)*baza+text[i])%mod2;
        if(hash_1==hash_1_pattern && hash_2==hash_2_pattern)
        {
            ++nr;
            if(nr<=1000) sol.push_back(i-n);
        }
       /* if(i==7)
        {
            cout<<hash_1_pattern<<' '<<hash_1<<'\n';
        }*/
    }
    cout<<nr<<'\n';
    nr=min(nr,1000);
    for(i=0;i<nr;++i)cout<<sol[i]<<' ';
    return 0;
}
