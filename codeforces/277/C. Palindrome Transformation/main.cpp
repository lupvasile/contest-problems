#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define nmax 100010

int n,p,mid,i,x,ls1(nmax),ls2,ld1(nmax),ld2;
char s[nmax];
int moves;



int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("date.in","r",stdin);
    #endif // ONLINE_JUDGE*/
    cin>>n>>p;
    cin>>(s+1);
    mid=(n>>1);
    for(i=1;i<=mid;++i)
    {
        x=min(abs(s[i]-s[n-i+1]),26-abs(s[i]-s[n-i+1]));
        if(x>0)
        {
                ls1=min(ls1,i);
                ls2=max(ls2,i);
        }
        moves+=x;
    }
    ld1=n-ls2+1;
    ld2=n-ls1+1;
    if(ls2==0)
    {
        cout<<moves;
        return 0;
    }
    if(p<=mid)
    {
        if(p<=ls2 && p>=ls1)
        {
            x=min((ls2-p)*2+p-ls1,(p-ls1)*2+ls2-p);
        }
        else
        {
            x=ls2-ls1;
            if(p>ls2) x+=(p-ls2);
            else x+=(ls1-p);
        }
        x=min(x,p+ld2-ld1);
    }
    else
    {
         if(p<=ld2 && p>=ld1)
        {
            x=min((ld2-p)*2+p-ld1,(p-ld1)*2+ld2-p);
        }
        else
        {
            x=ld2-ld1;
            if(p>ld2) x+=(p-ld2);
            else x+=(ld1-p);
        }
        x=min(x,n-p+1+ls2-ls1);
    }

    cout<<moves+x;
    return 0;
}
