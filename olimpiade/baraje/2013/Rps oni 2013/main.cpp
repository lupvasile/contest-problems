#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("rps.in");
ofstream fout("rps.out");
/// ////////////////////////////////////////////////

#define inf 0x3f3f3f3f

struct NOD_T
{
    NOD_T* fii[3];
    int nr,such_son=-1,much_val;
    NOD_T()
    {
        nr=0;
        fii[0]=fii[1]=fii[2]=0;
    }
};

int n,k,win,rem,nr;
int nom[200];
char nomnom[4]="PRS";
char s[1000010];

void add_trie(NOD_T *pnod,char *p)
{
    ++pnod->nr;
    if(*p=='\0')
    {
        pnod->much_val=pnod->nr * rem;
        return;
    }

    int c=nom[*p],res;

    if(pnod->fii[c]==NULL) pnod->fii[c]=new NOD_T;

    add_trie(pnod->fii[c],p+1);

    pnod->much_val=-inf;

    for(c=0; c<3; ++c)
    {
        res=0;
        if(pnod->fii[c]) res+=pnod->fii[c]->much_val;
        if(pnod->fii[(c+1)%3]) res+=pnod->fii[(c+1)%3]->nr * win;
        if(res>pnod->much_val)
        {
            pnod->much_val=res;
            pnod->such_son=c;
        }
    }
}

void query(NOD_T *pnod)
{
    if(pnod->such_son==-1) return;

    ++nr;
    cout<<nomnom[pnod->such_son];

    if(pnod->fii[pnod->such_son]) query(pnod->fii[pnod->such_son]);
    else for(++nr;nr<=k;++nr) cout<<'P';
}

int main()
{
    NOD_T *root=new NOD_T;
    int i;

    nom['P']=0;
    nom['R']=1;
    nom['S']=2;

    fin>>n>>k>>win>>rem;
    for(i=1; i<=n; ++i)
    {
        fin>>s;
        nr=0;s
        add_trie(root,s);
        query(root);
        cout<<'\n';
    }
    return 0;
}
