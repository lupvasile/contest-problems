#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream f("blis.in");
ofstream g("blis.out");

#define nmax 100010
#define inf (1<<30)+10
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,k,i,lim,pos,x,j,rasp,maxx;
bool v[nmax];
int dp[nmax];
char s[nmax];
vector <pair<int,int> >upd[nmax];


inline int caut(int val)
{
    int step,x(0);
    for(step=1;step<=n;step<<=1);
    for(;step;step>>=1)
    {
        if(x+step<=n && dp[x+step]<val) x+=step;
    }
    return x;
}


int main()
{
 freopen("blis.in","r",stdin);
    freopen("blis.out","w",stdout);
    scanf("%d%s",&k,s+1);
    n=strlen(s+1);
    for(i=1;i<=n+1;++i)dp[i]=inf;
    dp[0]=-inf;
    for(i=1;i<=n;++i)
    {
        lim=min(i+k-1,n);
        x=0;
        for(j=i;j<=lim;++j)
        {
            x=(x<<1)|(s[j]-'0');
            if(x>maxx) maxx=x;
            pos=caut(x);
            if(dp[pos+1]>x) upd[j].push_back({pos+1,x});
        }
        foor(it,upd[i]) if(dp[it->first]>it->second)
        {
            dp[it->first]=it->second;
        }
    }
    cout<<maxx<<'\n';
    cout<<caut(inf);
    return 0;
}


