#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
//#define cout g
#define foor(i,a,b) for(i=a;i<=b;i++)
ifstream f("text3.in");
ofstream g("text3.out");
char s[20001][21];
short int pred[20001];
short int c,l,i,h,j,maxx(0),pos,t;
struct
    {
    short int lungime,element;
    } dinamica[26];
void afisare(int i)
    {
    if (pred[i]>0) afisare(pred[i]);
    cout<<s[i]<<"\n";
    }
int main()
    {
    l=1;
    while (f>>s[l])
        {
        l++;
        }
    l--;
    cout<<l<<'\n';
    foor(i,1,l)
        {
        c=s[i][strlen(s[i])-1]-'a';
        if (dinamica[s[i][0]-'a'].lungime+1>dinamica[c].lungime)
            {
            dinamica[c].lungime=dinamica[s[i][0]-'a'].lungime+1;
            pred[i]=dinamica[s[i][0]-'a'].element;
            dinamica[c].element=i;
            }
        }
    foor(i,0,26) if(maxx<dinamica[i].lungime)
        {
        maxx=dinamica[i].lungime;
        pos=dinamica[i].element;
        }
    cout<<l-maxx<<'\n';
    afisare(pos);
    //cout<<"*******\n";
    //cout<<alfabet[3][0];
    return 0;

    }
