/*#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
using namespace std;
ifstream f("password.in");
ofstream g("password.out");
char s[200002],s1[200002];
int i,n,minn,j;
deque <int> l;
////////////////////********&&&&&&&
varianta 1
 for (i=1;i<=n-1;i++)
    {
        if(strcmp(s+minn,s+i)>0) minn=i;
    }/
int compara(int a,int b)
{
    int i;
    for (i=0;i<=b-a-1;i++)
    if (s[a+i]<s[b+i]) return 1;
    else if (s[a+i]>s[b+i]) return 0;
    return 1;
}
void afisare()
{
    deque <int>::iterator i;
    for(i=l.begin();i!=l.end();i++) cout<<*i<<' ';
    cout<<'\n';
}
int main()
{
    f>>s1;
    n=strlen(s1);
    strcat(s,s1);
    strcat(s,s1);
    minn=1;
    //while (!l.empty()) l.pop_back();
    for(i=0;i<=n-1;i++) l.push_back(i);
    //cout<<l.front();
    deque <int>::iterator j,aux;
    //cout<<"asdfasdf "<<*(l.end()-1)<<'\n';
     while(l.begin()+1!=l.end())
    {
        j=l.begin();
        while(j+1<l.end())
        {   aux=j;
            if (compara(*j,*(j+1))) l.erase(j+1);
            else l.erase(j);
            j=aux+2;
           //cout<<*(j)<<" "<<*l.end()<<'\n';
           //afisare();
        }
       // cout<<"asdfasdfasdfasdf\n";

    }
    g<<l.front();
    return 0;
}
*/
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("password.in");
ofstream g("password.out");
char s[200002],s1[200002];
int i,n,minn,j,p1,p2,k;
bool sters[100001];
int compara(int a,int b)
{
    int i;
    for (i=0;i<=b-a-1;i++)
    if (s[a+i]<s[b+i]) return 1;
    else if (s[a+i]>s[b+i]) return 0;
    return 1;
}
int main()
{
    f>>s1;
    n=strlen(s1);
    strcat(s,s1);
    strcat(s,s1);
    k=n-1;
    while(k>1)
    {
        p1=1;
        while(sters[p1] && p1<=n-1) p1++;
        p2=p1+1;
        while(sters[p2] && p2<=n-1) p2++;
        while(p1<p2 && p2<=n-1)
        {
            if (compara(p1,p2)) sters[p2]=true;
            else sters[p1]=true;
            k--;
            p1++;
            while(sters[p1] && p1<=n-1) p1++;
            p2++;
            while(sters[p2] && p2<=n-1) p1++;
        }
    }
    i=1;
    while(sters[i]) i++;
    g<<i;
    return 0;
}