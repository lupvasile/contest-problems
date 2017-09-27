#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");
/// ////////////////////////////////////////////////

#define nmax 2000010

char pattern[nmax],text[nmax];
int pref[nmax],n,m;
vector<int> res;

void make_prefix()
{
    int k;
    pref[1]=0;
    for(int i=2; i<=n; ++i)
    {
        k=pref[i-1];
        while(pattern[i]!=pattern[k+1] && k) k=pref[k];
        if(pattern[i]==pattern[k+1]) ++k;
        pref[i]=k;
    }
}

int main()
{
    int pos=0,i,nr=0;
    fin>>pattern+1>>text+1;
    n=strlen(pattern+1),m=strlen(text+1);

    make_prefix();

    for(i=1; i<=m; ++i)
    {
        while(text[i]!=pattern[pos+1] && pos) pos=pref[pos];
        if(text[i]==pattern[pos+1]) ++pos;

        if(pos==n)
        {
            ++nr;
            if(nr<=1000) res.push_back(i-n);
        }
    }

    cout<<nr<<'\n';
    for(auto it:res) cout<<it<<' ';
    return 0;
}
