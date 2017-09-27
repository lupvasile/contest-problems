#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;


ifstream f("ahocorasick.in");
ofstream g("ahocorasick.out");

#define cout g
#define foor(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define lmax 1000010
#define lmaxc 10010
#define dim_A 26//dimensiunea alfabetului

char text[lmax],cuv[lmaxc];
int nr_cuv,i,urm,sol[105];
int ic,sc;//inceputul si finalul cozii
struct nd_trie
{
    vector <int> lcuv;//lista cu cuvintele ce se termina aici
    int nr_ap;//de cate ori am facut match in acest nod
    nd_trie *fii[dim_A],*fail;
    nd_trie()
    {
        nr_ap=0;
        memset(fii,0,sizeof (fii));
    }
};
nd_trie *trie,*q[lmaxc*102],*p;

void ins(nd_trie *pnod,char *c,int nr)
{
    if(*c=='\0')
    {
        pnod->lcuv.push_back(nr);
        return;
    }
    int urm=*c-'a';
    if(pnod->fii[urm]==NULL) pnod->fii[urm]=new nd_trie;
    ins(pnod->fii[urm],c+1,nr);
}

void bfs()
{
    nd_trie *pnod,*p;
    trie->fail=trie;
    for(q[ic=sc=1]=trie;ic<=sc;++ic)
    {
        pnod=q[ic];
        for(i=0;i<dim_A;++i)
            if(pnod->fii[i]!=NULL)
        {
            for(p=pnod->fail;p!=trie && p->fii[i]==NULL;p=p->fail);//merg in sus pana pot continua cu litera respectiva
            if(p->fii[i]!=NULL && p->fii[i]!=pnod->fii[i]) p=p->fii[i];///neaparat p->fii[i]!=pnod->fii[i]
            pnod->fii[i]->fail=p;
            q[++sc]=pnod->fii[i];
        }
    }
}

void antibfs()
{
    nd_trie *p;
    for(;sc;--sc)
    {
        p=q[sc];
        p->fail->nr_ap+=p->nr_ap;
        foor(it,p->lcuv) sol[*it]+=p->nr_ap;
    }
}

int main()
{
    trie=new nd_trie;
    f>>text;
    f>>nr_cuv;
    for(i=1;i<=nr_cuv;++i)
    {
        f>>cuv;
        ins(trie,cuv,i);
    }
    bfs();//ca sa faci failu
    p=trie;
    for(char *c=text;*c!='\0';++c)
    {
        urm=*c-'a';
        for(;p->fii[urm]==NULL && p!=trie;p=p->fail);
        if(p->fii[urm]!=NULL) p=p->fii[urm];
        ++p->nr_ap;
    }

    antibfs();//faci bfs invers sa determini nr de aparitii la fiecare cuvant
    for(i=1;i<=nr_cuv;++i) cout<<sol[i]<<'\n';//numarul de aparitii la fiecare cuvant din dictionar
    return 0;
}
