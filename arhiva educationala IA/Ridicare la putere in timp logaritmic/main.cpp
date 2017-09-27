#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("lgput.in");
ofstream fout("lgput.out");
/// ////////////////////////

#define mod 1999999973
#define lint long long

lint power(lint n,lint p)
{
    lint res=1;
    for(;p;p>>=1)
    {
        if(p&1) res=res*n%mod;
        n=n*n%mod;
    }
    return res;
}

int main()
{
    lint n,p;
    fin>>n>>p;
    cout<<power(n,p);
    return 0;
}
