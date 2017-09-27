#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("teroristi.in");
ofstream fout("teroristi.out");
/// ////////////////////////////////

void read();
void gc(char &);

#define nmax 710
#define sigma 26
#define inf 0x3f3f3f3f

string s;
int source(0),sink(709),n;
vector<int> ziar[nmax],G[nmax];
int flux[nmax][nmax],dist[nmax],P[nmax];
queue<int> q;

inline int hhash(char a)
{
    return a-'a'+1;
}
inline int hhash(char a,char b)
{
    if(a>b) swap(a,b);
    return (int) (a-'a')*sigma+(b-'a')+27;
}

bool bfs()
{
    int nod;

    memset(dist,inf,sizeof dist);

    dist[source]=0;
    q.push(source);

    while(!q.empty())
    {
        nod=q.front();
        q.pop();

        for(auto vec:G[nod])
            if(flux[nod][vec] && dist[vec]>dist[nod]+1)
            {
                dist[vec]=dist[nod]+1;
                P[vec]=nod;
                if(vec!=sink) q.push(vec);
            }
    }

    return dist[sink]!=inf;
}

void make_flux()
{
    int minn,nod;

    while(bfs())
    {
        for(auto &it:G[sink])
        {
            if(flux[it][sink] && dist[it]!=inf)
            {
                minn=inf;
                P[sink]=it;

                for(nod=sink; nod!=source; nod=P[nod]) minn=min(minn,flux[P[nod]][nod]);

                if(minn)
                    for(nod=sink; nod!=source; nod=P[nod])
                    {
                        flux[P[nod]][nod]-=minn;
                        flux[nod][P[nod]]+=minn;
                    }
            }
        }
    }
    return ;
}

int main()
{
    char c;

    read();
    make_flux();

    for(int i=0; i<n; ++i)
        for(auto it:G[hhash(s[i])])
            if(flux[it][hhash(s[i])])
            {
                cout<<ziar[it].back()<<' ';
                ziar[it].pop_back();
                --flux[it][hhash(s[i])];
                break;
            }
    return 0;
}

void read()
{
    int i,m,hsh;
    char a,b;

    fin>>n>>m;
    fin>>s;

    for(i=0; i<n; ++i)
    {
        hsh=hhash(s[i]);
        ++flux[source][hsh];
        if(flux[source][hsh]==1)
        {
            G[source].push_back(hsh);
            G[hsh].push_back(source);
        }
    }

    for(i=1; i<=m; ++i)
    {
        gc(a);
        gc(b);
        hsh=hhash(a,b);

        ++flux[hsh][sink];

        if(flux[hsh][sink]==1)
        {
            G[sink].push_back(hsh);
            G[hsh].push_back(sink);
            G[hsh].push_back(hhash(a));
            G[hsh].push_back(hhash(b));
            G[hhash(a)].push_back(hsh);
            G[hhash(b)].push_back(hsh);
            flux[hhash(a)][hsh]=inf;
            flux[hhash(b)][hsh]=inf;
        }

        ziar[hsh].push_back(i);
    }


}

#define maxb 100000
int pos(maxb);
char buf[maxb];

void gc(char &c)
{
    while(buf[pos]<'a' || buf[pos]>'z')
        if(++pos>=maxb) fin.read(buf,maxb),pos=0;

    c=buf[pos];

    if(++pos>=maxb) fin.read(buf,maxb),pos=0;
}
