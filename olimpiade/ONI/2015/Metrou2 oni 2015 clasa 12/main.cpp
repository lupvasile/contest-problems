#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("metrou2.in");
ofstream fout("metrou2.out");


void citire();

#define nmax 100010

vector <int> G[nmax];
int grad[nmax],prof[nmax],nnext[nmax],gr3[20],adiac[20][20],ind[nmax];
int n,m,nr_lant,res;
bool grad_3,grad_1,viz[nmax];
int dp[nmax][3];///0 fara 1 cu 2 profitu nodului

class c_lant
{
public:
    int start,eend,from,v1,v2,v3,v4;
    void make_dp();
}
lant[nmax];

///v1 cu ambele capete incluse
///v2 doar cu capatul stang inclus
///v3 doar cu capatul drept inclus
///v4 fara capete

void dfs_grad1(int nod,int tata)
{
    viz[nod]=1;
    nnext[tata]=nod;
    if(tata==0) lant[++nr_lant].from=nod;

    for(auto it:G[nod]) if(!viz[it] && grad[it]<=2) dfs_grad1(it,nod);

    for(auto it:G[nod]) if(!viz[it] && grad[it]>2)
        {
            nnext[nod]=it;
            lant[nr_lant].eend=it;
        }
}

void dfs_grad3(int nod,int tata)
{
    bool ok=false;
    viz[nod]=true;
    if(grad[nod]<=2)
    {
        if(grad[tata]>2)
        {
            ++nr_lant;
            lant[nr_lant].from=nod;
            lant[nr_lant].start=tata;
        }
        nnext[tata]=nod;
    }

    for(auto it:G[nod]) if(!viz[it] && grad[it]<=2)
        {
            dfs_grad3(it,nod);
            ok=true;
        }

    if(grad[nod]<=2 && !ok)
    {
        if(grad[G[nod][0]]<=2 || grad[G[nod][1]]<=2) lant[nr_lant].eend=grad[G[nod][0]]>2 ? G[nod][0]:G[nod][1];
        else lant[nr_lant].eend=G[nod][0]!=tata ? G[nod][0]:G[nod][1];
        nnext[nod]=lant[nr_lant].eend;
    }

}

bool valid(long long k)
{
    int p1,p2;
    for(p1=0;(1ll<<p1)<=k;p1++);
    --p1;
    for(;p1>=0;--p1)
    for(p2=p1-1;p2>=0;--p2)
        if((k&(1ll<<p1)) && (k&(1ll<<p2)) && adiac[p1+1][p2+1]) return false;

    return true;
}
int calc_prof(long long k)
{
    int i,res=0;
    for(i=1;i<=nr_lant;++i)
    {
        if(lant[i].start==0 && lant[i].eend==0) res+=lant[i].v1;
        if(lant[i].start!=0 && lant[i].eend!=0)
        {
            if(k&(1ll<<(ind[lant[i].start]-1))) if(k&(1ll<<(ind[lant[i].eend]-1))) res+=lant[i].v4;
                                                else res+=lant[i].v3;
            else if(k&(1ll<<(ind[lant[i].eend]-1))) res+=lant[i].v2;
            else res+=lant[i].v1;
        }
        if(lant[i].start==0 && lant[i].eend!=0)
        {
            if(k&(1ll<<(ind[lant[i].eend]-1))) res+=lant[i].v2;
            else res+=lant[i].v1;
        }
    }
    for(i=0;(1ll<<i)<=k;++i) if(k&(1ll<<i)) res+=prof[gr3[i+1]];
    return res;
}
void rez_grad_3()
{
    int i;
    long long k;
    for(i=1; i<=n; ++i) if(grad[i]==1 && !viz[i])
        {
            dfs_grad1(i,0);
        }

    for(i=1; i<=n; ++i) if(grad[i]>2 && !viz[i])
        {
            dfs_grad3(i,0);
        }
    for(i=1; i<=nr_lant; ++i) lant[i].make_dp();

    for(k=((1ll<<gr3[0])-1); k>=0; --k)
    {
        if(valid(k))
            res=max(res,calc_prof(k));
    }
    }


int main()
{
    citire();
    if(grad_3==false && grad_1==false) grad[1]=3;
    rez_grad_3();
    cout<<res;
    return 0;
}
void citire()
{
    int i,x,y;
    grad[0]=90;
    fin>>n>>m;
    for(i=1; i<=n; ++i) fin>>prof[i];
    for(i=1; i<=m; ++i)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++grad[x];
        ++grad[y];
    }
    for(i=1; i<=n; ++i) if(grad[i]>2)
        {
            grad_3=true;
            gr3[++gr3[0]]=i;
            ind[i]=gr3[0];
        }
        else if(grad[i]==1) grad_1=true;
    for(int i=1; i<=gr3[0]; ++i)
        for(int j=i; j<=gr3[0]; ++j)
        {
            if(i==j) adiac[i][j]=1;
            for(auto it:G[gr3[i]]) if (it==gr3[j]) adiac[i][j]=adiac[j][i]=1;
        }
}



void c_lant::make_dp()
{
    int nod,l=0,i;
    for(nod=from; grad[nod]<=2; nod=nnext[nod]) dp[++l][2]=prof[nod];

    dp[1][0]=0;
    dp[1][1]=dp[1][2];

    for(i=2; i<=l; ++i)
    {
        dp[i][0]=max(dp[i-2][0]+dp[i][2],dp[i-1][0]);
        dp[i][1]=max(dp[i-2][1]+dp[i][2],dp[i-1][1]);
    }

    v1=dp[l][1];
    v2=dp[l-1][1];
    v3=dp[l][0];
    v4=dp[l-1][0];
}


