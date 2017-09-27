#include <bits/stdc++.h>

using namespace std;

ifstream f("cerc3.in");
ofstream g("cerc3.out");

#define nmax 2010
#define cout g
struct
    {
    int x,y,r;
    double l,ls;
    } cerc[nmax];
int pts[nmax];//punctele sortate dupa panta si dupa partea stanga a cercului
int n,i,nrd,lim,q,qmax,nrdm;

bool cmp(int a,int b)
    {
    if(cerc[a].y*cerc[b].x==cerc[a].x*cerc[b].y) return cerc[a].l<cerc[b].l;
    return cerc[a].y*cerc[b].x<cerc[a].x*cerc[b].y;
    }

int main()
    {
    f>>n;
    for(i=1; i<=n; ++i)
        {
        f>>cerc[i].x>>cerc[i].y>>cerc[i].r;
        cerc[i].l=sqrt(cerc[i].x*cerc[i].x+cerc[i].y*cerc[i].y)+cerc[i].r;
        cerc[i].ls=sqrt(cerc[i].x*cerc[i].x+cerc[i].y*cerc[i].y)-cerc[i].r;
        pts[i]=i;
        }
    sort(pts+1,pts+n+1,cmp);
    for(i=1; i<=n; ++i)
        {
        if(cerc[pts[i]].y*cerc[pts[i-1]].x!=cerc[pts[i]].x*cerc[pts[i-1]].y || i==1)//dreapta noud
            {
            ++nrd;
            lim=cerc[pts[i]].l;
            q=1;
            if(q>qmax)
                {
                qmax=q;
                nrdm=1;
                }
            else if(q==qmax) ++nrdm;
            }
        if(lim<cerc[pts[i]].ls)
            {
            ++q;
            lim=cerc[pts[i]].l;
            if(q>qmax)
                {
                qmax=q;
                nrdm=1;
                }
            else if(q==qmax) ++nrdm;
            }
        }
    cout<<nrd<<' '<<qmax<<' '<<nrdm;
    return 0;
    }
