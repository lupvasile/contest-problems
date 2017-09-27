#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//#define cout g

ifstream f("arbore.in");
ofstream g("arbore.out");

#define nmax 101
#define kmax 1001
#define ff first
#define ss second
#define foor(it,v) for(__typeof(v.begin())it=v.begin();it!=v.end();++it)
pair<int,int> dp[nmax][kmax];
int val[nmax];
vector <int> G[nmax];
int n,k,i,x;
bool ok;

void read();

void afis(int nod,int k)
    {
    cout<<nod<<'\n';
    for(; dp[nod][k].ff!=nod; k-=dp[nod][k].ss) afis(dp[nod][k].ff,dp[nod][k].ss);
    }

void dp_dfs(int nod)
    {
///dp[nod][i] .ff ultimu nod adaugat pentru a obtine suma i
///           .ss cu ce suma am adaugat nodul
    int i,j;
    dp[nod][val[nod]]= {nod,val[nod]};
    foor(it,G[nod])
        {
        dp_dfs(*it);
        for(j=1; j<=k; ++j) if(dp[*it][j].ff)
                for(i=k-j; i>=1; --i)
                    if(dp[nod][i].ff>0 && dp[nod][i].ff!=*it && dp[nod][i+j].ff==0)
                        dp[nod][i+j]= {*it,j};
        if(dp[nod][k].ff)
            {
            afis(nod,k);
            ok=true;
            }
        }
    }

int main()
    {
    read();
    dp_dfs(1);
    if(!ok)cout<<-1;
    return 0;
    }

void read()
    {
    f>>n>>k;
    f>>val[1];
    for(i=2; i<=n; ++i)
        {
        f>>x>>val[i];
        G[x].push_back(i);
        }

    }
