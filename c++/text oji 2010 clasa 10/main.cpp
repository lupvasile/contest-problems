#include <fstream>
#include <string.h>
using namespace std;
#define cout g
#define foor(i,a,b) for(i=a;i<=b;i++)
ifstream f("text3.in");
ofstream g("text3.out");
char s[20001][21];
short int lungime[20001],pred[20001],alfabet[26][20001];
short int c,l,i,h,j,maxx(0),pos,t;
void afisare(int i)
    {
    if (pred[i]>0) afisare(pred[i]);
    cout<<s[i]<<"\n";
    }
int main()
    {
    l=1;
    while (f>>s[l])
        {
        c=s[l][strlen(s[l])-1]-'a';
        alfabet[c][++alfabet[c][0]]=l;
        l++;
        }
    l--;
    cout<<l<<'\n';
    foor(i,1,l)
        {
        c=s[i][0]-'a';
        for(j=1;j<=alfabet[c][0] && alfabet[c][j]<i;j++)
            {

            if (lungime[alfabet[c][j]]+1>lungime[i])
                {
                lungime[i]=lungime[alfabet[c][j]]+1;
                pred[i]=alfabet[c][j];
                }
            if (lungime[i]>maxx)
                {
                maxx=lungime[i];
                pos=i;
                }
            }
        }
    cout<<l-maxx-1<<'\n';
    afisare(pos);
    //cout<<"*******\n";
    //cout<<alfabet[3][0];
    return 0;

    }
