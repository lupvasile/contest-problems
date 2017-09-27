#include <iostream>
#include <cstring>
using namespace std;
char s[30];
int rasp(0);
bool fonctie(int j);
void back(int nivel)
{
  if(nivel<4)
    {
      s[nivel]='a';
      if (fonctie(nivel)) rasp++;
      s[nivel]='b';
      if (fonctie(nivel)) rasp++;
      s[nivel]='c';
      if (fonctie(nivel)) rasp++;
      s[nivel]='a';
      back(nivel+1);
      s[nivel]='b';
      back(nivel+1);
      s[nivel]='c';
      back(nivel+1);
    }
}
bool fonctie(int j)
{
  int i;
  i=0;
  while(i<j && s[i]==s[j]) i++,j--;
  return (i>j);
}
int main()
{
  back(0);
  cout<<rasp<<' '<<strlen(s);
  return 0;
}
