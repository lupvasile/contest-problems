#include <bits/stdc++.h>

using namespace std;

ifstream f("avarcolaci.in");
ofstream g("avarcolaci.out");
#define cout g

int t,n,x,maj[20],fr[20],k,i;

int main()
{
    f>>t;
    for(k=1;k<=t;++k)
    {
        f>>n;
        for(i=1;i<=2*n;++i)
        {
            f>>x;
            if(x==maj[k]) ++fr[k];
            else
            {
                --fr[k];
                if(fr[k]<0) fr[k]=1,maj[k]=x;
            }
        }
    }
    f.close();
    ifstream ff("avarcolaci.in");
    #define f ff
    f>>t;
    for(k=1;k<=t;++k)
    {
        f>>n;
        fr[k]=0;
        for(i=1;i<=2*n;++i)
        {
            f>>x;
            if(x==maj[k]) ++fr[k];
        }
        if(fr[k]>n) cout<<maj[k]<<'\n';
        else cout<<"Mozart\n";
    }
}
