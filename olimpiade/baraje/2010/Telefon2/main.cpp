#include <iostream>
#include <fstream>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("telefon2.in");
ofstream fout("telefon2.out");
/// ////////////////////////////////

#define nmax 100010

int v[nmax],vo[nmax],n;
bool in[nmax],viz[nmax];

int main()
{
    int i,last=0,first,nod,nr=0;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>v[i];
        vo[i]=v[i];
        in[v[i]]=true;
    }

    for(i=1;i<=n;++i)
        if(!in[i])
    {
        viz[i]=true;

        for(nod=i; viz[v[nod]]==false; nod=v[nod],viz[nod]=true);

        if(last==0) last=nod;
        v[nod]=first;
        first=i;
    }

    for(i=1;i<=n;++i)
        if(!viz[i])
    {
        viz[i]=true;

        for(nod=i; viz[v[nod]]==false; nod=v[nod],viz[nod]=true);

        if(last==0) last=nod;
        v[nod]=first;
        first=i;
    }

    v[last]=first;

    for(i=1;i<=n;++i) if(v[i]!=vo[i]) ++nr;
    cout<<nr<<'\n';
    for(i=1;i<=n;++i) if(v[i]!=vo[i]) cout<<i<<' '<<v[i]<<'\n';
    return 0;
}
