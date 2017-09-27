#include <iostream>
#include <string.h>
using namespace std;
char s[200],s1[200];
int i,n,minn;
int main()
{
    cin>>s1;
    n=strlen(s1);
    strcat(s,s1);
    strcat(s,s1);
    minn=1;
    for (i=1;i<=n-1;i++)
    {
        if (strcmp(s+minn,s+i)>=0) minn=i;
    }
    for(i=0;i<=n-1;i++)cout<<s[i+minn];
    return 0;
}
