#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");
/// ////////////////////////////////////////////////

#define nmax 2000010
#define mod1 666013
#define mod2 666011
#define BASE 130

char pattern[nmax],text[nmax];
int n,m;
vector<int> res;

pair<int,int> hash_pattern,hash_text,BASE_power({1,1});

pair<int,int> operator * (const pair<int,int> &p,const int &x)
{
    return make_pair(p.first * x % mod1, p.second * x % mod2);
}

pair<int,int> operator + (const pair<int,int> &p,const int &x)
{
    return make_pair((p.first + x) % mod1, (p.second + x) % mod2);
}

pair<int,int> operator * (const pair<int,int> &p1,const pair<int,int> &p2)
{
    return make_pair(p1.first * p2.first % mod1, p1.second * p2.second % mod2);
}

pair<int,int> operator + (const pair<int,int> &p1,const pair<int,int> &p2)
{
    return make_pair((p1.first + p2.first + mod1) % mod1, (p1.second + p2.second + mod2) % mod2);
}

int main()
{
    int pos=0,i,nr=0;
    fin>>pattern+1>>text+1;
    n=strlen(pattern+1),m=strlen(text+1);

    for(i=1; i<=n; ++i)
    {
        hash_pattern=hash_pattern * BASE + pattern[i];
        if(i>1) BASE_power=BASE_power * BASE;
    }

    for(i=1; i<=n; ++i)
        hash_text=hash_text * BASE + text[i];

    if(hash_text==hash_pattern)
    {
        ++nr;
        if(nr<=1000) res.push_back(0);
    }

    for(i=n+1; i<=m; ++i)
    {
        hash_text=(hash_text + BASE_power * (-(int)text[i-n]) ) * BASE + text[i];

        if(hash_text==hash_pattern)
        {
            ++nr;
            if(nr<=1000) res.push_back(i-n);
        }
    }

    cout<<nr<<'\n';
    for(auto it:res) cout<<it<<' ';
    return 0;
}
