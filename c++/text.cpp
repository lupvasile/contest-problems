#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;
ifstream f("text.in");
ofstream g("text.out");

int main()
{
    int n;
    f>>n;
    f.get();
    char l[1001],s[1001],*p;

    while (!f.eof())
    {
        f.get(s,1001);
        //cout<<s<<"\n";
        f.get();
        while (s[0]==' ') strcpy(s,s+1);     //scot spatii de la inceput
        while (p=strstr(s,"  ")) strcpy(p,p+1); //scot spatii de pe parcurs
        if (s[strlen(s)-1]==' ') s[strlen(s)-1]=0;  //scot spatiu de la sfarsit
        //cout<<s<<"\n";

        while (strlen(s)>n)
            {

            }
    }
    f.close();
    return 0;
}
