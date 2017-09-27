#include <iostream>
#include <fstream>

using namespace std;

ifstream f("coins.in");
ofstream g("coins.out");

int semn[3],st[3][4],dr[3][4];
bool normal[13],v[13];
char c;
int i,j,h;

int main()
{
    for(i=0; i<=2; ++i)
    {
        for(j=0; j<=3; ++j) f>>st[i][j];
        f>>c;
        if(c=='=') semn[i]=0;
        else if (c=='<') semn[i]=-1;
        else semn[i]=1;
        for(j=0; j<=3; ++j) f>>dr[i][j];
        if(semn[i]=='=') for(j=0; j<=3; ++j) normal[st[i][j]]=normal[dr[i][j]]=true;
        els
        {
            for(h=1; h<=12; ++h) v[h]=true;
            for(j=0; j<=3; ++j) v[st[i][j]]=v[dr[i][j]]=false;
            for(h=1; h<=12; ++h) if(v[h]) normal[h]=true;
        }
    }
    for(h=1;h<=12;++h) if(!normal[h]) cout<<h<<'\n';
    return 0;
}
