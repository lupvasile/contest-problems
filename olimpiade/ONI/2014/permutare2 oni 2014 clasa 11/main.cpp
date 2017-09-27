#include <bits/stdc++.h>

using namespace std;

ifstream f("permutare2.in");
ofstream g("permutare2.out");

#define cout g

long long m,n,x,right_nr,right_sum,left_nr,left_sum,i,mid,r_nr,l_nr;
int v[100010];
long long sol;

int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>x;
    ++v[0];
    for(i=1;i<m;++i)
    {
        f>>x;
        ++v[x];
    }

    mid=n/2;
    r_nr=n/2;
    l_nr=n/2-(n%2==0);

    for(i=mid;i>=0;--i)
    {
        right_sum+=right_nr;
        right_nr+=v[i];
    }
    right_nr-=v[0];

    for(i=mid+1;i<n;++i)
    {
        left_sum+=left_nr;
        left_nr+=v[i];
    }
    left_sum+=left_nr;

    sol=right_sum+left_sum;

    for(i=1;i<n;++i)
    {
        ++mid;
        if(mid==n) mid=0;

        right_sum = right_sum - right_nr + v[mid]*r_nr;
        right_nr = right_nr - v[i] + v[mid];

        left_nr = left_nr - v[mid] + v[i-1];
        left_sum = left_sum - v[mid]*l_nr + left_nr;

        sol=min(sol,1ll*(left_sum+right_sum));
    }
    cout<<sol;
    return 0;
}
