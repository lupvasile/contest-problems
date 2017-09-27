#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int i,k;
    char s[50];
    strcpy(s,"1+2+3");
    k=0;
    for(i=1;i<strlen(s);i++)
    if(s[i]=='+')k=k+s[i-1];
    cout<<k;
    return 0;
}
