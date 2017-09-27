#include <bits/stdc++.h>

using namespace std;

ifstream f("numere7.in");
ofstream g("numere7.out");

#define cout g

unsigned long long n,x,fact[22],magic;
int fr[10],nr_cif,i,c;
string s;
int main()
{
    f>>n>>s;
    for(i=0;s[i];++i)
    {
        ++fr[s[i]-'0'];
        ++nr_cif;
    }
    fact[0]=1;
    for(i=1;i<=nr_cif;++i) fact[i]=fact[i-1]*i;
    magic=fact[nr_cif];
    for(i=1;i<=9;++i) magic/=fact[fr[i]];
    if(n>magic || n==0)
    {
        cout<<-1;
        return 0;
    }

    for(i=nr_cif;i>0;--i)
    {
        for(c=1;c<=9;++c)
            if(fr[c])
                if(magic*fr[c]/i<n)  n-=magic*fr[c]/i;
                else break;
        cout<<c;
        magic=magic*fr[c]/i;
        --fr[c];
    }
    return 0;
}
