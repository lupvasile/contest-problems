#include <iostream>
#include <fstream>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream f("date.in");
#define cin f
#endif // ONLINE_JUDGE

#define nmax 200010

int n,i,x,st,dr,mid,r;
int bita[nmax],bitb[nmax],bitc[nmax],facta[nmax],factb[nmax],factc[nmax],sol[nmax];

int qaib(int aib[],int x)
    {
    int s=0;
    for(; x; x-=(x&(-x)))
        {
        s+=aib[x];
        }
    return s;
    }
void ins_aib(int aib[],int pos)
    {
    for(; pos<=n; pos+=(pos&(-pos)))
        ++aib[pos];
    }
int main()
    {
    cin>>n;
    for(i=1; i<=n; ++i)
        {
        cin>>x;
        ++x;
        facta[n-i+1]=x-1-qaib(bita,x-1);
        ins_aib(bita,x);
        }
    for(i=1; i<=n; ++i)
        {
        cin>>x;
        ++x;
        factb[n-i+1]=x-1-qaib(bitb,x-1);
        ins_aib(bitb,x);
        }
    for(i=1; i<=n; ++i)
        {
        factc[i]+=facta[i]+factb[i];
        factc[i+1]+=factc[i]/i;
        factc[i]%=i;
        }
    for(i=n; i; --i)
        {
        st=1;
        dr=n;
        while(st<=dr)
            {
            mid=(st+dr)/2;
            x=qaib(bitc,mid-1)+factc[i]+1;
            if(mid==x)
                {
                r=mid-1;
                st=mid+1;
                }
            else if(mid<x) st=mid+1;
            else dr=mid-1;
            }
        cout<<r<<' ';
        ins_aib(bitc,r+1);
        }
    return 0;
    }
