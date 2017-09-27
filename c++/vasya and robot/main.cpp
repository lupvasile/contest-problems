#include <iostream>

using namespace std;
long long int l,r,n,qr,ql,i,w[100001],k,minn,curent;
int main()
{
    minn=9223372036854775806;
    cin>>n>>l>>r>>ql>>qr;
    for(i=1; i<=n; i++)
    {
        cin>>w[i];
        w[i]+=w[i-1];
    }

    for(k=0; k<=n; k++)
    {
        curent=w[k]*l+(w[n]-w[k])*r;
        if(2*k<n) curent=curent+(n-2*k-1)*qr;
        else if(2*k>n) curent=curent+(n-2*(n-k)-1)*ql;
        if (curent<minn)minn=curent;
    }
    cout<<minn;
    return 0;
}
