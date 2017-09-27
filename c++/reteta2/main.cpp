#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

ifstream f("reteta2.in");
ofstream g("reteta2.out");
//#define cout g
#define tr(it,container) \
for(__typeof(container.begin()) it=container.begin();it!=container.end();++it)
map <string,int> m;
char c;
int nr,aux,timp;
string s;
int main()
{
    while (f>>c)
    {

        if (c=='(' || c==')') continue;
        while (c>='0' && c<='9')
        {
         nr=nr*10+c-'0';
         f>>c;
         if(!f.good()) break;
        }
        timp+=nr;
        nr=0;
        if (c>='a' && c<='z')
        {
            s="";
        while (c>='a' && c<='z')
        {
         s+=c;
         f.get(c);
        }
            f>>nr;
            m[s]+=nr;
            nr=0;
        }
    }
cout<<timp<<'\n';
   tr(it,m)
   {
       cout<<it->first<<' '<<it->second<<'\n';
       it->second=2;
   }
    tr(it,m)
   {
       cout<<it->first<<' '<<it->second<<'\n';
       it->second=2;
   }
       return 0;
}
