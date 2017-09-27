#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif

ifstream fin("sabin.in");
ofstream fout("sabin.out");

#define dim 28
#define kmax 460
#define mmax 30010

struct TRIE
{
    TRIE* fii[dim];
    bool terminal;
    int lev,nr,gr;
    TRIE()
    {
        for(int i=0; i<dim; ++i) fii[i]=0;
        terminal=false;
        lev=nr=0;
    }
};

TRIE *root;
int n,p,k,q,m,len,res,grad;
char s[kmax],s1[kmax],cuv[mmax][33];

void add_trie(TRIE *nod,char *ch,int lev)
{
    ++(nod->nr);

    if(*ch=='\0') return;

    char x=*ch-'a';

    if(!(nod->fii[x]))
    {
        nod->fii[x]=new TRIE;
        TRIE &fiu=*nod->fii[x];

        fiu.lev=lev+1;
        if(fiu.lev%k==0)
        {
            fiu.terminal=true;
            fiu.gr=fiu.lev/k;
        }
    }
    add_trie(nod->fii[x],ch+1,lev+1);
}
void query(TRIE *nod,char *ch)
{
    if(nod->terminal)
    {
        if(nod->gr==grad) res+=nod->nr;
        if(nod->gr==grad+1)
        {
            res-=nod->nr;
            return;
        }
    }

    if(*ch=='\0') return;

    char x=*ch-'a';

    if(!(nod->fii[x])) return;
    query(nod->fii[x],ch+1);


}


int main()
{
    root=new TRIE;
    fin>>n>>k>>m>>p>>q;
    len=p*k;

    int i,j,h;
    s[len+1]='\0';

    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=k; ++j)
        {
            fin>>s1;
            for(h=0; h<p; ++h)
                s[k*h+j]=s1[h];
        }
        add_trie(root,s+1,0);
    }

    root->nr=n;
    root->terminal=true;
    root->gr=0;

    for(i=1; i<=m; ++i) fin>>cuv[i];

    for(; q; --q)
    {
        fin>>grad;
        for(j=1; j<=k; ++j)
        {
            fin>>i;
            for(h=0; h<p; ++h)
                s[k*h+j]=cuv[i][h];

        }
        res=0;
        query(root,s+1);
        cout<<res<<'\n';
    }

    return 0;
}
