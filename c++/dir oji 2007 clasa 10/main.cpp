#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;
ifstream f("dir.in");
ofstream g("dir.out");
#define cout g
char s[300][31],c[2];
struct bbbb{char el[256];} cale[100];
int h,l,fisier,poz[101],i,v[200],tata[300];

bool ok;
stack <int> stiva;
inline bool cmp(bbbb p,bbbb pp)
{
    if (strcmp(p.el,pp.el)<0) return true;
    else return false;
}
void construieste_cale(int i,int k)
    {
    v[0]=0;
    while (i!=0)
        {
        v[++v[0]]=i;
        i=tata[i];
        }
    strcat(cale[k].el,s[v[v[0]]]);
    for(h=v[0]-1; h>=1; h--)
        {
        strcpy(&cale[k].el[strlen(cale[k].el)],"\\");
        strcat(cale[k].el,s[v[h]]);
        //cout<<v[h]<<' ';
        }
    }
int main()
    {
    ok=true;
    f.get(c,2);
    while (c[0])
        {
        if (c[0]=='(')
            {
            ok=true;
            stiva.push(l);
            }
        else if (c[0]==')')
            {
            ok=true;
            stiva.pop();
            }
        else if (c[0]==',') ok=true;
        else
            {
            if (ok)
                {
                l++;
                if (c[0]>='a' && c[0]<='z')
                    {
                    fisier++;
                    poz[++poz[0]]=l;
                    }
                if (!stiva.empty()) tata[l]=stiva.top();
                }
            strcat(s[l],c);
            ok=false;
            }
        f.get(c,2);
        }
    //  cout<<l<<'\n';
    //for(i=1; i<=poz[0]; i++) //cout<<tata[i]<<" "<<i<<"\n";
    //  cout<<s[i]<<'\n';
    // cout<<poz[i]<<" ";
    for(i=1; i<=poz[0]; i++) construieste_cale(poz[i],i-1);//,cout<<'\n';
    sort(cale,cale+poz[0],cmp);
    cout<<fisier<<'\n';
    for(i=1; i<=fisier; i++)cout<<cale[i-1].el<<'\n';
    cout<<stiva[0];
    return 0;
    }
