#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define cout g
#define nmax 2001

ifstream f("parc.in");
ofstream g("parc.out");

int xp,yp,xg,yg,xpr,ypr,m,n,startx,finx,starty,finy,cx,cy,dist_x,dist_y,nrsol,kx,ky;
int i,a,b,j;
int sx[nmax],sy[nmax],spax[nmax],spay[nmax];
bool simx,simy;
pair<int,int> pv[nmax],po[nmax];
long double sol;

void stabilizeaza();
void read();
int main()
{
    read();
    sort(pv+1,pv+m+1);
    sort(po+1,po+n+1);
    for(i=1;i<=m;++i) sx[i]=sx[i-1]+pv[i].second-pv[i].first;
    for(i=1;i<=n;++i) sy[i]=sy[i-1]+po[i].second-po[i].first;

    for(startx=1;pv[startx].first<xg;++startx);
    for(finx=m;pv[finx].second>xpr;--finx);
    for(starty=1;po[starty].first<yg;++starty);
    for(finy=n;po[finy].second>ypr;--finy);

    dist_x=sx[finx]-sx[startx-1];
    dist_y=sy[finy]-sy[starty-1];

    cx=xpr-xg-dist_x;
    cy=ypr-yg-dist_y;

    sol=dist_x+dist_y+sqrtf(double(cx*cx+cy*cy));
    cout<<fixed<<sol<<'\n';

    nrsol=1;
    spax[++kx]=pv[startx].first-xg;
    for(i=startx+1;i<=finx;++i)
    {
        ++kx;
        spax[kx]=spax[kx-1]+pv[i].first-pv[i-1].second;
    }
    spay[++ky]=po[starty].first-yg;
    for(i=starty+1;i<=finy;++i)
    {
        ++ky;
        spay[ky]=spay[ky-1]+po[i].first-po[i-1].second;
    }

    for(i=1,j=1;i<=kx && j<=ky;)
    {
        if(spax[i]*cy==spay[j]*cx)
        {
            ++i;
            ++j;
            nrsol<<=1;
        }
        else if(spax[i]*cy>spay[j]*cx)
        {
            ++j;
        }
        else ++i;
    }
    cout<<nrsol;
    return 0;
}

void read()
{
    f>>xp>>yp;
    f>>xg>>yg>>xpr>>ypr;
    stabilizeaza();

    f>>m;
    for(i=1;i<=m;++i)
    {
        f>>a>>b;
        if(simx)
        {
            if(a<b) swap(a,b);
            pv[i]=make_pair(xp-a,xp-b);
        }
        else
        {
            if(a>b) swap(a,b);
            pv[i]=make_pair(a,b);
        }
    }

    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>a>>b;
        if(simy)
        {
            if(a<b) swap(a,b);
            po[i]=make_pair(yp-a,yp-b);
        }
        else
        {
            if(a>b) swap(a,b);
            po[i]=make_pair(a,b);
        }
    }

}

void stabilizeaza()//pt simtrice, sa ma duc numa din stanga jos in dreapta sus
{
    if(xpr<xg)
    {
        simx=true;
        xg=xp-xg;
        xpr=xp-xpr;
    }
    if(ypr<yg)
    {
        simy=true;
        yg=yp-yg;
        ypr=yp-ypr;
    }
}
