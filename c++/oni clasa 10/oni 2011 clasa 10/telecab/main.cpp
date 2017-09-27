#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream f("telecab.in");
ofstream g("telecab.out");

#define cout g
#define nmax 100010
#define inf 0x3f3f3f3f3f
int n,k,s,cota[nmax],stiva[nmax],st,i,neext[nmax],m[1010][1010];//m[i][j] timpul minim sa ajungi in i cu j bani
int j,l_traseu;//lungimea traseului
int dist(int i,int j)
{
    return sqrt((j-i)*(j-i)+(cota[j]-cota[i])*(cota[j]-cota[i]));
}
int main()
{
    f>>n>>k>>s;
    for(i=1; i<=n; ++i)
    {
        f>>cota[i];
        while (cota[stiva[st]]<cota[i] && st) neext[stiva[st]]=i,--st;
        stiva[++st]=i;
    }
    for(; st; --st) neext[stiva[st]]=stiva[st]+1;
    for(i=1; i<n; i=neext[i])
        l_traseu+=dist(i,neext[i]);
    for(i=0; i<=1009; ++i) for(j=0; j<=s; ++j) m[i][j]=inf;

    for(j=0; j<=s; ++j) m[1][j]=0;

    for(i=1; i<k; i=neext[i])
    {
        for(j=0; j<=s; ++j)
            if (cota[i]==cota[neext[i]]) m[neext[i]][j]=min(1+m[i][j],m[neext[i]][j]);
            else if(cota[i]<cota[neext[i]])
            {
                if(j+cota[neext[i]]-cota[i]<=s)   m[neext[i]][j+cota[neext[i]]-cota[i]]=min(m[i][j]+dist(i,neext[i]), m[neext[i]][j+cota[neext[i]]-cota[i]]);
            }
            else
            {
                m[neext[i]][j]=min(m[i][j]+dist(i,neext[i]),m[neext[i]][j]);
                if(j+cota[i]-cota[neext[i]]<=s) m[neext[i]][j+cota[i]-cota[neext[i]]]=min(m[i][j]+1,m[neext[i]][j+cota[i]-cota[neext[i]]]);
            }
    }
    cout<<l_traseu<<'\n';
    int t_min=inf;
    for(j=0; j<=s; ++j) t_min=min(t_min,m[i][j]);
    cout<<t_min;
    //for(i=1;i<=n;++i) cout<<neext[i]<<' ';
    return 0;
}
