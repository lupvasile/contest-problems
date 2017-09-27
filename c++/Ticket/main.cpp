#include <iostream>
#include <string>
#include <map>
#include <deque>
//#include <fstream>

using namespace std;

int n,m,i,t;
int c[110];
struct
{
    string n,s;
} nume[110];
map <string,int> p;
bool deschis[110];
deque <int> coada[110];
deque <int> ::iterator it;
int x,caz,pers;
string s;
//ifstream f("date.in");
//#define cin f
int main()
{
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        cin>>nume[i].n>>nume[i].s;
        p[nume[i].n]=i;
        p[nume[i].s]=i;
        c[i]=-1;
    }
    cin>>t;
    for(; t; --t)
    {
        cin>>caz;
        if(caz==1)
        {
            cin>>x;
            deschis[x]=(!deschis[x]);
            if(!deschis[x]) while (!coada[x].empty())
                {
                    c[coada[x].front()]=-1;
                    coada[x].pop_front();
                }
        }
        else if (caz==2)
        {
            cin>>x>>s;
            pers=p[s];
            coada[x].push_back(pers);
            c[pers]=x;
        }
        else if(caz==3)
        {
            cin>>x;
            c[coada[x].front()]=-1;
            coada[x].pop_front();
        }
        else if(caz==4)
        {
            cin>>x;
            if(coada[x].empty() || (!deschis[x])) cout<<-1<<'\n';
            else
            {
                for(it=coada[x].end(),--it; it!=coada[x].begin(); --it) cout<<nume[*it].n<<' '<<nume[*it].s<<' ';
                cout<<nume[coada[x].front()].n<<' '<<nume[coada[x].front()].s<<'\n';
            }
        }
        else
        {
            cin>>s;
            pers=p[s];
            cout<<c[pers]<<'\n';
        }
    }

    return 0;
}
