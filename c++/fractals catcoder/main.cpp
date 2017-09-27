#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
//#define cin f
int length,iterations,perimetru,i,nr;
void reading()
    {
    char *pp,s[10000];
    cin.get(s,1000);
    pp=strstr(s,"Length=");
    pp+=7;
    while(*pp>='0' && *pp<='9')
        {
        length=length*10+*pp-'0';
        pp++;
        }
    pp=strstr(s,"Iterations=");
    pp+=11;
    while(*pp>='0' && *pp<='9')
        {
        iterations=iterations*10+*pp-'0';
        pp++;
        }
    }
int main()
    {
    reading();
    length=243;iterations=3;
    perimetru=3*length;
    nr=3;
    for(i=1; i<=iterations; i++)
        {
        length=length/3;
        perimetru=perimetru+nr*length;
        nr=nr*2;
        }
    cout<<perimetru;
    return 0;
    }
