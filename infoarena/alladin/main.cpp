#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("aladdin.in");
ofstream g("aladdin.out");

#define cout g
#define nmax 1001
#define foor(i,a,b) for(__typeof(a) i=a;i!=b;++i)
int i,j,n,m,o,p;
int a[nmax][nmax];
struct pepepe
    {
    int semn,li,co;
    };
struct
    {
    int coef;
    vector<pepepe> lst;
    } v[nmax][nmax];

void fa_ec(int o,int p)
{
    foor(it,v[o][p].lst.begin(),v[o][p].lst.end())
                {
                foor(it2,v[i][j].lst.begin(),v[i][j].lst.end())
                if(it->li==it2->li && it->co==it2->co)
                    {
                    it2->semn=it2->semn-it->semn;
                    goto vasi1;
                    }
                v[i][j].lst.push_back( {-it->semn,it->li,it->co});

vasi1:
                ;
                }
}

int main()
    {
    f>>n>>m;
    /*for(i=1; i<n; ++i)
        for(j=1; j<m; ++j) f>>a[i][j];
*/
    for(i=1; i<=n; ++i) v[i][1].lst.push_back( {1,i,1});
    for(j=2; j<=m; ++j) v[1][j].lst.push_back( {1,1,j});

    for(i=2; i<=n; ++i)
        for(j=2; j<=m; ++j)
            {
            v[i][j].coef=a[i-1][j-1]-v[i][j-1].coef-v[i-1][j].coef-v[i-1][j-1].coef;
            fa_ec(i-1,j-1);
            fa_ec(i,j-1);
            fa_ec(i-1,j);

            }

    /*for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            cout<<i<<' '<<j<<"\t\t\t\t"<<v[i][j].coef<<'\n';
            foor(it,v[i][j].lst.begin(),v[i][j].lst.end()) if(it->semn!=0)cout<<"\t"<<it->semn<<' '<<it->li<<' '<<it->co<<'\n';
            }*/
    cout<<-1;
    return 0;
    }
