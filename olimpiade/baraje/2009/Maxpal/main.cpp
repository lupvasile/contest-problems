#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("maxpal.in");
ofstream fout("maxpal.out");
/// ////////////////////////////////

#define mod 666013
#define nmax 2002

int v[nmax],n;
int din[3][nmax],nr[3][nmax];

int main()
{
    int i,l,j,lc,lp,lpp;
    fin>>n;

    for(i=1; i<=n; ++i)  fin>>v[i];

    for(i=1; i<=n; ++i)
    {
        din[0][i]=1;
        nr[0][i]=1;
    }
    for(i=1; i<n; ++i)
    {
        if(v[i]==v[i+1])
        {
            din[1][i]=2;
            nr[1][i]=1;
        }
        else
        {
            din[1][i]=1;
            nr[1][i]=2;
        }
    }

    lp=0;
    lc=1;

    for(l=3; l<=n; ++l){
        lpp=lp;
        lp=lc;
        lc=lp+1;
        if(lc>2) lc=0;

        for(i=1;i<=n;++i) din[lc][i]=nr[lc][i]=0;

        for(i=1; i+l-1<=n; ++i)
        {
            j=i+l-1;
            if(v[i]==v[j])
            {
                din[lc][i]=2+din[lpp][i+1];
                nr[lc][i]=nr[lpp][i+1] + (din[lp][i+1]==din[lc][i] ? nr[lp][i+1]:0) + (din[lp][i]==din[lc][i] ? nr[lp][i]:0);

            }
            else
            {
                if(din[lp][i+1]==din[lp][i])
                {
                    din[lc][i]=din[lp][i+1];
                    nr[lc][i]=nr[lp][i+1]+nr[lp][i]-(din[lpp][i+1]==din[lc][i] ? nr[lpp][i+1]:0);
                }
                else if(din[lp][i+1]>din[lp][i])
                {
                    din[lc][i]=din[lp][i+1];
                    nr[lc][i]=nr[lp][i+1];
                }
                else
                {
                    din[lc][i]=din[lp][i];
                    nr[lc][i]=nr[lp][i];
                }
            }
            nr[lc][i]%=mod;
        }
    }
    cout<<din[lc][1]<<' '<<(nr[lc][1]+mod)%mod;

    return 0;
}
