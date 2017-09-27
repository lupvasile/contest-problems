#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream f("dir.in");
ofstream g("dir.out");
#define cout g
char stiva[260][31],c[2];
struct bbbb
    {
    char el[256];
    } cale[101];
int l(1),fisier,i;
bool ookk;
inline bool cmp(bbbb p,bbbb pp)
    {
    if (strcmp(p.el,pp.el)<0) return true;
    else return false;
    }
void construieste_cale()
    {
    int h;
    strcat(cale[fisier].el,stiva[1]);
    for(h=2; h<=l; h++)
        {
        strcpy(&cale[fisier].el[strlen(cale[fisier].el)],"\\");
        strcat(cale[fisier].el,stiva[h]);
        }
    }
int main()
    {
    f.get(c,2);
    while (c[0])
        {
        ookk=true;
        if (c[0]=='(')
            {
            l++;
            }
        else if (c[0]==')')
            {
            l--;
            }
        else if (c[0]==',') ;
        else
            {
            stiva[l][0]='\0';
            while (strchr(",() ",c[0])==NULL)
                {
                strcat(stiva[l],c);
                f.get(c,2);
                }
            if (stiva[l][0]>='a' && stiva[l][0]<='z')
                {
                fisier++;
                construieste_cale();
                }
            ookk=false;
            }
        if (ookk) f.get(c,2);
        }
    sort(cale+1,cale+fisier+1,cmp);
    cout<<fisier<<'\n';
    for(i=1; i<=fisier; i++)cout<<cale[i].el<<'\n';
    return 0;
    }
