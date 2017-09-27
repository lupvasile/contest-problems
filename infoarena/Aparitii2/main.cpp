#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("aparitii2.in");
ofstream fout("aparitii2.out");
/// ////////////////////////////////
#define nmax 1000010

int n_t,n_p;
char text[nmax],patt[nmax];
int st[nmax],dr[nmax],z[nmax*2],v[nmax];

void some_weird_magic(char text[],char patt[],int v[])
{
    char s[2*nmax]=" ";
    strcat(s,patt);
    strcat(s,"#");
    strcat(s,text);

    int n=strlen(s+1),i,R=0,L=0;

    for(i=2;i<=n;++i)
    {
        if(s[i]!=s[1])
        {
            z[i]=0;
            continue;
        }
        if(i>R)
        {
            R=L=i;
            while(s[R+1]==s[R+1-L+1]) ++R;
            z[i]=R-L+1;
        }
        else if(z[i-L+1]<R-i+1) z[i]=z[i-L+1];
        else
        {
            L=i;
            while(s[R+1]==s[R+1-L+1]) ++R;
            z[i]=R-L+1;
        }
    }

    for(i=1;i<=n_t;++i)
        v[i]=z[i+n_p+1];
}

int main()
{
    int i;
    fin>>(text+1);
    fin>>(patt+1);

    n_t=strlen(text+1);
    n_p=strlen(patt+1);

    some_weird_magic(text+1,patt+1,dr);
    reverse(text+1,text+n_t+1);
    reverse(patt+1,patt+n_p+1);
    some_weird_magic(text+1,patt+1,st);
    reverse(st+1,st+n_t+1);

    for(i=1;i+n_p-1<=n_t;++i)
        if(min(dr[i],st[i+n_p-1]))
    {
        ++v[1];--v[min(dr[i],st[i+n_p-1])+1];
    }

    for(i=1;i*2<=n_p;++i)
    {
        v[i]+=v[i-1];
        cout<<v[i]<<'\n';
    }

    return 0;
}
