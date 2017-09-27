#include <bits/stdc++.h>

using namespace std;

ifstream f("virus.in");
ofstream g("virus.out");

#define cout g
#define lmax 100001
#define kmax 1001

struct aho
    {
    int nr;
    vector<int> cuv;
    aho *fii[2],*fail;
    aho()
        {
        nr=0;
        cuv.clear();
        fii[0]=fii[1]=fail=0;
        }
    };

aho *root,*p;
int n,l,i,x,w,nr_ap_tot;
int ic,sc;
aho *q[kmax*kmax];
char text[lmax],s[kmax];
int nr_ap[kmax];

void add(aho *p,char *c)
    {
    if(*c=='\0')
        {
        p->cuv.push_back(i);
        return;
        }
    int w=*c-'0';
    if(p->fii[w]==0)  p->fii[w]=new aho;
    add(p->fii[w],c+1);
    }

void bfs()
    {
        int w;
        aho *nod,*fiu,*p;

        root->fail=root;
        ic=sc=0;
        q[ic]=root;
        while(ic<=sc)
        {
            nod=q[ic];
            ++ic;
            for(w=0;w<=1;++w)
            {
                fiu=nod->fii[w];
                if(fiu==0) continue;
                p=nod->fail;
                while(p->fii[w]==0 && p!=root) p=p->fail;
                if(p->fii[w] && p->fii[w]!=fiu) p=p->fii[w];
                fiu->fail=p;
                q[++sc]=fiu;
            }
        }
    }

void revbfs()
{
    int i;
    for(i=sc;i>=0;--i)
    {
        q[i]->fail->nr+=q[i]->nr;
        for(auto c:q[i]->cuv) nr_ap[c]+=q[i]->nr;
    }
}
int main()
    {
    root=new aho;
    f>>l>>n;
    f>>text;

    for(i=1; i<=n; ++i)
        {
        f>>x;
        f>>s;
        add(root,s);
        }

    bfs();
    p=root;
    for(i=0;i<l;++i)
    {
        w=text[i]-'0';
        while(p->fii[w]==0 && p!=root) p=p->fail;
        if(p->fii[w]) p=p->fii[w];
        ++p->nr;
    }
    revbfs();
    for(i=1;i<=n;++i) cout<<nr_ap[i]<<'\n';
    return 0;
    }
