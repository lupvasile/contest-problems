#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("cladiri.in");
ofstream fout("cladiri.out");
/// ////////////////////////////////

void read();

#define nmax 1010

int a[nmax][nmax],h[nmax][nmax],lleft[nmax],rright[nmax],up[nmax],down[nmax];
int maxx,n,lin,col,m;

struct
{
    int nr;
    pair<int,int> st[nmax];///first ii inaltimea, second ii pozitia

    void RIP()
    {
        nr=0;
    }

    void baga(pair<int,int> p)
    {
        while(p.first<st[nr].first)
        {
            maxx=max(maxx,st[nr].first*(p.second-st[nr-1].second-1));
            --nr;
        }
        st[++nr]=p;
    }
} stiva;

void make_up()
{
    int i,j;
    maxx=0;
    for(i=1; i<=n; ++i)
    {
        stiva.RIP();
        stiva.baga({0,0});

        for(j=1; j<=m; ++j)
        {
            if(a[i][j]) h[i][j]=0;
            else h[i][j]=1+h[i-1][j];
            stiva.baga({h[i][j],j});
        }
        stiva.baga({0,m+1});
        up[i]=maxx;
    }
}


void make_down()
{
    int i,j;
    maxx=0;
    for(i=n; i>=1; --i)
    {
        stiva.RIP();
        stiva.baga({0,0});

        for(j=1; j<=m; ++j)
        {
            if(a[i][j]) h[i][j]=0;
            else h[i][j]=1+h[i+1][j];
            stiva.baga({h[i][j],j});
        }
        stiva.baga({0,m+1});
        down[i]=maxx;
    }
}


void make_left()
{
    int i,j;
    maxx=0;

    for(j=1; j<=m; ++j)
    {
        stiva.RIP();
        stiva.baga({0,0});
        for(i=1; i<=n; ++i)
        {
            if(a[i][j]) h[i][j]=0;
            else h[i][j]=1+h[i][j-1];
            stiva.baga({h[i][j],i});
        }
        stiva.baga({0,n+1});
        lleft[j]=maxx;
    }
}


void make_right()
{
    int i,j;
    maxx=0;
    for(j=m; j>=1; --j)
    {
        stiva.RIP();
        stiva.baga({0,0});

        for(i=1; i<=n; ++i)
        {
            if(a[i][j]) h[i][j]=0;
            else h[i][j]=1+h[i][j+1];
            stiva.baga({h[i][j],i});
        }
        stiva.baga({0,n+1});
        rright[j]=maxx;
    }
}

int main()
{
    int i,j,l;
    read();

    make_down();
    make_left();
    make_right();
    make_up();

    maxx=0;

    for(i=1; i<=n; ++i)
    {
        l=0;
        for(j=1; j<=m; ++j)
        {
            if(h[i][j]<lin) l=j;
            else if(j-l>=col)
            {
                maxx=max(maxx,up[i-lin]);
                maxx=max(maxx,down[i+1]);
                maxx=max(maxx,lleft[j-col]);
                maxx=max(maxx,rright[j+1]);
            }

        }
    }
    cout<<maxx;
    return 0;
}

void read()
{
    int i,j;
    fin>>n>>m>>col>>lin;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>a[i][j];
}
