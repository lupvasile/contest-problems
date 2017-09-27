#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("cuiburi.in");
ofstream fout("cuiburi.out");
/// ////////////////////////////////

void read();

#define dist(x1,y1,x2,y2) ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
#define nmax 2005

class C_rect
{
public:
    int x1,y1,x2,y2,ind;
    C_rect(int _x1,int _y1,int _x2,int _y2,int _ind): x1(_x1),y1(_y1),x2(_x2),y2(_y2),ind(_ind) {};
};

class C_circ
{
public:
    int x,y,r,ind;
    C_circ(int _x,int _y,int _r,int _ind): x(_x),y(_y),r(_r),ind(_ind) {};
};

bool operator < (const C_rect &r,const C_circ &c)
{
    return (dist(r.x1,r.y1,c.x,c.y)<=c.r*c.r) && (dist(r.x2,r.y2,c.x,c.y)<=c.r*c.r) && (dist(r.x1,r.y2,c.x,c.y)<=c.r*c.r) && (dist(r.x2,r.y1,c.x,c.y)<=c.r*c.r);
}

bool operator < (const C_rect &r1,const C_rect &r2)
{
    return r2.x1<=r1.x1 && r2.y1<=r1.y1 && r2.x2>=r1.x2 && r2.y2>=r1.y2;
}

bool operator < (const C_circ &c,const C_rect &r)
{
    return (c.x-c.r)>=r.x1 && (c.x+c.r)<=r.x2 && (c.y-c.r)>=r.y1 && (c.y+c.r)<=r.y2;
}

bool operator < (const C_circ &c1,const C_circ &c2)
{
    if(c1.r>c2.r) return 0;
    return dist(c1.x,c1.y,c2.x,c2.y)<=(c2.r-c1.r)*(c2.r-c1.r);
}

vector<C_rect> R;
vector<C_circ> C;
vector<int> G[nmax];
bool gg[nmax][nmax],viz[nmax];
int n,dp[nmax];

void make_graph()
{
    for(auto &it:R)
    {
        for(auto &it2:R)
        {
            if(it.ind==it2.ind || gg[it.ind][it2.ind]) continue;
            if(it<it2)
            {
                G[it2.ind].push_back(it.ind);
                gg[it2.ind][it.ind]=1;
            }
        }
        for(auto &it2:C)
        {
            if(it.ind==it2.ind || gg[it.ind][it2.ind]) continue;
            if(it<it2)
            {
                G[it2.ind].push_back(it.ind);
                gg[it2.ind][it.ind]=1;
            }
        }
    }

    for(auto &it:C)
    {
        for(auto &it2:R)
        {
            if(it.ind==it2.ind || gg[it.ind][it2.ind]) continue;
            if(it<it2)
            {
                G[it2.ind].push_back(it.ind);
                gg[it2.ind][it.ind]=1;
            }
        }
        for(auto &it2:C)
        {
            if(it.ind==it2.ind || gg[it.ind][it2.ind]) continue;
            if(it<it2)
            {
                G[it2.ind].push_back(it.ind);
                gg[it2.ind][it.ind]=1;
            }
        }
    }
}

void dfs(int nod)
{
    viz[nod]=true;
    for(auto son:G[nod])
    {
        if(!viz[son]) dfs(son);
        dp[nod]=max(dp[nod],dp[son]);
       // if(dp[nod]==dp[son]) nnext[nod]=son;
    }
    ++dp[nod];
}

int main()
{
    int res(0);
    read();
    make_graph();
    for(int i=1; i<=n; ++i)
        if(!viz[i]) dfs(i);

    for(int i=1; i<=n; ++i) res=max(res,dp[i]);
    cout<<res<<'\n';
    //for(int nod=9;nod;nod=nnext[nod]) cout<<nod<<' ';

    return 0;
}

void read()
{
    int i,tip,a,b,c,d;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>tip;
        if(tip==0)
        {
            fin>>a>>b>>c>>d;
            R.push_back({a,b,c,d,i});
        }
        else
        {
            fin>>a>>b>>c;
            C.push_back({a,b,c,i});
        }
    }
}
