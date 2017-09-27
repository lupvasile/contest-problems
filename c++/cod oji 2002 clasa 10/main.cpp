#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f("codul.in");
char s[202];
int a[201],b[201],i,na,nb,lcs[201][201],j;
void afisare(int i,int j)
{
if(i && j)
if(a[i]==b[j]) 
{afisare(i-1,j-1);
cout<<a[i];}
else if (lcs[i-1][j]>lcs[i][j-1]) afisare(i-1,j);
else afisare(i,j-1);
}
int main()
{
    f>>s;
    na=strlen(s);
    for(i=0;i<na;i++) a[i+1]=s[i]-'0';
    f>>s;
    nb=strlen(s);
    for(i=0;i<nb;i++) b[i+1]=s[i]-'0';
    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
            {
                if(a[i]==b[j]) lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
afisare(na,nb);
cout<<lcs[na][nb];
    return 0;
}
