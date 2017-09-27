#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream f("reteta2.in");
ofstream g("reteta2.out");
char s[1001],c;
#define cout g
struct element
    {
    char nume[1000]; int cant;
    };
element v[101],aux;
int timp,cantitate;
bool ok(true);
//in v[0].cant tii minte lungimea lui v
int citeste_numar()
    {
    int nr(0);
    while (c<'0' || c>'9') f>>c;
    while (c>='0' && c<='9'&& !f.eof())
        {
        nr=nr*10+c-'0';
        f>>c;
        }
    ok=false;
    return nr;
    }
void citeste_nume()
    {
    int i;
    for(i=0; c>='a' && c<='z'; i++)
        {
        s[i]=c;
        f>>c;
        }
    s[i]='\0';
    }
void binsrc()
    {
        bool ook(true);
    int n,st(1),dr(v[0].cant),m,i;
    while (st<=dr && ook)
        {
        m=(st+dr)/2;
        n=strcmp(s,v[m].nume);
        if (n==0)
            {
            ook=false;
            v[m].cant+=cantitate;
            }
        else if(n<0)
            {
            dr=m-1;
            }
        else
            {
            st=m+1;
            }
        }
    if (ook)
    {   v[0].cant++;
        for (i=v[0].cant;i>=st+1;i--) v[i]=v[i-1];
        v[st].cant=cantitate;
        strcpy(v[st].nume,s);
    }

    }
void citire()
    {

    while (!f.eof())
        {
        if (ok) f>>c;
        ok=true;
        if (c>='a' && c<='z')
            {
            citeste_nume();
            cantitate=citeste_numar();
            //cout<<s<<" "<<cantitate<<"\n";
            binsrc();
            }
        else if (c==')')
            {
            timp+=citeste_numar();
            //cout<<"asdf";
            }
        }
    }
int main()
    {
    citire();
    cout<<timp<<'\n';
    for(int i(1);i<=v[0].cant;i++)
    {
        cout<<v[i].nume<<' '<<v[i].cant<<'\n';
    }
    return 0;
    }
