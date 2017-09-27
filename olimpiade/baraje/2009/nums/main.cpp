#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("nums.in");
ofstream fout("nums.out");
/// ////////////////////////////////

void read();

#define nmax 100003

int n,len;
int aib[nmax],ind[nmax],mp[nmax];
bool skip[nmax];
string v[nmax];

struct {int tip,pos;} op[nmax];
pair<int,int> hsh[nmax][2];

void update_aib(int pos)
{
    for(; pos<nmax; pos+=(pos&(-pos))) ++aib[pos];
}

int query_aib(int k)
{
    int step,pos=0;
    step=65536;
    for(; step; step>>=1)
        if(pos+step<=len)
            if(aib[pos+step]<k)
            {
                pos+=step;
                k-=aib[pos];
            }

    return pos+1;
}

bool cmp(int a,int b)
{
    if(v[a].size()!=v[b].size()) return v[a].size()<v[b].size();
    return v[a]<v[b];
}

int main()
{
    int i;

    read();
    sort(ind+1,ind+len+1,cmp);
    for(i=1; i<=len; ++i) mp[ind[i]]=i;
    for(i=1;i<=len;++i) if(v[ind[i-1]].size()==v[ind[i]].size()) if(v[ind[i]]==v[ind[i-1]]) mp[ind[i]]=mp[ind[i-1]];

    for(i=1;i<=n;++i)
        if(op[i].tip==1) if(skip[mp[op[i].pos]])continue;
        else update_aib(mp[op[i].pos]),skip[mp[op[i].pos]],skip[mp[op[i].pos]]=true;
        else cout<<v[ind[query_aib(op[i].pos)]]<<'\n';

        return 0;
}

void read()
{
    int i;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>op[i].tip;
        if(op[i].tip==1)
        {
            fin>>v[++len];
            make_hash(len);
            ind[len]=len;
            op[i].tip=1;
            op[i].pos=len;
        }
        else
        {
            fin>>op[i].pos;
        }
    }
}
