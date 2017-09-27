#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cautbin.in");
ofstream g("cautbin.out");

#define cout g
#define nmax 100010

int n,v[nmax],i,x,val,step,log,m,tip;
int main()
{
    f>>n;
    for(i=1;i<=n;++i) f>>v[i];

    for(log=1;log<=n;log<<=1);
    log>>=1;

    f>>m;
    for(;m;--m)
    {
        f>>tip>>val;
        x=0;
        if(tip<2)
        {
            for(step=log;step;step>>=1)
                if(x+step<=n && v[x+step]<=val) x+=step;
            if(tip==0)
            {
                if(v[x]==val) cout<<x<<'\n';
                else cout<<-1<<'\n';
            }
            else cout<<x<<'\n';
        }
        else
        {
            x=n;
            for(step=log;step;step>>=1)
                if(x-step>0 && v[x-step]>=val) x-=step;
            cout<<x<<'\n';
        }
    }
    return 0;
}
