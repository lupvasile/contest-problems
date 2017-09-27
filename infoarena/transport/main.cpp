#include <iostream>
#include <fstream>

using namespace std;

ifstream f("transport.in");
ofstream g("transport.out");

#define cout g

int n,k,v[16000];

bool verifica(int volum)
{
    int s=0,i=0,nrt=0;
    for(i=0; i<n; ++i)
    {
        if (s+v[i]>volum)
        {
            ++nrt;
            s=0;
            --i;
        }
        else s+=v[i];
    }
    if(s>0) ++nrt;
    return nrt<=k;

}

int caut(int st, int dr)
{
    if(st>dr) return st;
    int m;
    m=(st+dr)/2;
    if(verifica(m)) return caut(st,m-1);
    else return caut(m+1,dr);
}
int main ()
{
    int st(0),dr(0),m,i;

    f>>n>>k;
    for(i=0; i<n; ++i)
    {
        f>>v[i];
        st=max(st,v[i]);
        dr+=v[i];
    }
    cout<<caut(st,dr);
    //cout<<'\n'<<verifica(7);
    return 0;
}
