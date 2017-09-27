/// vezi cu aaba si abaa


#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream f("sirrom.in");

//#define cout g
#define nmax 16
#define lmax 10001
#define inf (1<<30)
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

vector <int> G[nmax];
int cost[nmax][nmax],C[1<<nmax][nmax];
char cuv[nmax][lmax];
int n,i,j,res;
int pref[lmax<<1];

void init();
void const_graf();
int prefix(char *p1, char *p2);

int r_C(int conf,int last)
{
    if(C[conf][last]==-1)
    {
        C[conf][last]=inf;
        foor(it,G[last]) if(conf&(1<<(*it)))
        {
            if(*it==0 && (1<<last)+1!=conf) continue;
            C[conf][last]=min(C[conf][last],r_C(conf^(1<<last),*it)+cost[*it][last]);
        }
    }
    return C[conf][last];
}

int main()
{
    while(f>>n)
    {
        if(n==-1) break;
        for(i=1;i<=n;++i) f>>(cuv[i]+1);
        init();
        const_graf();
        res=inf;
        for(i=1;i<=n;++i) res=min(res,r_C((1<<(n+1))-1,i));
        cout<<res<<'\n';
    }
    return 0;
}
void init()
{
    for(i=0;i<=n;++i) G[i].clear();
    memset(cost,inf,sizeof cost);
    memset(C,-1,sizeof C);
    for(i=1;i<=n;++i) cost[0][i]=strlen(cuv[i]+1);
    C[1][0]=0;
}
void const_graf()
{
    for(i=1;i<=n;++i)
        {
            G[i].push_back(0);
            for(j=1;j<=n;++j)
            {
                if(j==i) continue;
                cost[i][j]=strlen(cuv[j]+1)-prefix(cuv[i],cuv[j]);
                G[j].push_back(i);
            }
        }
}
int prefix(char *p1, char *p2)
{
    int l1=strlen(p1+1),l2=strlen(p2+1)-1,pos,i;

    pref[1]=pos=0;
    for(i=1;i<=l2;++i)
    {
        while(p2[pos+1]!=p2[i] && pos>0) pos=pref[pos];
        if(p2[pos+1]==p2[i]) ++pos;
        pref[i]=pos;
    }
    pos=0;
    for(i=2;i<=l1;++i)
    {
        while(p2[pos+1]!=p1[i] && pos) pos=pref[pos];
        if(p2[pos+1]==p1[i]) ++pos;
    }
    cout<<p1+1<<' '<<p2+1<<' '<<pos<<'\n';
    return pos;
}
