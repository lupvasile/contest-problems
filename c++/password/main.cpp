#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("password.in");
ofstream g("password.out");
char s[200002],s1[200002];
int i,n,minn,j;
int compara(char *p1,char *p2)
{
    for(j=0;j<=n-1;j++) if(*(p2+j)<*(p1+j)) return 1;
    else if(*(p2+j)>*(p1+j)) return -1;
    return -1;

}
int main()
{
    f>>s1;
    n=strlen(s1);
    strcat(s,s1);
    strcat(s,s1);
    minn=1;
    for (i=1;i<=n-1;i++)
    {
        if (compara(s+minn,s+i)>0) minn=i;
        //if(strcmp(s+minn,s+i)>0) minn=i;
    }
    g<<minn;
    return 0;
}
