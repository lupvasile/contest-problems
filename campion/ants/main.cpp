#include <iostream>
//#include <fstream>
#include <cstdio>
using namespace std;

//ifstream f("ants.in");
//ofstream g("ants.out");

//#define cout g

int n,st(~(1<<31)),dr;
struct
{
    int dist,boabe;
} v[100010];
bool verifica(int greieri)
{
    int t=0,c,vit;
    c=v[1].boabe;
    for(int i=1; i<n; ++i)
    {
        vit=v[i+1].boabe;
        if(c>=greieri)
        {
            if(c-greieri-(v[i+1].dist-v[i].dist)>0)
                vit+=c-greieri-(v[i+1].dist-v[i].dist);
        }
        else vit=vit+c-greieri-(v[i+1].dist-v[i].dist);
        c=vit;
    }
    if(vit-greieri>=0) return true;
    else return false;

}
int caut(int st,int dr)
{
    if(st>dr) return dr;
    int m((st+dr)/2);
    if(verifica(m)) return caut(m+1,dr);
    else return caut(st,m-1);
}
int main()
{
    freopen("ants.in","r",stdin);
    freopen("ants.out","w",stdout);
    //f>>n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        //f>>v[i].dist>>v[i].boabe;
        scanf("%d %d",&v[i].dist,&v[i].boabe);
        st=min(st,v[i].boabe);
        dr=max(dr,v[i].boabe);
    }
    //cout<<caut(st,dr);
    printf("%d",caut(st,dr));
    return 0;
}
