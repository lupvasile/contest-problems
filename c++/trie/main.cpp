#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("trie.in");
ofstream g("trie.out");

#define ch(x) (*x-'a')
#define cout g
int tip;
char s[21];

struct trie
{
  int words,nr_fii;
  trie * fiu[26];
  trie ()
  {
    words=nr_fii=0;
    memset(fiu,0,sizeof(fiu));
  }
};
trie *T=new trie;

void add(trie *nod,char *p)
{
  if (*p=='\0') nod->words+=1;
  else
    {
      if (nod->fiu[ch(p)]==0) nod->fiu[ch(p)]=new trie,nod->nr_fii+=1;
      add(nod->fiu[ch(p)],p+1);
    }
}
bool ddelete(trie *nod, char *p)
{
  if (*p=='\0') nod->words-=1;
  else if(ddelete(nod->fiu[ch(p)],p+1))
    {
      nod->nr_fii--;
      nod->fiu[ch(p)]=0;

    }
  if (nod->nr_fii==0 && nod->words==0 && nod!=T)
    {
      delete nod;
      return 1;
    }
  return 0;
}
int aparitii(trie *nod, char *p)
{
  if (*p=='\0') return nod->words;
  if (nod->fiu[ch(p)]) return aparitii(nod->fiu[ch(p)],p+1);
  return 0;
}
int prefix(trie *nod,char *p)
{
  if (*p=='\0') return 0;
  if (nod->fiu[ch(p)]) return 1+prefix(nod->fiu[ch(p)],p+1);
  return 0;
}
int main()
{
  while (f>>tip)
    {
      f>>s;
      switch(tip)
        {
        case 0:
          add(T,s);
          break;
        case 1:
          ddelete(T,s);
          break;
        case 2:
          cout<<aparitii(T,s)<<'\n';
          break;
        case 3:
          cout<<prefix(T,s)<<'\n';
          break;
        }
    }
  return 0;
}
