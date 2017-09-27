#include <iostream>
#include <string.h>
using namespace std;
int v[28],i,n,k;
char c,s[10000];
int main()
{   cin.get(s,10000);
    n=strlen(s)-1;
    for(i=0;i<=n;i++) v[s[i]-'a']++;
    for(i=0;i<=27;i++) if (v[i]%2) k++;
    if (k<=1) cout<<"First";
    else if (k%2==0)cout<<"Second";
    else cout<<"First";
    return 0;
}
