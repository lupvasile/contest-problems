#include <bits/stdc++.h>

using namespace std;

ifstream f("diff.in");
ofstream g("diff.out");
#define nmax 100001
#define cout g
int n,m,i,diff,x,minn,maxx,pmin,pmax;
bool ok,ap[2*nmax+2];
int first_ap[2*nmax+2],last_ap[2*nmax+2];
#define first_ap (first_ap+nmax)
#define last_ap (last_ap+nmax)
#define ap (ap+nmax)

int gi();
int main()
    {
    n=gi();
    m=gi();

    for(i=1; i<=n; ++i)
        {
        x=gi();
        if(x) diff+=1;
        else diff-=1;

        if(!ap[diff-minn])
            {
            ap[diff-minn]=true;
            first_ap[diff-minn]=pmin+1;
            last_ap[diff-minn]=i;
            }

        if(!ap[diff-maxx])
            {
            ap[diff-maxx]=true;
            first_ap[diff-maxx]=pmax+1;
            last_ap[diff-maxx]=i;
            }
        if(diff<minn)
            {
            minn=diff;
            pmin=i;
            }
        if(diff>maxx)
            {
            maxx=diff;
            pmax=i;
            }
        }
    for(; m; --m)
        {
        x=gi();
        if(x>n || x<-n)
            {
            cout<<"-1\n";
            continue;
            }
        if(!ap[x])
        {
            cout<<"-1\n";
            continue;
        }
        cout<<first_ap[x]<<' '<<last_ap[x]<<'\n';
        }
    return 0;
    }

#define maxb 300000
int pos(maxb);
char buf[maxb];
int gi()
    {
    int n(0),s(1);
    while((buf[pos]<'0' || buf[pos]>'9') && buf[pos]!='-')
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    if(buf[pos]=='-')
        {
        s=-1;
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    while(buf[pos]>='0' && buf[pos]<='9')
        {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    return n*s;
    }
