#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("borcane.in");
ofstream fout("borcane.out");
/// ////////////////////////////////

void read();

#define nmax 102

struct borcan
{
    int id,b;
    bool operator < (const borcan &other) const
    {
        if(b==other.b) return id>other.id;
        return b>other.b;
    }
} b[nmax];

int n;

int main()
{
    int i;
    read();

    for(i=n; i>2; --i)
        for(; b[i].b; --b[i].b,--b[i-1].b,b[1].b+=2) cout<<b[i].id<<' '<<b[i-1].id<<' '<<b[1].id<<'\n';

    while(b[2].b)
    {
        if(b[3].b)
        {
            cout<<b[3].id<<' '<<b[2].id<<' '<<b[1].id<<'\n';
            --b[3].b,--b[2].b,b[1].b+=2;
        }
        else
        {
            cout<<b[1].id<<' '<<b[2].id<<' '<<b[3].id<<'\n';
            --b[1].b,--b[2].b,b[3].b+=2;
        }
    }

    swap(b[2],b[3]);

    if(b[2].b==1)
    {
        cout<<b[2].id<<' '<<b[1].id<<' '<<b[3].id<<'\n';
        --b[2].b,b[3].b+=2;
        swap(b[2],b[3]);
    }

    if(b[2].b==2)
    {
        cout<<b[1].id<<' '<<b[2].id<<' '<<b[3].id<<'\n';
        cout<<b[1].id<<' '<<b[3].id<<' '<<b[4].id<<'\n';
        cout<<b[4].id<<' '<<b[3].id<<' '<<b[1].id<<'\n';
        cout<<b[4].id<<' '<<b[2].id<<' '<<b[1].id<<'\n';
    }

    return 0;
}

void read()
{
    int i;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>b[i].b;
        b[i].id=i;
    }

    sort(b+1,b+n+1);
}
