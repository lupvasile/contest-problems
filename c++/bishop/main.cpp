#include <iostream>

using namespace std;

#define TESTARE 1


#if TESTARE
#define cin f
#include <fstream>
ifstream f("bishop.in");
#endif // TESTARE

#define nmax 15

int n,m,k,i,nr_d;
long long nr_sol;
bool ds[2*nmax];

void bback(int d,int rem)
    {
    int i,j;
    if(n-1-d<rem-1 || m+n-1-(k-rem)<rem) return;
    for(i=1; i<=n && i-d<=m; ++i)
    if(i-d>=1) if(ds[i+i-d]==0)
            {
            ds[i+i-d]=1;
            if(rem>1)for(j=d+1; j<=n-1; ++j) bback(j,rem-1);
            else ++nr_sol;
            ds[i+i-d]=0;
            }
    }

int main()
    {
    while(1)
        {
        cin>>n>>m>>k;
        if(n==m && m==k && k==-1) return 0;
        nr_d=n+m-1;
        nr_sol=0;
        for(i=1-m;i<=n-1;++i)
            bback(i,k);
        cout<<nr_sol<<'\n';
        }
    return 0;
    }
