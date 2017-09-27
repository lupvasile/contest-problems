#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("biperm.in");
ofstream g("biperm.out");

#define cout g
#define nmax 10010

vector <int> G[nmax],G_t[nmax];
int n,i,nrc,nr_arc,scad;
int a[nmax],b[nmax],cc[nmax],ap[nmax][2];//cc ii ciclu, ap[i] ii pe ce pozitie apare elem egal cu i

void ddelete(vector<int> &v,int val)
{
    /*int i;
    for(i=0;v[i]!=val;++i);
    v.erase(v.begin()+i);
    */
    for(vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        if(*it==val)
        {v.erase(it);
        return;
        }

    }
    return;
}

int dfs(int nod)
    {
    int pos;
    nr_arc+=1;
    for(int i=0; i<G[nod].size(); ++i)
    {
        int x=G[nod][i];
        G[nod].erase(G[nod].begin()+i);
        ddelete(G_t[x],nod);
        return dfs(x);
    }
    for(int i=0; i<G_t[nod].size(); ++i)
            {
            pos=a[ap[nod][0]]==G_t[nod][i] ? ap[nod][0]:ap[nod][1];
            swap(a[pos],b[pos]);
            int x=G_t[nod][i];
            G_t[nod].erase(G_t[nod].begin()+i);
            ddelete(G[x],nod);
            return 1+dfs(x);
            }
    return 0;
    }

int main()
    {
    f>>n;
    for(i=1; i<=n; ++i)
        {
        f>>a[i];
        if(ap[a[i]][0]) ap[a[i]][1]=i;
        else ap[a[i]][0]=i;
        }
    for(i=1; i<=n; ++i)
        {
        f>>b[i];
        if(ap[b[i]][0]) ap[b[i]][1]=i;
        else ap[b[i]][0]=i;
        G[a[i]].push_back(b[i]);
        G_t[b[i]].push_back(a[i]);
        if(a[i]==b[i]) scad++;
        }
    for(i=1; i<=n; ++i) if(G[i].size() || G_t[i].size())
            {
            nr_arc=0;
            cc[++nrc]=dfs(i);
            cc[nrc]=min(cc[nrc],nr_arc-1-cc[nrc]);
            cc[nrc]+=cc[nrc-1];
            }
    nrc-=scad;
    cout<<(1<<nrc)<<' '<<cc[nrc+scad]<<'\n';
    for(i=1;i<=n;++i) cout<<a[i]<<' ';
    cout<<'\n';
    for(i=1;i<=n;++i) cout<<b[i]<<' ';
    return 0;
    }
