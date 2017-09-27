#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("pscpld.in");
ofstream fout("pscpld.out");
/// ////////////////////////////////

#define nmax 1000010

char inp[nmax],s[2*nmax];
int len[2*nmax];
int n;

void make_new_string()
{
    int l=0,i;
    fin>>inp;
    n=strlen(inp);

    s[0]='^';
    s[++l]='#';
    for(i=0;i<n;++i)
    {
        s[++l]=inp[i];
        s[++l]='#';
    }
    s[++l]='%';
    n=l;
}

long long res;

int main()
{
    make_new_string();

    int i,center(0),R(-1);

    for(i=1;i<n;++i)
    {
        if(i>R) len[i]=0;
        else len[i]=min(R-i,len[center-(i-center)]);

        while(s[i+len[i]+1]==s[i-len[i]-1]) ++len[i];

        if(i+len[i]>R)
        {
            R=i+len[i];
            center=i;
        }

        res+=(len[i]+1)/2;
    }

    cout<<res;

    return 0;
}
