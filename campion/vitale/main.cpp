#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream f("vitale.in");
ofstream g("vitale.out");
#define cout g

#define nmax 50010
#define foor(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)

int n,m,i;
vector <int> G[nmax];

int dad[nmax],up[nmax];
bool viz[nmax];
struct elem
    {
    int a,b,c;
    bool operator < (elem b) const
        {
        return  c<b.c;
        }
    };
elem muc[2*nmax];
    struct elem_stack
        {
        int nod,level,p;
        } sstack[nmax];
int todo[10*nmax],lt;

///******************************
#define mb 100018
char b[mb];

int p(mb);
int gi()
    {
    int n=0;
    while (b[p]<'0' || b[p]>'9') if(++p>=mb) f.read(b,mb),p=0;
    while (b[p]>='0' && b[p]<='9')
        {
        n=n*10+b[p]-'0';
        if(++p>=mb) f.read(b,mb),p=0;
        }
    return n;
    }
void read();
///********************
vector<pair<int,int > >sol;
int det_father(int a)
    {
    if(dad[a]!=a) dad[a]=det_father(dad[a]);
    return dad[a];
    }

void uneste(int a,int b)
    {
    a=det_father(a),b=det_father(b);
    if(a!=b) dad[b]=a;
    }
elem_stack make_stack(int a,int b,int c)
{
elem_stack e;
e.nod=a;
e.level=b;
e.p=c;
return e;
}
void dfs_iterativ(int nod,int level,int p)
    {

    int st(0);
    int vecin;
    sstack[++st]=make_stack(nod,level,p);
    while(st)
        {
        vasi:;
        nod=sstack[st].nod;
        level=sstack[st].level;
        p=sstack[st].p;
        viz[nod]=true;
        up[nod]=level;
        foor(it,G[nod])
            {
            vecin=(nod!=det_father(muc[*it].a) ? det_father(muc[*it].a):det_father(muc[*it].b));
            if(!viz[vecin])
                {
                sstack[++st]=make_stack (vecin,level+1,nod);
                goto vasi;
                }
            }
        foor(it,G[nod])
            {
            vecin=(nod!=det_father(muc[*it].a) ? det_father(muc[*it].a):det_father(muc[*it].b));
            if(up[vecin]>level)
                {
                sol.push_back(make_pair(min(muc[*it].a,muc[*it].b),max(muc[*it].a,muc[*it].b)));
                }
            if(vecin!=p)up[nod]=min(up[nod],up[vecin]);
            else
                {
                foor(itt,G[nod]) if(*it!=*itt && (det_father(muc[*itt].a)==p || det_father(muc[*itt].b)==p)) up[nod]=min(up[nod],up[vecin]);
                }
            }
        --st;
        }
    }

void dfs(int nod,int level,int p)
    {
    int vecin;
    viz[nod]=true;
    up[nod]=level;
    foor(it,G[nod])
        {
        vecin=(nod!=det_father(muc[*it].a) ? det_father(muc[*it].a):det_father(muc[*it].b));
        if(!viz[vecin])
            {
            dfs(vecin,level+1,nod);
            if(up[vecin]>level)
                {
                sol.push_back(make_pair(min(muc[*it].a,muc[*it].b),max(muc[*it].a,muc[*it].b)));
                }

            }
        if(vecin!=p)up[nod]=min(up[nod],up[vecin]);
        else
            {
            foor(itt,G[nod]) if(*it!=*itt && (det_father(muc[*itt].a)==p || det_father(muc[*itt].b)==p)) up[nod]=min(up[nod],up[vecin]);
            }
        }
    }

void det_critic()
    {
    int i;
  //  for(i=1; i<=n; ++i) viz[i]=false;
    for(i=1; i<=lt; ++i) if(!viz[todo[i]]) dfs_iterativ(todo[i],1,0);
    }

void kruskal()
    {
    int j,x,y,h;
    for(i=1; i<=n; ++i) dad[i]=i;
    for(i=1; i<=m; ++i)
        {
        if(muc[i].c!=muc[i-1].c)
            {
            j=i;
            //for(h=1; h<=n; ++h) G[h].clear();
            while (muc[j].c==muc[i].c && j<=m) ++j;
            --j;
            for(h=i; h<=j; ++h)
                {
                x=det_father(muc[h].a);
                y=det_father(muc[h].b);
                G[x].push_back(h);
                G[y].push_back(h);
                viz[x]=false;
                viz[y]=false;
                todo[++lt]=x;
                todo[++lt]=y;
                }
            det_critic();
            for(;lt;--lt) G[h].clear();
            for(h=i; h<=j; ++h) uneste(muc[h].a,muc[h].b);
            //for(h=1;h<=n;++h) cout<<det_father(h)<<' ';
            //cout<<'\n';
            i=j;
            }
        }
    }
void write()
    {
    sort(sol.begin(),sol.end());
    cout<<sol.size()<<'\n';
    foor(it,sol) cout<<(it->first)<<' '<<(it->second)<<'\n';
    }
int main()
    {
    read();
    kruskal();
    write();
    return 0;
    }



void read()
    {
    n=gi(),m=gi();
    for(i=1; i<=m; ++i)
        {
        muc[i].a=gi();
        muc[i].b=gi();
        muc[i].c=gi();
        }
    sort(muc+1,muc+m+1);
    }
