#include <bits/stdc++.h>
using namespace std;
/// ////////////////////////////////

#define nmax 502

int dp[nmax][nmax],L[nmax],R[nmax];
bool open[nmax];
vector<int> G[nmax];

class copacel
{
public:
    vector<int> at_lev[nmax],G[nmax],bomberman[nmax];
    int lev[nmax],n,sz[nmax];

    void grow()
    {
        int i,x,y;
        scanf("%d",&n);
        for(i=0; i<nmax; ++i) G[i].clear(),at_lev[i].clear(),lev[i]=0,sz[i]=0,bomberman[i].clear();

        for(i=1; i<n; ++i)
        {
            scanf("%d%d",&x,&y);
            bomberman[x].push_back(y);
            bomberman[y].push_back(x);
        }
    }

    void bloom(int nod)
    {
        at_lev[lev[nod]].push_back(nod);
        sz[nod]=1;

        for(auto son:bomberman[nod])
        {
            if(sz[son]) continue;
            G[nod].push_back(son);
            lev[son]=lev[nod]+1;
            sz[nod]+=sz[son];
            bloom(son);
        }
    }

} brad,mar;

bool cupleaza(int nod)
{
    if(open[nod]) return 0;

    for(auto vec:G[nod])
        if(L[vec]==-1)
    {
        L[vec]=nod;
        R[nod]=vec;
        return 1;
    }

    open[nod]=true;
    for(auto vec:G[nod])
        if(cupleaza(L[vec]))
        {
            L[vec]=nod;
            R[nod]=vec;
            open[nod]=false;
            return 1;
        }


    //open[nod]=false;
    return 0;
}

bool try_match(int x,int y)
{
    if(mar.G[y].size()==0) return 1;

    for(auto sonX:brad.G[x]) R[sonX]=-1,open[sonX]=0;
    for(auto sonY:mar.G[y]) L[sonY]=-1;
    //for(int i=0;i<nmax;++i) R[i]=L[i]=-1,open[i]=0;
    for(int i=0;i<brad.n;++i) G[i].clear();

    for(auto sonX:brad.G[x])
        for(auto sonY:mar.G[y])
            if(dp[sonX][sonY])
                G[sonX].push_back(sonY);

    for(auto sonX:brad.G[x])
            if(R[sonX]==-1)
                cupleaza(sonX);

    int nr=0;
    for(auto sonX:brad.G[x])
        if(R[sonX]!=-1) ++nr;

    return nr==mar.G[y].size();
}


void make_din()
{
    if(brad.n<mar.n)
    {
        dp[0][0]=0;
        return;
    }

    memset(dp,0,sizeof dp);


    for(int i=mar.n-1;i>=0;--i)
        for(auto x:brad.at_lev[i])
            for(auto y:mar.at_lev[i])
                if(brad.sz[x]>=mar.sz[y] && brad.G[x].size()>=mar.G[y].size())
                    {
                        dp[x][y]=try_match(x,y);
                        //if(dp[x][y]) G[x].push_back(y);
                    }

}

int main()
{
    int T;
    freopen("sakura.in","r",stdin);
    freopen("sakura.out","w",stdout);

    scanf("%d",&T);

    for(; T; --T)
    {
        brad.grow();
        mar.grow();

        brad.bloom(0);
        mar.bloom(0);

        make_din();

        if(dp[0][0]) printf("%d\n",brad.n-mar.n);
        else printf("-1\n");
    }
    return 0;
}
