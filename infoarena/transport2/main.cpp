#include <bits/stdc++.h>

using namespace std;

ifstream f("transport2.in");
ofstream g("transport2.out");

#define nmax 100001
#define cout g
vector <pair<int,int>> G[nmax];
int n,m,x,y,i,z,step,lim;
bool viz[nmax];
int gi();
void dfs(int nod,int w)
{
    viz[nod]=true;
    if(viz[n]) return;
    for(auto vec:G[nod])
        if(!viz[vec.first])
        if(vec.second>=w) dfs(vec.first,w);
}

int main()
{
    n=gi();
    m=gi();
    for(i=1;i<=m;++i)
    {
        x=gi();
        y=gi();
        z=gi();
        G[x].push_back({y,z});
        G[y].push_back({x,z});
        lim=max(lim,z);
    }

    for(step=1;step<=lim;step<<=1);
    step>>=1;
    int x=0;
    for(;step;step>>=1)
    {
        memset(viz,0,sizeof viz);
        dfs(1,x+step);
        if(viz[n]) x+=step;
    }
    cout<<x;
    return 0;
}
#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
{
    int n(0),s(1);
    while(!(buf[pos]>='0' && buf[pos]<='9') && buf[pos]!='-') if(++pos>=maxb) f.read(buf,maxb),pos=0;
    if(buf[pos]=='-')
    {
        s=-1;
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    while((buf[pos]>='0' && buf[pos]<='9'))
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    return n*s;
}
