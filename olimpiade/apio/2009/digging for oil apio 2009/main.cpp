#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("OIL/large/large-10.in");
//ofstream g("");

//#define cout g
#define nmax 1520

long long A[nmax][nmax], B[nmax][nmax], BNV[nmax][nmax], BNE[nmax][nmax], BSV[nmax][nmax], BSE[nmax][nmax], BX[nmax], BY[nmax];
long long patrat[nmax][nmax];
long long n,m,k,rez,s;
long long i,j,bst;
deque <pair<long long,long long> > d_x, d_y;

inline long long maxx(long long a,long long b,long long c)
{
    return max(a,max(b,c));
}
int main()
{
    f>>n>>m>>k;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            f>>A[i][j];
            B[i][j]=A[i][j]+B[i][j-1]+B[i-1][j]-B[i-1][j-1];
            if(i>=k && j>=k) patrat[i][j]=B[i][j]-B[i-k][j]-B[i][j-k]+B[i-k][j-k];
        }

    //faci BNV
    for(i=k; i<=n; ++i)
        for(j=k; j<=m; ++j)
        {
            BNV[i][j]=patrat[i][j];
            BNV[i][j]=maxx(BNV[i][j],BNV[i-1][j],BNV[i][j-1]);
        }

    //faci BNE
    for(i=k; i<=n; ++i)
        for(j=m-k+1; j>=1; --j)
        {
            BNE[i][j]=patrat[i][j+k-1];
            BNE[i][j]=maxx(BNE[i][j],BNE[i][j+1],BNE[i-1][j]);
        }

    //faci BSV
    for(i=n-k+1; i>=1; --i)
        for(j=k; j<=m; ++j)
        {
            BSV[i][j]=patrat[i+k-1][j];
            BSV[i][j]=maxx(BSV[i][j],BSV[i+1][j],BSV[i][j-1]);
        }

    //faci BSE
    for(i=n-k+1; i>=1; --i)
        for(j=m-k+1; j>=1; --j)
        {
            BSE[i][j]=patrat[i+k-1][j+k-1];
            BSE[i][j]=maxx(BSE[i][j],BSE[i+1][j],BSE[i][j+1]);
        }

    //faci BX
    for (i=k; i<=n; ++i)
    {
        for(j=k; j<=m; ++j)
        {
            while (!d_x.empty() && patrat[i][j]>=patrat[d_x.back().first][d_x.back().second]) d_x.pop_back();
            d_x.push_back(make_pair(i,j));
        }
        if(i-d_x.front().first>=k) d_x.pop_front();
        BX[i]=patrat[d_x.back().first][d_x.back().second];
    }

    //faci BY
    for(j=k; j<=m; ++j)
    {
        for(i=k; i<=n; ++i)
        {
            while (!d_y.empty() && patrat[i][j]>=patrat[d_y.back().first][d_y.back().second]) d_y.pop_back();
            d_y.push_back(make_pair(i,j));
        }
        if(j-d_y.front().second>=k) d_x.pop_front();
        BY[j]=max(BY[j],patrat[d_y.back().first][d_y.back().second]);
    }

    //doua linii orizontale

    for(i=k; i<=n-2*k; ++i)
    {
        bst=0;
        for(j=i+k; j<=n-k; ++j)
        {
            bst=max(bst,BX[j]);
            s=BNV[i][m]+bst+BSV[j+1][m];
            rez=max(rez,s);
        }
    }

    //doua linii verticale

    for(i=k; i<=m-2*k; ++i)
    {
        bst=0;
        for(j=i+k; j<=m-k; ++j)
        {
            bst=max(bst,BY[j]);
            s=BSV[1][i]+bst+BSE[1][j+1];
            rez=max(rez,s);
        }
    }

    //una orizontala(i) si una verticala(j)

    for(i=k;i<=n-k;++i)
    for(j=k;j<=m-k;++j)
    {
        rez=max(rez,BNV[i][m]+BSV[i+1][j]+BSE[i+1][j+1]);
        rez=max(rez,BNV[i][j]+BNE[i][j+1]+BSE[i+1][1]);
        rez=max(rez,BSV[1][j]+BNE[i][j+1]+BSE[i+1][j+1]);
        rez=max(rez,BNV[i][j]+BSV[i+1][j]+BSE[1][j+1]);
    }
    cout<<rez;
    return 0;
}
