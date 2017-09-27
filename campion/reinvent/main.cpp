#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("reinvent.in");
ofstream g("reinvent.out");

#define cout g
#define nmax 100010
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)

int n,a,m,b,c,nod;
queue <int> Q;
vector <int> G[nmax];
int dist[nmax];
bool viz[nmax];
int src[nmax];
int gi();

int main()
{
    n=gi();
    m=gi();
    c=gi();
    for(;m;--m)
    {
        a=gi();
        b=gi();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(;c;--c)
    {
        a=gi();
        Q.push(a);
        viz[a]=true;
        src[a]=a;
    }
    while(1)
    {
        nod=Q.front();
        Q.pop();
        foor(it,G[nod]) if(viz[a=*it] && src[*it]!=src[nod])
        {
            cout<<dist[nod]+dist[*it]+1;
            return 0;
        }
        else if(!viz[*it])
        {
            viz[*it]=true;
            dist[*it]=dist[nod]+1;
            src[*it]=src[nod];
            Q.push(*it);
        }
    }
    return 0;
}

#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
{
    int n=0;
    while( buf[pos]<'0' || buf[pos]>'9') if(++pos>=maxb) f.read(buf,maxb),pos=0;
    while(buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    return n;
}
