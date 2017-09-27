#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//#define cout g
#define nmax 5000010

ifstream f("ATM/large/large-dag-0.in");
ofstream g("atm.out");

typedef vector<int>::iterator itt;
vector <int> G[nmax],G_t[nmax],componenta[nmax],G_c[nmax];
bool viz[nmax],pub[nmax],pub_componenta[nmax];
int i,n,m,x,y,c,p,start;
int rez;
int stack[nmax],st,in_care[nmax];
int bani[nmax],bani_componenta[nmax];
int d[nmax];//dinamica

#define nbuf 16384
char buf[nbuf];
int ptr(nbuf);

int gI()
{
    int nr(0);
    while (buf[ptr]<'0' || buf[ptr]>'9')
    {
        if (++ptr>=nbuf) f.read(buf,ptr),ptr=0;
    }
    while (buf[ptr]>='0' && buf[ptr]<='9')
    {
        nr=nr*10+buf[ptr]-'0';
        if (++ptr>=nbuf) f.read(buf,ptr),ptr=0;
    }
    return nr;
}
void dfs(int nod)
{
    viz[nod]=true;
    cout<<viz[440062]<<' '<<nod<<'\n';
    itt it;
    for(it=G[nod].begin(); it!=G[nod].end(); ++it)
        if (!viz[*it]) dfs(*it);
    stack[++st]=nod;
}

void dfs_t(int nod)
{
    viz[nod]=true;
    itt it;
    for(it=G_t[nod].begin(); it!=G_t[nod].end(); ++it) if(!viz[*it]) dfs_t(*it);
    componenta[c].push_back(nod);
    if(pub[nod]) pub_componenta[c]=true;
    bani_componenta[c]+=bani[nod];
    in_care[nod]=c;
}

void dfs_c(int nod,int c)
{
    viz[nod]=true;
    itt it;
    for(it=G[nod].begin(); it!=G[nod].end(); ++it)
        if (!viz[*it] && in_care[*it]==c) dfs_c(*it,c);
        else if (in_care[*it]!=c)
        {
            G_c[c].push_back(in_care[*it]);
        }
}

void dfs_d(int nod,int suma)
{
    if(d[nod]<suma+bani_componenta[nod])
    {
        d[nod]=suma+bani_componenta[nod];
        for(itt it=G_c[nod].begin(); it!=G_c[nod].end(); ++it)
            dfs_d(*it,d[nod]);
    }
}

int main()
{
    f>>n>>m;
    //n=gI();
    //m=gI();
    for(; m; --m)
    {
        f>>x>>y;
        //x=gI();
        //y=gI();
        G[x].push_back(y);
        G_t[y].push_back(x);
    }
    for(i=1; i<=n; ++i) f>>bani[i];
        //bani[i]=gI();
    f>>start>>p;
    //start=gI();
    //p=gI();
    for(; p; --p)
    {
        f>>x;
        //x=gI();
        pub[x]=true;
    }
   // cout<<"asdf\n";
   // for(itt it=G[262636].begin();it!=G[262636].end();++it) cout<<*it<<' ';

    for(i=1; i<=n; ++i) if(!viz[i]) dfs(i);
    for(i=1; i<=n; ++i) viz[i]=false;
    for(; st; --st)
        if(!viz[stack[st]]) ++c,dfs_t(stack[st]);

    //in c ai numarul de componente conexe
    //in G_c iti faci graful componentelor conexe
    for(i=1; i<=n; ++i) viz[i]=false;
    for(i=1; i<=c; ++i) dfs_c(componenta[i][0],i);
    for(i=1; i<=c; ++i) viz[i]=false;
    dfs_d(in_care[start],0);
    for(i=1; i<=c; ++i)
    {
        if (pub_componenta[i]) rez=max(rez,d[i]);
        //cout<<d[i]<<' ';
    }
    cout<<rez;
    return 0;
}
