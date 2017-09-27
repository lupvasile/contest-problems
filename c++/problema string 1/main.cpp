#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
ifstream f("date.in");
char text[1000],aux[1000],cuv1[10],cuv2[10],*p;
int main()
{
    f.get(text+1,1000);
    f>>cuv1+1>>cuv2;
    text[0]=' ';
    cuv1[0]=' ';
    strcat(cuv1," ");
    strcat(text," ");
    //text[0]=' ';
    while (strstr(text,cuv1))
    {
        p=strstr(text,cuv1);
        strcpy(aux,p+strlen(cuv1)-1);
        p[1]='\0';
        strcat(text,cuv2);
        strcat(text,aux);
    }
    text[strlen(text)-1]='\0';
    cout<<text+1;
    return 0;
}
