#include <bits/stdc++.h>

using namespace std;

ifstream fin("drumuri4.in");
ofstream fout("drumuri4.out");

#define nmax 40001
#define inf 0x3f3f3f3f
#define cout fout

int n,m,k,tip,x,y,i;
int vec[nmax][2],kvec[nmax][2],p[nmax],vi[nmax],vj[nmax],diri[nmax],dirj[nmax];

void find_node(int i,int j,int dist,int &nod,int &d)
    {
    int dir;
    d=0;
    nod=i;
    if(vec[nod][0]==j) dir=1;
    else dir=0;

    while(1)
        {
        if(d+k>dist) break;
        if(kvec[nod][dir]==0) break;
        j=nod;
        nod=kvec[nod][dir];
        if(kvec[nod][dir]==j) dir=1-dir;
        d+=k;
        }

    while(1)
        {
        if(d+1>dist) break;
        if(vec[nod][dir]==0) break;
        j=nod;
        nod=vec[nod][dir];
        if(vec[nod][dir]==j) dir=1-dir;
        ++d;
        }

    }

void update_kvec(int i,int j,bool ok)
    {
    int di(0),dj(0),u,v,h;

    u=i;
    v=j;
   if(vec[u][0]==v) diri[0]=0;
   if(vec[u][1]==v) diri[0]=1;
    while(u && di<k)
        {
        vi[di]=u;
        if(vec[u][0]==v)
            {
            v=u;
            u=vec[u][1];
            diri[di]=0;
            }
        else
            {
            v=u;
            u=vec[u][0];
            diri[di]=1;
            }
        ++di;
        }

    u=j;
    v=i;
    if(vec[u][0]==v) dirj[0]=0;
    if(vec[u][1]==v) dirj[0]=1;
    while(u && dj<k)
        {
        vj[dj]=u;
        if(vec[u][0]==v)
            {
            v=u;
            u=vec[u][1];
            dirj[dj]=0;
            }
        else
            {
            v=u;
            u=vec[u][0];
            dirj[dj]=1;
            }
        ++dj;
        }

    for(h=0; h<di; ++h)
        {
        v=k-h-1;
        if(ok)
            {
            if(v<dj) kvec[vi[h]][diri[h]]=vj[v];
            }
        else kvec[vi[h]][diri[h]]=0;
        }

    for(h=0; h<dj; ++h)
        {
        v=k-h-1;
        if(ok)
            {
            if(v<di) kvec[vj[h]][dirj[h]]=vi[v];
            }
        else kvec[vj[h]][dirj[h]]=0;
        }
    }

bool add(int x,int y)
    {
    if((vec[x][0] && vec[x][1]) || (vec[y][0] && vec[y][1]) || p[x]==y || x==y) return false;

    if(vec[x][0]) vec[x][1]=y;
    else vec[x][0]=y;
    if(vec[y][0]) vec[y][1]=x;
    else vec[y][0]=x;

    update_kvec(x,y,1);

    int a=p[x],b=p[y];
    p[x]=0;
    p[y]=0;
    p[a]=b;
    p[b]=a;

    return true;
    }

bool ddel(int x,int y)
    {
    int a,b;
    if(vec[x][1]!=y and vec[x][0]!=y) return false;

    find_node(x,y,1<<30,a,b);
    b=p[a];

    update_kvec(x,y,0);

    if(vec[x][0]==y) vec[x][0]=0;
    else vec[x][1]=0;
    if(vec[y][0]==x) vec[y][0]=0;
    else vec[y][1]=0;

    p[x]=a;
    p[a]=x;
    p[y]=b;
    p[b]=y;

    return true;
    }
string det_vec(int nod,int dist,bool ok)
    {
    stringstream ss;
    int c1,d1,c2,d2;
    find_node(nod,vec[nod][0],dist,c1,d1);
    find_node(nod,vec[nod][1],dist,c2,d2);
    if(c1>c2) swap(c1,c2),swap(d1,d2);
    if(ok)
        {
        if(c1!=c2) ss<<"2 "<<c1<<' '<<c2;
        else ss<<"1 "<<c1;
        }
    else
        {
        if(d1!=dist && d2!=dist) ss<<"0";
        else if(d1==dist && d2==dist && c1!=c2) ss<<"2 "<<c1<<' '<<c2;
        else if(d1==dist) ss<<"1 "<<c1;
        else ss<<"1 "<<c2;
        }
    return ss.str();
    }
int main()
    {
    fin>>n>>m;
    for(k=1; k*k<=n; ++k);
    --k;
    for(i=1; i<=n; ++i) p[i]=i;
    for(; m; --m)
        {
        fin>>tip>>x;
        if (tip<4)
            {
            fin>>y;
            if(tip==1) cout<<add(x,y)<<'\n';
            else if(tip==2) cout<<ddel(x,y)<<'\n';
            else
                {
                cout<<det_vec(x,y,0)<<'\n';
                }
            }
        else cout<<det_vec(x,1<<30,1)<<'\n';

        }
    return 0;
    }
