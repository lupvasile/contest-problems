#include <iostream>
#include <fstream>

using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

#define nmax 1000010
#define cout g
int n,stack[nmax],st,maxx,i;
char s[nmax];
inline bool pereche(char a,char b)
{
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

int main()
{
    f>>n;
    s[0]=')';
    s[n+1]='(';
    stack[++st]=0;
    f>>s+1;
    for(i=1;i<=n;++i)
    if(pereche(s[stack[st]],s[i])) --st;
    else stack[++st]=i;
    stack[++st]=n+1;
    /*for(i=1;i<=st;++i) cout<<stack[i]<<' ';
    cout<<"\n";*/
    for(i=2;i<=st;++i) maxx=max(maxx,stack[i]-stack[i-1]);
    cout<<maxx-1;
    return 0;
}
