#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("emptri.in");
ofstream fout("emptri.out");
/// ////////////////////////////////

#define nmax 1000010

int v[nmax],n;
long long res;

int main()
{
    int i,j;
    fin>>n;

    for(i=1;i<=n;++i) v[i]=i;

    for(i=2;i<=n;++i)
        {
        if(v[i]==i)
            for(j=i;j<=n;j+=i)
                  v[j]=v[j]/i*(i-1);
        res+=v[i];
        }
    res+=1;
    res<<=1;
    res-=1;
    cout<<res;
    return 0;
}
