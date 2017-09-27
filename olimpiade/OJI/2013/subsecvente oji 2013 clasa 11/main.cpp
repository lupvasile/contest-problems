#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");

#define cout g

struct node
    {
    int cod;
    node *fii[2];
    node()
        {
        cod=0;
        fii[0]=fii[1]=0;
        }
    };

string s;
int n,i,j,mask(1),c,sol,full;
node *start,*p;

int main()
    {
    f>>n;
    f>>s;
    start=new node;
    for(i=0; i<s.size(); ++i)
        {
        p=start;
        for(j=1; j<=60 && (i+j-1)<s.size(); ++j)
            {
            c=s[i+j-1]-'a';
            if(p->fii[c]==0) p->fii[c]=new node;
            p=p->fii[c];
            p->cod|=mask;
            }
        }
    full=(1<<n)-1;
    for(--n,mask<<=1;n;--n,mask<<=1)
    {
        f>>s;
        for(i=0; i<s.size(); ++i)
        {
        p=start;
        for(j=1; j<=60 && (i+j-1)<s.size(); ++j)
            {
            c=s[i+j-1]-'a';
            if(p->fii[c]==0) break;
            p=p->fii[c];
            p->cod|=mask;
            if(p->cod==full) sol=max(sol,j);
            }

        }
    }
    cout<<sol;
    return 0;
    }
