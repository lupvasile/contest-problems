#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("expresie3.in");
ofstream g("expresie3.out");

#define cout g

char s[20100];
int i,p[27];
bool on[27];

void paranteza(int semn_init)
{
    int semn=semn_init;
    while (i<strlen(s))
    {
        if(s[i]=='(') ++i,paranteza(semn);
        else p[s[i]-'a']+=semn,on[s[i]-'a']=true;
        ++i;
        if(s[i]==')') return;
        if(s[i]=='/') semn=-semn_init;
        else semn=semn_init;
        ++i;
    }
    return;
}

int main()
{
    f>>s;
    paranteza(1);
    for(i=0;i<=26;++i) if(on[i])cout<<(char)(i+'a')<<' '<<p[i]<<'\n';
     return 0;
}
