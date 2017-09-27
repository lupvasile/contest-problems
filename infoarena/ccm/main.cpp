#include <bits/stdc++.h>

using namespace std;

ifstream f("ccm.in");
ofstream g("ccm.out");

#define nmax 20
#define cout g
#define mod 9901

int n,m,e,x,y,i,lim,stare;
short dp[nmax][1<<nmax],bst[nmax][1<<nmax];
vector<int> G[nmax];
bool viz[nmax];
int L[nmax],R[nmax];

bool pairup(int nod)
    {
    if(viz[nod]) return false;
    viz[nod]=true;
    for(auto vec:G[nod]) if(stare&(1<<(vec-1)))
            if(L[vec]==0)
                {
                L[vec]=nod;
                R[nod]=vec;
                return 1;
                }

    for(auto vec:G[nod]) if(stare&(1<<(vec-1)))
            if(pairup(vec))
                {
                L[vec]=nod;
                R[nod]=vec;
                return 1;
                }
    return false;
    }

int det_bst(int i,int stare)
    {
    /* bool ok=true;
     int j;

     memset(L,0,sizeof L);
     memset(R,0,sizeof R);

     while(ok)
         {
         ok=false;
         memset(viz,0,sizeof viz);
         for(j=1; j<=i; ++j) if(!R[j]) if(pairup(j))ok=true;
         }
     int r=0;
     for(j=1;j<=i;++j) if(R[j]) ++r;
     */
    int r=bst[i-1][stare];
    for(auto vec:G[i]) if(stare&(1<<(vec-1))) r=max(r,bst[i-1][stare-(1<<(vec-1))]+1);
    return r;
    }

int main()
    {
    f>>n>>m>>e;
    for(i=1; i<=e; ++i)
        {
        f>>x>>y;
        G[x].push_back(y);
        }
    lim=(1<<m);
    for(i=0; i<lim; ++i) dp[0][i]=1;
    for(i=1; i<=n; ++i) dp[i][0]=1;
    for(i=1; i<=n; ++i)

        for(stare=1; stare<lim; ++stare)
            {
            bst[i][stare]=det_bst(i,stare);
            dp[i][stare]=0;
            if(bst[i-1][stare]==bst[i][stare]) dp[i][stare]+=dp[i-1][stare];
            for(auto vec:G[i])
                if(stare&(1<<(vec-1)))
                    if(bst[i-1][stare-(1<<(vec-1))]==bst[i][stare]-1)
                        {
                        dp[i][stare]+=dp[i-1][stare-(1<<(vec-1))];
                        if(dp[i][stare]>=mod) dp[i][stare]-=mod;
                        }

            }
    cout<<bst[n][lim-1]<<' '<<dp[n][lim-1];
    /*  g.close();
      f.close();
      g.open("ccm.in");
      n=16;
      g<<n<<' '<<n<<' '<<n*n<<'\n';
      for(i=1;i<=n;++i)
          for(int j=1;j<=n;++j)
          g<<i<<' '<<j<<'\n';*/
    return 0;
    }
