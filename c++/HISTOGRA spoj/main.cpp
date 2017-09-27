#include <iostream>
#include <stack>
using namespace std;

#define mp make_pair
#define nmax 100010

int n,i,st,x;
pair<int,int>  stk[nmax];
long long ar_max,aria;


int main()
{
    while(1)
    {
        cin>>n;
        if(n==0) return 0;
        st=0;
        ar_max=0;
        stk[++st]=mp(0,0);
        for(i=1;i<=n+1;++i)
        {
            if(i<=n)cin>>x;
            else x=0;
            while(stk[st].first>x)
            {
                aria=1ll*stk[st].first*(i-stk[st-1].second-1);
                ar_max=max(ar_max,aria);
                --st;
            }
            stk[++st]=mp(x,i);
        }
        cout<<ar_max<<'\n';

    }
    return 0;
}
