#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");
string nume,s,v[40001];
int nr,c,act,pas,l;
void termina(int i)
{
    cout<<i;
    exit;
}
int control(int nr)
{
    int aux;
    while (nr>9)
    {
        aux=nr;
        nr=0;
        while (aux)
        {
            nr+=aux%10;
            aux/=10;
        }
    }
    return nr;
}
int para()
{
    int nr(0),i;
    for(i=s.length()-1; i>1; --i)
    {
        nr=nr*10+s[i]-'0';
        if(s[i]==s[i-1] && !(s[i]%2))    --i;

    }
    return nr;
}
int impara()
{
    string p;
    int i=1,j(s.length()-1);
    while (i<s.length())
    {
        if(s[i]%2)
        {
            while (j && !(s[j]%2)) --j;
            p+=s[j];
            j-=2;
            i+=2;
        }
        else
        {
            p+=s[i];
            ++i;
            ++j;
        }
    }
    return atoi(p.data());
}
void deplasare(int c)
{
    int i=0,x;
    while (nume[i]>'9')
    {
        if(nume[i]>='a')
        {
            x=nume[i]-c;
            if(x<'a') x='Z'-('a'-x);
        }
        else
        {
            x=nume[i]-c;
            if(x<'A') x='z'-('A'-x);
        }
        nume[i]=x;
        ++i;
    }
}
int main()
{
    while (f>>nume)
    {
        f>>s;
        ++pas;
        nr=atoi(nume.substr(nume.length()-3).data());
        c=control(nr);
        deplasare(c);
        ++l;
        if(c%2==0) if(s[0]=='2') {
            act=para();
            v[l]=to_string(act);

        }
            else termina(pas);
        else if(s[0]=='1') act=impara();
        else termina(pas);
        cout<<nume;
    }
    return 0;
}