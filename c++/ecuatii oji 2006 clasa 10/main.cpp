#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

//ifstream f("teste/0-ec.in");
ifstream f("ecuatii2.in");

ofstream g("ecuatii2.out");
#define cout g
bool ok;
long long int nr,op,n,i,p,dreapta,cx;
char s[260];
void rezolva()
    {
    dreapta=0;
    cx=0;
    op=1;
    p=0;
    while (s[p]!='=')
        {
        ok=true;
        if (s[p]=='+') op=1;

        else if (s[p]=='-')op=-1;
        else if (s[p]=='x') cx+=op;
        else
            {
            nr=0;
            while (s[p]>='0' && s[p]<='9')
                {
                nr=nr*10+(s[p]-'0');
                p++;
                }
            if (s[p]=='x')cx+=op*nr;
            else
                {
                dreapta-=op*nr;
                ok=false;
                }
            }
        if (ok)p++;
        }
    p++;
    op=1;
    while (p<strlen(s))
        {
        ok=true;
        if (s[p]=='+') op=1;

        else if (s[p]=='-')op=-1;
        else if (s[p]=='x') cx-=op;
        else
            {
            nr=0;
            while (s[p]>='0' && s[p]<='9' && p<strlen(s))
                {
                nr=nr*10+(s[p]-'0');
                p++;
                }
            if (s[p]=='x')cx-=op*nr;
            else
                {
                dreapta+=op*nr;
                ok=false;
                }
            }
        if (ok)p++;
        }
    }
int main()
    {
    f>>n;
    for(i=1; i<=n; i++)
        {
        //s[0]='\0';
        f>>s;
        rezolva();
        if(cx!=0)cout<<fixed<<setprecision(4)<<(double)dreapta/cx<<'\n';
        else if(dreapta==0)cout<<"infinit\n";
        else cout<<"inposibil\n";
        }
    //cout<<cx<<" "<<dreapta;
    return 0;
    }
