#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream f("sirrom.in");
ofstream g("sirrom.out");

//#define cout g

#define nmax 16
#define lcuv 10001
#define inf 0x3f3f3f3f
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define MOD1 999983
#define MOD2 999981
#define nr(x) (x-'a')
#define SIGMA 26

char cuv[nmax][lcuv];
int cost[nmax][nmax],C[1<<nmax][nmax];
int hash1[nmax][lcuv][2],hash2[nmax][lcuv][2],P1,P2;
int n,m,i,j,sol;
vector <int> G[nmax];

void init();
void build_graph();
int r_C(int,int);
void build_hash();

int main()
    {
    while(f>>n)
        {
        if(n==-1) return 0;
        for(i=1; i<=n; ++i) f>>(cuv[i]+1);
        init();
        C[1][0]=0;
        build_hash();
        build_graph();
        sol=inf;
        for(i=1; i<=n; ++i) sol=min(sol,r_C((1<<(n+1))-1,i));
        cout<<sol<<'\n';
        }
    return 0;
    }

int prefix(int a,int b)
    {
        int res=0,lim,n,m;
        n=strlen(cuv[a]+1);
        m=strlen(cuv[b]+1);
        lim=min(n,m);
        for(int i=1;i<=lim;++i)
            if(hash1[a][n-i+1][1]==hash1[b][i][0] && hash2[a][n-i+1][1]==hash2[b][i][0]) res=i;
        //cout<<cuv[a]+1<<' '<<cuv[b]+1<<' '<<res<<'\n';
    return res;
    }

void build_hash()
    {
    for(i=1; i<=n; ++i)
        {
        for(j=1; cuv[i][j]; ++j)
            {
            hash1[i][j][0]=(hash1[i][j-1][0]*SIGMA+nr(cuv[i][j]))%MOD1;
            hash2[i][j][0]=(hash2[i][j-1][0]*SIGMA+nr(cuv[i][j]))%MOD2;
            }
        P1=P2=1;
        for(--j;j>=1;--j)
        {
            hash1[i][j][1]=(nr(cuv[i][j])*P1%MOD1+hash1[i][j+1][1])%MOD1;
            hash2[i][j][1]=(nr(cuv[i][j])*P2%MOD2+hash2[i][j+1][1])%MOD2;
            P1=P1*SIGMA%MOD1;
            P2=P2*SIGMA%MOD2;
        }
        }
    }

void init()
    {
    for(i=0; i<=n; ++i) G[i].clear();
    memset(C,-1,sizeof C);
    memset(cost,inf,sizeof cost);
    memset(hash1,0,sizeof hash1);
    memset(hash2,0,sizeof hash2);
    }
void build_graph()
    {
    for(i=1; i<=n; ++i)
        {
        G[i].push_back(0);
        cost[0][i]=strlen(cuv[i]+1);
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            {
            if(i==j) continue;
            cost[i][j]=strlen(cuv[j]+1)-prefix(i,j);
            G[j].push_back(i);
            }
    }
int r_C(int conf,int last)
    {
    if(C[conf][last]==-1)
        {
        C[conf][last]=inf;
        foor(it,G[last])
        if(conf&(1<<(*it)))
            {
            if(*it==0 && (1<<last)+1!=conf) continue;
            C[conf][last]=min(C[conf][last],r_C(conf^(1<<last),*it)+cost[*it][last]);
            }
        }
    return C[conf][last];
    }
