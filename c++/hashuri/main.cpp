#include <iostream>
#include <fstream>
#include <list>
using namespace std;
#define mod 666013
#define cout g
ifstream f("hashuri.in");
ofstream g("hashuri.out");
int n,x,tip;
list <int> v[mod];
list <int>::iterator find(int val)
{
list <int>::iterator  it;
for(it=v[x%mod].begin();it!=v[x%mod].end();++it) if (*it==x) return it;
return it;
}
void add(int x)
{
if (find(x)==v[x%mod].end()) v[x%mod].push_back(x);
}
void del(int x)
{
    list<int> ::iterator i;
    i=find(x);
    if(i!=v[x%mod].end()) v[x%mod].erase(i);
}
int main()
{
  f>>n;
  for(; n; --n)
    {
      f>>tip>>x;
      switch (tip)
        {
        case 1:
          add(x);
          break;
        case 2:
          del(x);
          break;
        case 3:
          cout<<(find(x)!=v[x%mod].end())<<'\n';
          break;
        }
    }
  return 0;
}
